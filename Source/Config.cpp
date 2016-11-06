#pragma once
#include "Config.h"
#include <direct.h>

namespace Config
{
	namespace BotInfo
	{
		std::string BotName = "Artanis";
		std::string Author = "Nathaniel";
	}

	namespace Log
	{
		bool useLogger = true;
		bool LogDisplay = true;
		Logger::LogLevel minLoglevel = Logger::LOG_INFO;
		std::string logFilePath = get_working_path();
		
	}

	namespace Module
	{
		GameCommander::Executors defaultExecutor = GameCommander::Fenix;//Hierarch would lead all the protoss for now
		bool useMessageManager = true;
	}
	
}

std::string get_working_path()
{
	char temp[MAXPATHLEN];
	return (_getcwd(temp, MAXPATHLEN) ? std::string(temp) : std::string(""));
}
