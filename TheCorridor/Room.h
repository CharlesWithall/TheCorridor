#pragma once
#include "ServiceLocator.h"
#include <map>

class Room
{
public:
	Room(Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom, const int& roomID);
	~Room(void);
	void Enter();
	void Exit(const Direction& aDirection);
	void Look(const Direction& aDirection);
	Room* GetAdjacentRoom(const Direction& aDirection);
private:
	void Init();

	const int myRoomId;
	const std::string myEntryText;
	std::map<Direction, Room*> myAdjacentRooms;
	std::map<Direction, std::string> myLookDialogue;
	std::map<Direction, std::string> myGoDialogue;
};



