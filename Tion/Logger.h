#pragma once

#include <string>

class Logger {
public:
	static void Error(std::string message);
	static void Success(std::string message);
	static void Print(std::string message);
private:
	enum COLOR {
		RED = 31,
		GREEN = 32,
		DEFAULT = 39
	};
};