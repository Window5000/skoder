#pragma once
#include <fstream>
#include <iostream>
#include <string>

namespace Squirrel {
	namespace File {
		/*
		* Load a file
		* loadFile(const char* filedir = system file to load, std::fstream *result = fstream to return file to)
		*/
		void loadFile(const char* filedir, std::fstream* result);

		/*
		* Load a file and return it as a string
		* loadFile(const char* filedir = system file to load)
		*/
		const char* loadFile(const char* filedir);

		/*
		* Remove a file
		* removeFile(const char* filedir = system file to remove)
		*/
		void removeFile(const char* filedir);

		/*
		* Check if a file exist
		* returns if the exists as a bool
		* checkFile(const char* filedir = system file to check, bool createFile = if we should create a file if the file does not exist)
		*/
		bool checkFile(const char* filedir, bool createFile);

		/*
		* Check if a file exist
		* returns if the exists as a bool
		* checkFile(const char* filedir = system file to check)
		*/
		bool checkFile(const char* filedir);

		/*
		* Write text to a file, create the file if it does not exist
		* use 'n' to to seperate lines
		* writeFile(const char* filedir = system file to write to, const char* str = text to write)
		*/
		void writeFile(const char* filedir, const char* str);
	}
}