#pragma once

#include <array>
#include "Room.h"
#include "ServiceLocator.h"

#define LENGTH_OF_PATH 14

class ChessBoardMiniGame
{
public:
	ChessBoardMiniGame(Room* aRoom);
	~ChessBoardMiniGame(void);


	const RoomID GetLocation() const { return myRoom->GetID(); }
	void MoveToPodium(const Direction& aDirection);
private:
	int currentPosition;
	Room* myRoom;
	std::array<Direction, LENGTH_OF_PATH> pathToEnd;
};

