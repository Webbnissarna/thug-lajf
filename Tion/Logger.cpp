#include "Logger.h"
#include <iostream>

void Logger::error(std::string message) {
	std::cout << "\033[" << RED << "m" << message << std::endl;
}

void Logger::success(std::string message) {
	std::cout << "\033[" << GREEN << "m" << message << std::endl;
}

void Logger::print(std::string message) {
	std::cout << "\033[" << DEFAULT << "m" << message << std::endl;
}