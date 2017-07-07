#pragma once

#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class ConsoleWriter
{
	friend class ServiceLocator;
public:
	~ConsoleWriter(void);
	void WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument = std::string());
private:
	bool HasHitTriggerCharacter(const char& aCharacterInTheString, const char& aTriggerCharacter);
	void TryToInsertArgument(const char& aCharacterInTheString, std::string& anOutputString, const std::string& anArgument);
	void TryToInsertLineBreak(const char& aCharacterInTheString, std::string& anOutputString);
	ConsoleWriter();

	HANDLE myConsoleHandle;
};

