#pragma once

#include "Item.h"
#include "ServiceLocator.h"

#include <string>

class ItemBuilder
{
public:
	ItemBuilder() {}
	~ItemBuilder() {}

	ItemBuilder& setItemName(const std::string& anItemName) { myItemName = anItemName; return *this; }
	ItemBuilder& setExamineDialogue(const std::string& anExamineDialogue) { myExamineDialogue = anExamineDialogue; return *this; }
	ItemBuilder& setAfterUseExamineDialogue(const std::string& anAfterUseExamineDialogue) { myAfterUseExamineDialogue = anAfterUseExamineDialogue; return *this; }
	ItemBuilder& setItemID(const ItemID& anItemID) { myItemID = anItemID; return *this; }
	ItemBuilder& setRoomID(const RoomID& aRoomID) { myRoomID = aRoomID; return *this; }
	ItemBuilder& setIsLocked(const bool anIsLocked) { myIsLocked = anIsLocked; return *this; }
	ItemBuilder& setIsUsable(const bool anIsUsable) { myIsUsable = anIsUsable; return *this; }

	// produce desired Product
	Item* Build()
	{
		return new Item(myItemName, myExamineDialogue, myAfterUseExamineDialogue, myItemID, myRoomID, myIsLocked, myIsUsable);
	}

private:
	std::string myItemName = std::string();
	std::string myExamineDialogue = INVALID_ITEM_STRING;
	std::string myAfterUseExamineDialogue = std::string();

	ItemID myItemID = ITEM_INVALID;
	RoomID myRoomID = INVALID_ROOM;

	bool myIsLocked = false;
	bool myIsUsable = true;
};

