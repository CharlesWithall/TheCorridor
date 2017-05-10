#pragma once

#include <string>
#include "Command.h"
#include "GoCommand.h"
#include "InvestigateCommand.h"
#include "LookCommand.h"
#include "TakeCommand.h"

enum Action { GO, LOOK, TAKE, INVESTIGATE };

class InputHandler
{
public:
	InputHandler(void);
	~InputHandler(void);
	void HandleInput(const std::string& aUserInput);
private:
	void GetFirstTwoWordsFromString(const std::string& aInputString, std::string& aFirstWord, std::string& aSecondWord);
	bool ConvertStringToAction(const std::string& anInputString, Action& anAction);
	bool CompareStringOrFirstLetter(const std::string& aUserString, const std::string& aGameString);

	Command* myGoCommand;
	Command* myLookCommand;
	Command* myTakeCommand;
	Command* myInvestigateCommand;
};

