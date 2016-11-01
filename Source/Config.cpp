#pragma once
#include "Config.h"
#include <direct.h>
#ifndef MAXPATHLEN
#define MAXPATHLEN 100
#endif

namespace Config
{
	namespace BotInfo
	{
		std::string BotName = "Artanis";
		std::string Author = "Nathaniel";
	}

	namespace Logger
	{
		bool useLogger = true;
		bool LogDisplay = true;
		enum LogLevel minLoglevel = LOG_INFO;
		std::string logFilePath = get_working_path();
		
	}

	namespace Module
	{
		extern enum Executors Hierarch = Fenix;//Hierarch would lead all the protoss for now


	}
	
}

std::string get_working_path()
{
	char temp[MAXPATHLEN];
	return (getcwd(temp, MAXPATHLEN) ? std::string(temp) : std::string(""));
}
