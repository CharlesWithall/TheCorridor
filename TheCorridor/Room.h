#pragma once
#include "ServiceLocator.h"
#include <map>

class Room
{
public:
	Room(std::string anEntryText, Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom);
	~Room(void);
	void Enter();
	void Exit();
	Room* GetAdjacentRoom(Direction aDirection);
	const std::string myEntryText;
private:
	std::map<Direction, Room*> myAdjacentRooms;
};



