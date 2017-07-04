#pragma once

#include "Room.h"
#include "ServiceLocator.h"

#include <array>

class ChandelierMiniGame
{
public:
	ChandelierMiniGame(Room* aRoom);
	~ChandelierMiniGame();
	void LightCandle(int aCandleToToggle);
	const RoomID GetLocation() const { return myRoom->GetID(); }
	const ItemID GetReward() const { return myReward; }
	
private:
	void DisplayCandleArrangement() const;
	bool IsPuzzleComplete();

	std::array<bool, 9> myChandeliers;
	Room* myRoom;
	const ItemID myReward;
};

