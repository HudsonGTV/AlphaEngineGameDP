#include "out.h"

namespace FilterValues {
	static bool showInfoMsg = true;
	static bool showDebugMsg = true;
	static bool showWarningMsg = true;
	static bool showErrorMsg = true;
	static bool showMiscMsg = true;
}

std::string currentDateTime() {

	time_t now = time(0);
	struct tm tstruct;
	char buf[80];

	localtime_s(&tstruct, &now);

	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

	std::string tsColor = TSC_TIMESTAMP;

	return tsColor + buf + TSC_NORMAL;

}

std::string tagStyle(std::string tag) {

	std::string whiteColor = TSC_WHITE;

	if(tag == "Info")							return whiteColor + " [" + TSC_INFO		+ "Info"	+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;
	if(tag == "Debug")							return whiteColor + " [" + TSC_DEBUG	+ "Debug"	+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;
	if(tag == "Warning" || tag == "RWarning")	return whiteColor + " [" + TSC_WARNING	+ "Warning"	+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;
	if(tag == "Error")							return whiteColor + " [" + TSC_ERROR	+ "Error"	+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;
	if(tag == "Filter")							return whiteColor + " [" + TSC_MAGENTA	+ "Filter"	+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;
	else										return whiteColor + " [" + TSC_WHITE	+ tag		+ TSC_NORMAL + TSC_WHITE + "] " + TSC_NORMAL;

}

bool shouldPrintMsg(std::string tag) {

	if(tag == "Filter") return true;
	if(!FilterValues::showInfoMsg && tag == "Info") return false;
	if(!FilterValues::showDebugMsg && tag == "Debug") return false;
	if(!FilterValues::showWarningMsg && (tag == "Warning" || tag == "RWarning")) return false;
	if(!FilterValues::showErrorMsg && tag == "Error") return false;
	if(!FilterValues::showMiscMsg && tag != "Info" && tag != "Debug" && tag != "Warning" && tag != "RWarning" && tag != "Error") return false;

	return true;

}

std::string Console::value(std::string str) {
	return TSC_VALUE + str + TSC_NORMAL + TSC_WHITE;
}

void Console::out::toggleFilter(Filters filterID) {
	switch(filterID) {
		case Filters::Info:
			FilterValues::showInfoMsg = !FilterValues::showInfoMsg;
			println(std::string("Console::Filters::Info = " + Console::value(std::to_string(FilterValues::showInfoMsg))), "Filter");
			break;
		case Filters::Debug:
			FilterValues::showDebugMsg = !FilterValues::showDebugMsg;
			println(std::string("Console::Filters::Debug = " + Console::value(std::to_string(FilterValues::showDebugMsg))), "Filter");
			break;
		case Filters::Warning:
			FilterValues::showWarningMsg = !FilterValues::showWarningMsg;
			println(std::string("Console::Filters::Warning = " + Console::value(std::to_string(FilterValues::showWarningMsg))), "Filter");
			break;
		case Filters::Error:
			FilterValues::showErrorMsg = !FilterValues::showErrorMsg;
			println(std::string("Console::Filters::Error = " + Console::value(std::to_string(FilterValues::showErrorMsg))), "Filter");
			break;
		case Filters::Misc:
			FilterValues::showMiscMsg = !FilterValues::showMiscMsg;
			println(std::string("Console::Filters::Misc = " + Console::value(std::to_string(FilterValues::showMiscMsg))), "Filter");
			break;
		default:
			break;
	}
}

void Console::out::print(std::string str, std::string tag) {

	if(shouldPrintMsg(tag)) {

		std::string finalStr = currentDateTime() + tagStyle(tag) + TSC_WHITE + str + TSC_NORMAL;

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

		std::string finalStr = currentDateTime() + tagStyle(tag) + TSC_WHITE + str + TSC_NORMAL + "\n";

		AESysPrintf(finalStr.c_str());

	}

}
