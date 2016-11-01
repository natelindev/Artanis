#pragma once

#include "BWAPI.h"
#include "common.h"
#include <cassert>

namespace Config
{
	namespace BotInfo
	{
		extern std::string BotName;
		extern std::string Author;
	}

	namespace Logger
	{
		extern bool useLogger;
		extern bool LogDisplay;
		extern enum LogLevel minLoglevel;
		extern std::string logFilePath;
		
	}

	namespace Module
	{
		extern enum Executors Hierarch;//Hierarch would lead all the protoss for now


	}
}