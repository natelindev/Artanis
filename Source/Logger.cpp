#include "Logger.h"
#include "config.h"
#include "common.h"
#include <fstream>

void Logger::logEvent(int level,const char* fmt, ...)
{
	if (level < Config::Log::minLoglevel){return;} //Log level control
	
	va_list args;
	va_start(args, fmt);
	char buff[256];
	vsnprintf_s(buff, 256, fmt, args);
	va_end(args);

	if (Config::Log::LogDisplay)
	{
		BWAPI::Broodwar->printf("[%s] ", levels[level]);
		BWAPI::Broodwar->printf("%s\n",buff);
	}
	else
	{
		std::ofstream logStream;
		logStream.open(Config::Log::logFilePath.c_str(), std::ofstream::app);
		logStream << buff;
		logStream.flush();
		logStream.close();
	}
	
}