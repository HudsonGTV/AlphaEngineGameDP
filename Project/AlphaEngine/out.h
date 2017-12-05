#ifndef OUT_H
#define OUT_H

#include <string>
#include <time.h>

#include "AEEngine.h"

namespace Console {

	namespace out {

		void print(std::string str, std::string tag = "Info");
		void println(std::string str, std::string tag = "Info");

	}

}

#endif
