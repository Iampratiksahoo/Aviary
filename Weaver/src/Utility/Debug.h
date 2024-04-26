#pragma once

enum LogType
{
	Log, 
	Warning,
	Error,
	Success
};

class Debug
{
public:
	static void Log(LogType Type, const char* fmt, ...);
	static void Exception(char const* const msg);
	static bool LogEnabled();
private:
	Debug();

	static void set_log_color(LogType Type);
	static void reset_log_color();
};

