#include "stdafx.h"
#include "InputHandler.h"
#include <iostream>

InputHandler::InputHandler(void)
{
	myGoCommand = new GoCommand;
	myInvestigateCommand = new InvestigateCommand;
	myLookCommand = new LookCommand;
	myTakeCommand = new TakeCommand;
}


InputHandler::~InputHandler(void)
{
	delete myGoCommand;
	delete myInvestigateCommand;
	delete myLookCommand;
	delete myTakeCommand;
}

void InputHandler::HandleInput(const std::string& aUserInput)
{
	std::string firstWord;
	std::string lastWord;
	Action action;

	GetFirstTwoWordsFromString(aUserInput, firstWord, lastWord);
	ConvertStringToAction(firstWord, action);

	switch (action)
	{
		case GO:
			myGoCommand->Execute();
			break;
		case TAKE:
			myTakeCommand->Execute();
			break;
		case LOOK:
			myLookCommand->Execute();
			break;
		case INVESTIGATE:
			myInvestigateCommand->Execute();
			break;
		default:
			throw "Action command not recognised";
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