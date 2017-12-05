#include "out.h"

namespace FilterValues {
	static bool showInfoMsg = true;
	static bool showDebugMsg = true;
	static bool showWarningMsg = true;
	static bool showErrorMsg = true;
}

std::string currentDateTime() {

	time_t now = time(0);
	struct tm tstruct;
	char buf[80];

	localtime_s(&tstruct, &now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	return buf;

}

bool shouldPrintMsg(std::string tag) {

	if(!FilterValues::showInfoMsg && tag == "Info") return false;
	if(!FilterValues::showDebugMsg && tag == "Debug") return false;
	if(!FilterValues::showWarningMsg && tag == "Warning") return false;
	if(!FilterValues::showErrorMsg && tag == "Error") return false;

	return true;

}

void Console::out::toggleFilter(Filters filterID) {

	switch(filterID) {
		case Filters::Info:
			FilterValues::showInfoMsg = !FilterValues::showInfoMsg;
			println(std::string("Console::Filters::Info = " + std::to_string(FilterValues::showInfoMsg)), "Filter");
			break;
		case Filters::Debug:
			FilterValues::showDebugMsg = !FilterValues::showDebugMsg;
			println(std::string("Console::Filters::Debug = " + std::to_string(FilterValues::showDebugMsg)), "Filter");
			break;
		case Filters::Warning:
			FilterValues::showWarningMsg = !FilterValues::showWarningMsg;
			println(std::string("Console::Filters::Warning = " + std::to_string(FilterValues::showWarningMsg)), "Filter");
			break;
		case Filters::Error:
			FilterValues::showErrorMsg = !FilterValues::showErrorMsg;
			println(std::string("Console::Filters::Error = " + std::to_string(FilterValues::showErrorMsg)), "Filter");
			break;
		default:
			break;
	}

}

void Console::out::print(std::string str, std::string tag) {

	if(shouldPrintMsg(tag)) {

		std::string finalStr = currentDateTime() + " [" + tag + "] " + str;

		AESysPrintf(finalStr.c_str());

	}

}

void Console::out::println(std::string str, std::string tag) {

	if(shouldPrintMsg(tag)) {

		bool isRWarning = false;

		if(tag == "RWarning") {
			isRWarning = true;
			tag = "Warning";
		}

		std::string finalStr = currentDateTime() + " [" + tag + "] " + str + "\n";

		AESysPrintf(finalStr.c_str());

	}

}
