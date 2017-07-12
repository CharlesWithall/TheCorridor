#include "stdafx.h"
#include "Item.h"


Item::Item(const std::string anItemName, const std::string anExamineDialogue, const ItemID anItemID, const RoomID aRoomID, bool isLocked) :
	myItemName(anItemName), myDefaultExamineDialogue(anExamineDialogue), myItemID(anItemID), myRoomID(aRoomID), myIsOwnedByPlayer(false), myIsLocked(isLocked)
{

}


Item::~Item(void)
{
}