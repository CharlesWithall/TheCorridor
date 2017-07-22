#pragma once

#include "Definitions.h"

class Item
{
public:
	Item(const std::string anItemName, const std::string anExamineDialogue, const ItemID anItemID, const RoomID aRoomID, bool isLocked = false, bool isUsable = true);
	~Item(void);

	void Unlock() { myIsLocked = false; }
	bool IsLocked() const { return myIsLocked; }
	bool IsOwnedByPlayer() const { return myIsOwnedByPlayer; }
	bool IsUsable() const { return myIsUsable; }
	void Pickup() { myIsOwnedByPlayer = true; }
	void MakeUsable() { myIsUsable = true; }
	void MakeUnusable() { myIsUsable = false; }
	void CombineItems(const std::string& anAdditionalDialogue) { myDefaultExamineDialogue += anAdditionalDialogue; }

	const RoomID GetRoomID() const { return myRoomID; }
	const ItemID GetItemID() const { return myItemID; }
	const std::string GetItemName() const { return myItemName; }
	const std::string GetDialogue() const { return myDefaultExamineDialogue; }
private:
	const std::string myItemName;
	std::string myDefaultExamineDialogue;

	const ItemID myItemID;
	const RoomID myRoomID;

	bool myIsOwnedByPlayer;
	bool myIsLocked;
	bool myIsUsable;
};

