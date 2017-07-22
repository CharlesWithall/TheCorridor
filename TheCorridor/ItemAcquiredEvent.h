#pragma once

#include <vector>

#include "IObserver.h"
#include "Event.h"

class ItemAcquiredEvent : public Event
{
public:
	ItemAcquiredEvent(const ItemID& anItemID);
	~ItemAcquiredEvent();

	const ItemID myItemID;
};

