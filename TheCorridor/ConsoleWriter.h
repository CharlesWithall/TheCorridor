#pragma once

#include <string>
#include <iostream>

class ServiceLocator;

class ConsoleWriter
{
	friend class ServiceLocator;
public:
	~ConsoleWriter(void);
	void WriteStringToConsole(std::string aStringToDisplay);
private:
	ConsoleWriter();
};

