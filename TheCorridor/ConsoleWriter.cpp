#include "stdafx.h"
#include "ConsoleWriter.h"

#define TRIGGER_LINE_BREAK '.'
#define TRIGGER_ARGUMENT '%'
#define TRIGGER_SPECIAL '#'

#define MAX_NUM_SPECIAL_STRINGS 5

ConsoleWriter::ConsoleWriter(void)
{
	myConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}


ConsoleWriter::~ConsoleWriter(void)
{
}

void ConsoleWriter::WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument, const CONSOLE_MESSAGE_TYPE aMessageType)
{
	SetConsoleTextAttribute(myConsoleHandle, (int)aMessageType);

	if (WriteSpecial(aStringToDisplay))
		return;

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
	SetConsoleTextAttribute(myConsoleHandle, COLOUR_INPUT);
}

bool ConsoleWriter::WriteSpecial(const std::string& aStringToDisplay)
{
	if (aStringToDisplay[0] == TRIGGER_SPECIAL && (aStringToDisplay[1] == '0' || aStringToDisplay[1] == '1' || aStringToDisplay[1] == '2' || aStringToDisplay[1] == '3' || aStringToDisplay[1] == '4'))
	{
		std::array<std::string, MAX_NUM_SPECIAL_STRINGS> specialStrings;
		std::string currentSpecialString;
		int specialIndex = -1;
		bool readyForIndex;

		for(char c : aStringToDisplay)
		{
			if (c == TRIGGER_SPECIAL)
			{
				if (specialIndex >= 0)
				{
					specialStrings[specialIndex] = currentSpecialString;
					currentSpecialString = std::string();
					specialIndex = -1;
				}
					
				readyForIndex = true;
			}
			else if (readyForIndex)
			{
				specialIndex = std::atoi(&c);
				readyForIndex = false;
			}
			else
			{
				currentSpecialString += c;
			}
		}

		specialStrings[specialIndex] = currentSpecialString;

		int lastPopulatedIndex = 0;

		for (int i = 0; i < specialStrings.size(); ++i)
		{
			if (specialStrings[i] != std::string())
			{
				lastPopulatedIndex = i;
			}		
		}

		for (int i = 0; i <= lastPopulatedIndex; ++i)
		{
			WriteStringToConsole(specialStrings[i], std::string(), COLOUR_SPECIAL);
		}

		return true;
	}
	else
	{
		return false;
	}
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
