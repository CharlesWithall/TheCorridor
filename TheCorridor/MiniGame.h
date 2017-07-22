#pragma once

#include "MiniGameCompleteEvent.h"
#include "Notifier.h"
#include "Room.h"
#include "ServiceLocator.h"

class MiniGame : public Notifier
{
public:
	MiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~MiniGame();

	virtual bool IsPuzzleComplete() const = 0;

	virtual void Notify(const Event* const anEvent) override;

	virtual const RoomID GetLocation() const { return myRoom->GetID(); }
	const MiniGameID GetMiniGameID() const { return myMiniGameID; }

protected:
	void PostMiniGameCompleteEvent();

	const MiniGameID myMiniGameID;
	Room* myRoom;
};

