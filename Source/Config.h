#pragma once

#include "BWAPI.h"
#include "common.h"
#include "GameCommander.h"
#include "Logger.h"
#include <cassert>
#ifndef MAXPATHLEN
#define MAXPATHLEN 100
#endif

namespace Config
{
	namespace BotInfo
	{
		extern std::string BotName;
		extern std::string Author;
	}

	namespace Log
	{
		extern bool useLogger;
		extern bool LogDisplay;
		extern Logger::LogLevel minLoglevel;
		extern std::string logFilePath;
		
	}

	namespace Module
	{
		extern GameCommander::Executors defaultExecutor;//Hierarch would lead all the protoss for now
		extern bool UsingGameCommander;
		extern bool UsingWorkerManager;
		extern bool UsingMessageManager;
		

	}
}

std::string get_working_path();