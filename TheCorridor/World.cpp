#include "stdafx.h"
#include "MiniGameCompleteEvent.h"
#include "World.h"
#include <iostream>


World::World(void)
{
	Init();
	InitRooms();
	InitItems();
}


World::~World(void)
{
	for (int i = 0; i < MAX_WORLD_SIZE; ++i)
	{
		delete myMap[i];
	}

	delete[] myMap;

	for (Item* item : myItems)
	{
		delete item;
	}
}

void World::Init()
{
	myMap = new Room*[MAX_WORLD_SIZE];

	for (int i = 0; i < MAX_WORLD_SIZE; ++i)
	{
		myMap[i] = (Room*) operator new(sizeof(Room));
	}
}

void World::InitRooms()
{
	std::vector<RoomID> roomIDs = ServiceLocator::GetData().GetAllRoomIds();

	for (const RoomID roomID : roomIDs)
	{
		std::string roomName = ServiceLocator::GetData().GetRoomNameByID(roomID);
		std::array<RoomID, 4> adjacentRooms = ServiceLocator::GetData().GetAllAdjacentRooms(roomID);

		new (myMap[roomID]) Room(roomName, roomID);

		myMap[roomID]->myAdjacentRooms[NORTH] = adjacentRooms[NORTH] ? myMap[adjacentRooms[NORTH]] : NULL;
		myMap[roomID]->myAdjacentRooms[EAST] = adjacentRooms[EAST] ? myMap[adjacentRooms[EAST]] : NULL;
		myMap[roomID]->myAdjacentRooms[SOUTH] = adjacentRooms[SOUTH] ? myMap[adjacentRooms[SOUTH]] : NULL;
		myMap[roomID]->myAdjacentRooms[WEST] = adjacentRooms[WEST] ? myMap[adjacentRooms[WEST]] : NULL;
	}
}

void World::InitItems()
{
	myItems = ServiceLocator::GetData().LoadAllItems();

	for (Item* item : myItems)
	{
		if (Room* aRoom = GetRoomByID(item->GetRoomID()))
		{
			aRoom->AddItem(item);
		}
	}	
}

Room* World::GetRoomByID(const RoomID& aRoomID) const
{
	for (int i = 0; i < MAX_WORLD_SIZE; ++i)
	{
		if (myMap[i]->GetID() == aRoomID)
		{
			return myMap[i];
		}
	}

	return nullptr;
}

Room* World::GetPlayerStartingPosition()
{
	return myMap[CORRIDOR_ONE];
}

void World::OnNotify(const Event* const anEvent)
{
	if (const MiniGameCompleteEvent* const miniGameComplete = static_cast<const MiniGameCompleteEvent* const>(anEvent))
	{
		if (miniGameComplete->myMiniGameID == MG_BOOKS)
		{
			myMap[LIBRARY]->myAdjacentRooms[EAST] = myMap[SECRET_ROOM];
		}

		if (miniGameComplete->myMiniGameID == MG_WATERPIPES)
		{
			if (Item* item = myMap[DRAWING_ROOM]->GetItem(BUCKET))
			{
				item->MakeUsable();
			}
		}
	}
}

	

