#include "stdafx.h"
#include "Room.h"

// A Room that holds items and performs actions on entry and exit
// The player's room is treated like a {STATE PATTERN}
Room::Room(const std::string& aRoomName, const RoomID& aRoomID) : myRoomName(aRoomName), myRoomId(aRoomID)
{
	Init();
}

void Room::Enter()
{
	std::wstring formattedRoomName(myRoomName.length(), L' ');
	std::copy(myRoomName.begin(), myRoomName.end(), formattedRoomName.begin());
	//SetConsoleTitle(formattedRoomName.c_str());
}

void Room::Exit(const Direction& aDirection)
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myGoDialogue[aDirection]);
}

// Gets Go and Look Dialogue from the Data Repository
void Room::Init()
{
	DataRepository& data = ServiceLocator::GetData();
	
	for (int i = 0; i != DIRECTION_COUNT; ++i)
	{
		Direction direction = static_cast<Direction>(i);
		myLookDialogue[direction] = data.GetDialogueText(ROOM_DATA_TYPE, myRoomId, LOOK, direction);
		myGoDialogue[direction] = data.GetDialogueText(ROOM_DATA_TYPE, myRoomId, GO, direction);
	}
}

void Room::Look(const Direction& aDirection) const
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myLookDialogue[aDirection]);
}

Room* Room::GetAdjacentRoom(const Direction& aDirection)
{
	return myAdjacentRooms[aDirection];
}

Item* Room::GetItem(const ItemID& anItemID) const
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