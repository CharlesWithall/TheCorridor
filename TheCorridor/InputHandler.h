#pragma once

#include <string>
#include "Command.h"
#include "GoCommand.h"
#include "InvestigateCommand.h"
#include "LookCommand.h"
#include "TakeCommand.h"
#include "ServiceLocator.h"

class InputHandler
{
public:
	InputHandler(void);
	~InputHandler(void);
	Command* HandleInput(const std::string& aUserInput);
private:
	void GetFirstTwoWordsFromString(const std::string& aInputString, std::string& aFirstWord, std::string& aSecondWord);
	bool ConvertStringToAction(const std::string& anInputString, Action& anAction);
	bool ConvertStringToDirection(const std::string& anInputString, Direction& aDirection);
	bool CompareStringOrFirstLetter(const std::string& aUserString, const std::string& aGameString);
};

