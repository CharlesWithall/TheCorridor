#include "stdafx.h"
#include "ItemAcquiredEvent.h"


ItemAcquiredEvent::ItemAcquiredEvent(const ItemID& anItemID, const RoomID& aRoomID) : myItemID(anItemID), myRoomID(aRoomID)
{
}


ItemAcquiredEvent::~ItemAcquiredEvent()
{
}
