#pragma once

#include "Definitions.h"

class Item
{
public:
	Item(const std::string anItemName, const ItemID anItemID, const RoomID aRoomID, bool isLocked = false);
	~Item(void);

	void Unlock() { myIsLocked = false; }
	bool IsLocked() const { return myIsLocked; }
	bool IsOwnedByPlayer() const { return myIsOwnedByPlayer; }
	void Pickup() { myIsOwnedByPlayer = true; }
	void Examine();

	const RoomID GetRoomID() const { return myRoomID; }
	const ItemID GetItemID() const { return myItemID; }
	const std::string GetItemName() const { return myItemName; }
private:

	const std::string myItemName;
	const ItemID myItemID;
	const RoomID myRoomID;
	bool myIsOwnedByPlayer;
	bool myIsLocked;
};

