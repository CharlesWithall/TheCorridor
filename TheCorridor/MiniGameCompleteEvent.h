#pragma once

#include <vector>

#include "IObserver.h"
#include "Event.h"

class MiniGameCompleteEvent : public Event
{
public:
	MiniGameCompleteEvent(const MiniGameID& aMiniGameID);
	~MiniGameCompleteEvent();

	const MiniGameID myMiniGameID;
};

