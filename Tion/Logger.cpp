#include "Logger.h"
#include <iostream>

void Logger::Error(std::string message) {
	std::cout << "\033[" << RED << "m" << message << std::endl;
}

void Logger::Success(std::string message) {
	std::cout << "\033[" << GREEN << "m" << message << std::endl;
}

void Logger::Print(std::string message) {
	std::cout << "\033[" << DEFAULT << "m" << message << std::endl;
}