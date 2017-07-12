#pragma once

#include <array>
#include <cstdarg>
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

enum CONSOLE_MESSAGE_TYPE // Aligned with console colour codes: https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
{
	COLOUR_INPUT = 7,
	COLOUR_SPECIAL = 10,
	COLOUR_OUTPUT = 11,
	COLOUR_ERROR = 12,
};

class ConsoleWriter
{
	friend class ServiceLocator;
public:
	~ConsoleWriter(void);
	void WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument = std::string(), const CONSOLE_MESSAGE_TYPE aMessageType = COLOUR_OUTPUT);
	void ReportError(const std::string& aStringToDisplay, const std::string& anArgument = std::string()) { WriteStringToConsole(aStringToDisplay, anArgument, COLOUR_ERROR); throw; }
private:
	bool WriteSpecial(const std::string& aStringToDisplay);
	bool HasHitTriggerCharacter(const char& aCharacterInTheString, const char& aTriggerCharacter);
	void TryToInsertArgument(const char& aCharacterInTheString, std::string& anOutputString, const std::string& anArgument);
	void TryToInsertLineBreak(const char& aCharacterInTheString, std::string& anOutputString);
	ConsoleWriter();

	HANDLE myConsoleHandle;
};

