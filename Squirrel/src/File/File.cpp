#include "File.h"

namespace Squirrel {
	namespace File {

		/* 
		* Load a file
		* loadFile(const char* filedir = system file to load, std::fstream *result = fstream to return file to)
		*/
		void loadFile(const char* filedir, std::fstream *result) {
			std::fstream file;
			file.open(filedir);
			if (!file.is_open()) {
				std::cout << "[!!!] Failed loading file\n";
				result = NULL;
			}
			result = &file;
			file.close();
		}

		/*
		* Load a file and return it as a string
		* loadFile(const char* filedir = system file to load)
		*/
		const char* loadFile(const char* filedir) {
			std::fstream file;
			Squirrel::File::loadFile(filedir, &file);

			std::string str;
			std::string fstr;
			int i = 0;
			while (std::getline(file, str)) {
				fstr += str;
			}
			return fstr.c_str();
		}

		/*
		* Remove a file
		* removeFile(const char* filedir = system file to remove)
		*/
		void removeFile(const char* filedir) {
			if (remove(filedir) != 0)
				perror("Error removing file\n");
		}

		/*
		* Check if a file exist
		* returns if the exists as a bool
		* checkFile(const char* filedir = system file to check, bool createFile = if we should create a file if the file does not exist)
		*/
		bool checkFile(const char* filedir, bool createFile) {
			std::fstream config(filedir);
			if (!config.is_open() && createFile) {
				std::ofstream{filedir};
			}
			bool is = config.is_open();
			config.close();
			return is;
		}

		/*
		* Check if a file exist
		* returns if the exists as a bool
		* checkFile(const char* filedir = system file to check)
		*/
		bool checkFile(const char* filedir) {
			std::fstream config(filedir);
			bool is = config.is_open();
			config.close();
			return is;
		}

		/*
		* Write text to a file, create the file if it does not exist
		* use 'n' to to seperate lines
		* writeFile(const char* filedir = system file to write to, const char* str = text to write)
		*/
		void writeFile(const char* filedir, const char* str) {
			std::fstream config(filedir);
			if (!config.is_open()) {
				std::ofstream{ filedir };
			}
			config << str;
			config.close();
		}
	}
}