#pragma once

#include "MiniGame.h"

class WaterPipesMiniGame : public MiniGame
{
public:
	WaterPipesMiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~WaterPipesMiniGame(void);

	virtual bool IsPuzzleComplete() const override;
	void TurnDial(const LeftRight& aDialToTurn);
private:
	int myLeftHandDial;
	int myRightHandDial;
};

