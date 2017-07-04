#include "stdafx.h"
#include "Item.h"


Item::Item(const std::string anItemName, const ItemID anItemID, const RoomID aRoomID, bool isLocked) :
	myItemName(anItemName), myItemID(anItemID), myRoomID(aRoomID), myIsOwnedByPlayer(false), myIsLocked(isLocked)
{

}


Item::~Item(void)
{
}
