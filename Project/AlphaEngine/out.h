#ifndef OUT_H
#define OUT_H

#include <string>
#include <time.h>

#include "AEEngine.h"
#include "TextStyle.h"

namespace Console {

	enum Filters {
		Info,
		Debug,
		Warning,
		Error,
		Misc
	};

	std::string value(std::string str);

	namespace out {

		bool filterStatus(Filters filterID);
		void toggleFilter(Filters filterID);
		void print(std::string str, std::string tag = "Info");
		void println(std::string str, std::string tag = "Info");

	}

}

#endif
