#pragma once

#include "Room.h"

class Player
{
public:
	Player(Room* aStartingLocation);
	~Player(void);
	Room* GetCurrentRoom() { return myCurrentRoom; }
	void MoveTo(Room* aNewRoom);
private:
	Room* myCurrentRoom;
};

