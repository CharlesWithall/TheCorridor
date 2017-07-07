#pragma once

#include "Room.h"
#include "ServiceLocator.h"

class WaterPipesMiniGame
{
public:
	WaterPipesMiniGame(const Room* aRoom);
	~WaterPipesMiniGame(void);

	bool IsPuzzleComplete();
	void TurnDial(const LeftRight& aDialToTurn);

	const RoomID GetLocation() const { return myRoom->GetID(); }
private:
	int myLeftHandDial;
	int myRightHandDial;

	const Room* myRoom;
};

