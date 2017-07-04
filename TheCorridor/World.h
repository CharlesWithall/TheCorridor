#pragma once

#include "Room.h"

class World
{
public:
	World();
	~World();
	Room* GetPlayerStartingPosition();
	Room* GetRoomByID(const RoomID& aRoomID) const;
private:
	void Init();
	void InitRooms();
	void InitItems();

	Room** myMap;
	std::vector<Item*> myItems;
};

