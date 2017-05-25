#pragma once

#include <array>
#include "Room.h"

class World
{
public:
	World();
	~World();
	Room* GetPlayerStartingPosition();
	
private:
	void Init();

	Room** myMap;
};

