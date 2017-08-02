#pragma once

#include "Definitions.h"

class Item
{
	friend class ItemBuilder;

public:
	~Item(void);

	void Unlock() { myIsLocked = false; }
	bool IsLocked() const { return myIsLocked; }
	bool IsOwnedByPlayer() const { return myIsOwnedByPlayer; }
	bool IsUsable() const { return myIsUsable; }
	void Pickup() { myIsOwnedByPlayer = true; }
	void MakeUsable() { myIsUsable = true; }
	void MakeUnusable() { myIsUsable = false; }
	void CombineItems(const std::string& anAdditionalDialogue) { myDefaultExamineDialogue += anAdditionalDialogue; }
	void SwitchDialogue();

	const RoomID GetRoomID() const { return myRoomID; }
	const ItemID GetItemID() const { return myItemID; }
	const std::string GetItemName() const { return myItemName; }
	const std::string GetDialogue() const { return myDefaultExamineDialogue; }
private:
	Item(const std::string anItemName, const std::string anExamineDialogue, const std::string anAfterUseExamineDialogue, const ItemID anItemID, const RoomID aRoomID, bool isLocked, bool isUsable);

	const std::string myItemName;
	std::string myDefaultExamineDialogue;
	std::string myAfterUseExamineDialogue;

	const ItemID myItemID;
	const RoomID myRoomID;

	bool myIsOwnedByPlayer;
	bool myIsLocked;
	bool myIsUsable;
};

