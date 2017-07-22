#include "stdafx.h"
#include "MiniGame.h"


MiniGame::MiniGame(const MiniGameID& aMiniGameID, Room* aRoom) : myMiniGameID(aMiniGameID), myRoom(aRoom)
{
}


MiniGame::~MiniGame()
{
}

void MiniGame::Notify(const Event* const anEvent)
{
	for (IObserver* observer : myObservers)
	{
		observer->OnNotify(anEvent);
	}
}

void MiniGame::PostMiniGameCompleteEvent()
{
	const MiniGameCompleteEvent* const miniGameComplete = new MiniGameCompleteEvent(myMiniGameID);
	Notify(miniGameComplete);
	delete miniGameComplete;
}
