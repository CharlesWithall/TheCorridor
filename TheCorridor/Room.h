#pragma once
#include "ServiceLocator.h"
#include "Item.h"
#include <map>
#include <vector>

class Room
{
public:
	Room(Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom, const RoomID& aRoomID);
	~Room(void);
	void AddItem(Item* anItem) { myItems.push_back(anItem); }
	void Enter();
	void Exit(const Direction& aDirection);
	void Look(const Direction& aDirection);
	Room* GetAdjacentRoom(const Direction& aDirection);
	const RoomID& GetID() const { return myRoomId; }
	Item* GetItem(const ItemID& anItemID);
	bool UnlockItem(const ItemID& anItemID);
private:
	void Init();

	const RoomID myRoomId;
	const std::string myEntryText;

	std::map<Direction, Room*> myAdjacentRooms;
	std::map<Direction, std::string> myLookDialogue;
	std::map<Direction, std::string> myGoDialogue;

	std::vector<Item*> myItems;
};



