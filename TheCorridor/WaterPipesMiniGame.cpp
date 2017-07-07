#include "stdafx.h"
#include "WaterPipesMiniGame.h"

#define MAX_DIAL_VALUE 9
#define INVALID_DIAL_STRING "An invalid dial was selected"
#define INVALID_DIAL_DIRECTION_STRING "An invalid dial turning direction was selected"
#define LEFT_DIAL_COMPLETE 5
#define RIGHT_DIAL_COMPLETE 4

WaterPipesMiniGame::WaterPipesMiniGame(const Room* aRoom) : myRoom(aRoom), myLeftHandDial(0), myRightHandDial(0)
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
		default: throw INVALID_DIAL_STRING;
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

	IsPuzzleComplete();
}

bool WaterPipesMiniGame::IsPuzzleComplete()
{
	bool isPuzzleComplete = false;

	if (myLeftHandDial == LEFT_DIAL_COMPLETE && myRightHandDial == RIGHT_DIAL_COMPLETE)
	{
		isPuzzleComplete = true;
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("A stream of water comes gushing out of the pipes!");
	}

	return isPuzzleComplete;
}