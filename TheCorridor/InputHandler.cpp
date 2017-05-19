#include "stdafx.h"
#include "InputHandler.h"

InputHandler::InputHandler(void)
{

}

InputHandler::~InputHandler(void)
{
}

Command* InputHandler::HandleInput(const std::string& aUserInput)
{
	std::string firstWord;
	std::string lastWord;
	Action action;
	Direction direction;

	GetFirstTwoWordsFromString(aUserInput, firstWord, lastWord);	

	if (!ConvertStringToAction(firstWord, action))
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_COMMAND_STRING);
		return NULL;
	}
	else
	{
		switch (action)
		{
		case GO:
			if (!ConvertStringToDirection(lastWord, direction))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIRECTION_STRING);
				return NULL;
			}

			return new GoCommand(direction);
		case TAKE:
			if (!ConvertStringToDirection(lastWord, direction))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIRECTION_STRING);
				return NULL;
			}

			return new TakeCommand(direction);
		case LOOK:
			return new LookCommand;
		case INVESTIGATE:
			return new InvestigateCommand;
		default:
			throw "Invalid action command generated";
		}
	}	
}

void InputHandler::GetFirstTwoWordsFromString(const std::string& anInputString, std::string& aFirstWord, std::string& aSecondWord)
{	
	aFirstWord = anInputString.substr(0, anInputString.find_first_of(" \t"));
	aSecondWord = anInputString.substr(anInputString.find_first_of(" \t")+1, std::string::npos);	
}

bool InputHandler::ConvertStringToAction(const std::string& anInputString, Action& anAction)
{
	if (CompareStringOrFirstLetter(anInputString, "GO"))
	{
		anAction = Action::GO;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "LOOK"))
	{
		anAction = Action::LOOK;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "TAKE"))
	{
		anAction = Action::TAKE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "INVESTIGATE"))
	{
		anAction = Action::INVESTIGATE;
		return true;
	}

	return false;
}

bool InputHandler::ConvertStringToDirection(const std::string& anInputString, Direction& aDirection)
{
	if (CompareStringOrFirstLetter(anInputString, "NORTH"))
	{
		aDirection = Direction::NORTH;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "EAST"))
	{
		aDirection = Direction::EAST;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "SOUTH"))
	{
		aDirection = Direction::SOUTH;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "WEST"))
	{
		aDirection = Direction::WEST;
		return true;
	}

	return false;
}

bool InputHandler::CompareStringOrFirstLetter(const std::string& aUserString, const std::string& aGameString)
{
	if (aUserString.length() == aGameString.length())
	{
		for (int i = 0; i < aUserString.length(); ++i)
		{
			if (toupper(aUserString[i]) != aGameString[i])
			{
				return false;
			}
		}
	}
	else
	{
		if (aUserString.length() == 1 && toupper(aUserString[0]) == aGameString[0])
		{
			return true;
		}

		return false;
	}

	return true;
}