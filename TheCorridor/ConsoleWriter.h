#pragma once

#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>

class ConsoleWriter
{
	friend class ServiceLocator;
public:
	~ConsoleWriter(void);
	void WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument = std::string());
private:
	ConsoleWriter();
};

