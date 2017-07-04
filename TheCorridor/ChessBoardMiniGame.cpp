#include "stdafx.h"
#include "ChessBoardMiniGame.h"


ChessBoardMiniGame::ChessBoardMiniGame(Room* aRoom) : currentPosition(0), myRoom(aRoom)
{
	pathToEnd[0] = EAST;
	pathToEnd[1] = SOUTH;
	pathToEnd[2] = SOUTH;
	pathToEnd[3] = EAST;
	pathToEnd[4] = EAST;
	pathToEnd[5] = EAST;
	pathToEnd[6] = NORTH;
	pathToEnd[7] = NORTH;
	pathToEnd[8] = WEST;
	pathToEnd[9] = NORTH;
	pathToEnd[10] = NORTH;
	pathToEnd[11] = EAST;
	pathToEnd[12] = EAST;
	pathToEnd[13] = NORTH;
}


ChessBoardMiniGame::~ChessBoardMiniGame(void)
{
}

void ChessBoardMiniGame::MoveToPodium(const Direction& aDirection)
{
	if (currentPosition >= LENGTH_OF_PATH)
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The traps in this room have deactivated - you can walk freely across the tiles");
	}
	else if (pathToEnd[currentPosition] == aDirection)
	{
		++currentPosition;
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("You step onto the next tile...");
		if (currentPosition == LENGTH_OF_PATH)
		{
			myRoom->UnlockItem(GREEN_KEY);
			ServiceLocator::GetConsoleWriter().WriteStringToConsole("You've reach the podium with the %s", myRoom->GetItem(GREEN_KEY)->GetItemName());
		}
	}
	else
	{
		currentPosition = 0;
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The room fills with gas... You wake up on the first tile again");
	}
}


