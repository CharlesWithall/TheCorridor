#include "stdafx.h"
#include "WaterPipesMiniGame.h"

#define MAX_DIAL_VALUE 5
#define LEFT_DIAL_COMPLETE 4
#define RIGHT_DIAL_COMPLETE 2

WaterPipesMiniGame::WaterPipesMiniGame(const MiniGameID& aMiniGameID, Room* aRoom) : MiniGame(aMiniGameID, aRoom), myLeftHandDial(0), myRightHandDial(0)
{
}


WaterPipesMiniGame::~WaterPipesMiniGame(void)
{
}

void WaterPipesMiniGame::TurnDial(const LeftRight& aDialToTurn)
{
	int* dialToTurn;

	switch (aDialToTurn)
	{
		case LEFT: dialToTurn = &myLeftHandDial; break;
		case RIGHT: dialToTurn = &myRightHandDial; break;
		default: ServiceLocator::GetConsoleWriter().ReportError(ERROR_INVALID_DIAL_STRING); throw;
	}

	if (*dialToTurn >= MAX_DIAL_VALUE)
	{
		*dialToTurn = 0;
	}
	else
	{
		++*dialToTurn;
	}


	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You turned a dial...");
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("The male dial now reads %s", std::to_string(myLeftHandDial));
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("The female dial now reads %s", std::to_string(myRightHandDial));

	if (IsPuzzleComplete())
	{
		PostMiniGameCompleteEvent();
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("A stream of water comes gushing out of the pipes. You fill your bucket with water.");
	}
}

bool WaterPipesMiniGame::IsPuzzleComplete() const
{
	bool isPuzzleComplete = false;

	if (myLeftHandDial == LEFT_DIAL_COMPLETE && myRightHandDial == RIGHT_DIAL_COMPLETE)
	{
		isPuzzleComplete = true;
	}

	return isPuzzleComplete;
}