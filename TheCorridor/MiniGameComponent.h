#pragma once

#include "World.h"
#include "ChandelierMiniGame.h"
#include "ChessBoardMiniGame.h"
#include "WaterPipesMiniGame.h"

class MiniGameComponent
{
public:
	MiniGameComponent(const World* aWorld);
	~MiniGameComponent(void);

	ChandelierMiniGame* GetChandelierMiniGame() const { return myChandelierMiniGame; }
	ChessBoardMiniGame* GetChessBoardMiniGame() const { return myChessBoardMiniGame; }
	WaterPipesMiniGame* GetWaterPipesMiniGame() const { return myWaterPipesMiniGame; }
private:

	ChandelierMiniGame* myChandelierMiniGame;
	ChessBoardMiniGame* myChessBoardMiniGame;
	WaterPipesMiniGame* myWaterPipesMiniGame;
};

