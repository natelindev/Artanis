#pragma once
#include <string>

class Logger
{
public:
	enum LogLevel
	{
		LOG_INFO, LOG_DEBUG, LOG_WARN, LOG_ERROR, LOG_NONE
	};

	char *levels[4] = { "INFO", "DBUG", "WARN", "ERRO"};

	void logEvent(int level,const char* fmt, ...);
	
};

