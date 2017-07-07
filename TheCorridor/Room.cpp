#include "stdafx.h"
#include "Room.h"

Room::Room(Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom, const RoomID& aRoomID) : myRoomId(aRoomID)
{
	Init();

	myAdjacentRooms[NORTH] = aNorthRoom;
	myAdjacentRooms[WEST] = aWestRoom;
	myAdjacentRooms[SOUTH] = aSouthRoom;
	myAdjacentRooms[EAST] = anEastRoom;
}

Room::~Room(void)
{

}

void Room::Enter()
{
	//ServiceLocator::GetConsoleWriter().WriteStringToConsole(myEntryText);
}

void Room::Exit(const Direction& aDirection)
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myGoDialogue[aDirection]);
}

void Room::Init()
{
	DataRepository& data = ServiceLocator::GetData();
	
	for (int i = 0; i != ACTION_COUNT; ++i)
	{
		Direction direction = static_cast<Direction>(i);
		myLookDialogue[direction] = data.GetDialogueText(myRoomId, LOOK, direction);
		myGoDialogue[direction] = data.GetDialogueText(myRoomId, GO, direction);
	}
}

void Room::Look(const Direction& aDirection)
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myLookDialogue[aDirection]);
}

Room* Room::GetAdjacentRoom(const Direction& aDirection)
{
	return myAdjacentRooms[aDirection];
}

Item* Room::GetItem(const ItemID& anItemID)
{
	for (Item* item : myItems)
	{
		if (item->GetItemID() == anItemID)
		{
			return item;
		}
	}

	return nullptr;
}

bool Room::UnlockItem(const ItemID& anItemID)
{
	for (Item* item : myItems)
	{
		if (item->GetItemID() == anItemID && item->IsLocked())
		{
			item->Unlock();
			return true;
		}
	}

	return false;
}