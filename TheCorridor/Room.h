#pragma once
#include "ServiceLocator.h"
#include "Item.h"
#include <array>
#include <vector>

class Room
{
	friend class World;
public:
	Room(const std::string& aRoomName, const RoomID& aRoomID);
	void AddItem(Item* anItem) { myItems.push_back(anItem); }
	void Enter();
	void Exit(const Direction& aDirection);
	void Look(const Direction& aDirection) const;
	Room* GetAdjacentRoom(const Direction& aDirection);
	const RoomID& GetID() const { return myRoomId; }
	Item* GetItem(const ItemID& anItemID) const;
	bool UnlockItem(const ItemID& anItemID);
private:
	void Init();

	const std::string myRoomName;
	const RoomID myRoomId;
	const std::string myEntryText;

	std::array<Room*, DIRECTION_COUNT> myAdjacentRooms;
	std::array<std::string, DIRECTION_COUNT> myLookDialogue;
	std::array<std::string, DIRECTION_COUNT> myGoDialogue;

	std::vector<Item*> myItems;
};



