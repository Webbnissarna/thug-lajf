#pragma once

#include <string>

class Logger {
public:
	static void error(std::string message);
	static void success(std::string message);
	static void print(std::string message);
private:
	enum COLOR {
		RED = 31,
		GREEN = 32,
		DEFAULT = 39
	};
};