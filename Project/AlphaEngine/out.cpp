#include "out.h"

std::string currentDateTime() {

	time_t now = time(0);
	struct tm tstruct;
	char buf[80];

	localtime_s(&tstruct, &now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;

}

void Console::out::print(std::string str, std::string tag) {

	std::string finalStr = currentDateTime() + " [" + tag + "] " + str;

	AESysPrintf(finalStr.c_str());

}

void Console::out::println(std::string str, std::string tag) {

	bool isRWarning = false;

	if(tag == "RWarning") {
		isRWarning = true;
		tag = "Warning";
	}

	std::string finalStr = currentDateTime() + " [" + tag + "] " + str + "\n";

	AESysPrintf(finalStr.c_str());

}
