#include "Squirrel.h"

namespace Squirrel {
	namespace Debug {
		void Log(const char* msg) {
			std::cout << msg << "\n";
		}
	}
}