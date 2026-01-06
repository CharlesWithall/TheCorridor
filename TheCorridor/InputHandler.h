#pragma once

#include <string>
#include "Command.h"
#include "ExamineCommand.h"
#include "GoCommand.h"
#include "IgniteCommand.h"
#include "MoveCommand.h"
#include "LookCommand.h"
#include "OpenCommand.h"
#include "PullCommand.h"
#include "PlayCommand.h"
#include "RotateCommand.h"
#include "TakeCommand.h"
#include "UseCommand.h"
#include "ServiceLocator.h"

class InputHandler
{
public:
	InputHandler(void);
	~InputHandler(void);
	Command* HandleInput(const Player* aPlayer, const std::string& aUserInput);
private:
	void GetFirstTwoWordsFromString(const std::string& aInputString, std::string& aFirstWord, std::string& aSecondWord);
	bool HandleSpecialInputs(const Player* aPlayer, const std::string& anUserInput);
	bool ConvertStringToAction(const std::string& anInputString, Action& anAction, const Player* aPlayer);
	bool ConvertStringToDirection(const std::string& anInputString, Direction& aDirection);
	bool ConvertStringToItem(const std::string& anInputString, ItemID& anItemID);
	bool ConvertStringToInt(const std::string& anInputString, int& aCandleNumber);
	bool ConvertStringToLeftRight(const std::string& anInputString, LeftRight& aDirection);
	bool CompareStringOrFirstLetter(const std::string& aUserString, const std::string& aGameString);
};
