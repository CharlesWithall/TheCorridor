#include "stdafx.h"
#include "ConsoleWriter.h"

#define TRIGGER_LINE_BREAK '.'
#define TRIGGER_ARGUMENT '%'

#define COLOR_DEFAULT 7 // Off-white
#define COLOR_CYAN 11

ConsoleWriter::ConsoleWriter(void)
{
	myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}


ConsoleWriter::~ConsoleWriter(void)
{
}

void ConsoleWriter::WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument)
{
	SetConsoleTextAttribute(myConsoleHandle, COLOR_CYAN);
	std::string output;

	bool isInsertingArgument = false;
	bool isInsertingLineBreak = false;

	for(char c : aStringToDisplay)
	{
		if (isInsertingArgument)
			TryToInsertArgument(c, output, anArgument);

		if (isInsertingLineBreak)
			TryToInsertLineBreak(c, output);

		if (!isInsertingArgument && !isInsertingLineBreak)
			output += c;

		isInsertingArgument = HasHitTriggerCharacter(c, TRIGGER_ARGUMENT);
		isInsertingLineBreak = HasHitTriggerCharacter(c, TRIGGER_LINE_BREAK);		
	}

	std::cout << output << std::endl;
	SetConsoleTextAttribute(myConsoleHandle, COLOR_DEFAULT);
}

bool ConsoleWriter::HasHitTriggerCharacter(const char& aCharacterInTheString, const char& aTriggerCharacter)
{
	if (aCharacterInTheString == aTriggerCharacter)
	{
		return true;
	}

	return false;
}

void ConsoleWriter::TryToInsertArgument(const char& aCharacterInTheString, std::string& anOutputString, const std::string& anArgument)
{
	if (aCharacterInTheString == 's')
	{
		anOutputString.pop_back();
		anOutputString += anArgument;
	}
	else
	{
		anOutputString += TRIGGER_ARGUMENT;
	}
}



void ConsoleWriter::TryToInsertLineBreak(const char& aCharacterInTheString, std::string& anOutputString)
{
	if (aCharacterInTheString == ' ')
	{
		std::cout << anOutputString << std::endl;
		anOutputString = std::string();			
	}
	else
	{
		anOutputString += TRIGGER_LINE_BREAK;
	}
}
