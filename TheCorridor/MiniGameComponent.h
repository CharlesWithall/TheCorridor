#pragma once

#include "World.h"
#include "ChandelierMiniGame.h"
#include "ChessBoardMiniGame.h"

class MiniGameComponent
{
public:
	MiniGameComponent(const World* aWorld);
	~MiniGameComponent(void);

	ChandelierMiniGame* GetChandelierMiniGame() const { return myChandelierMiniGame; }
	ChessBoardMiniGame* GetChessBoardMiniGame() const { return myChessBoardMiniGame; }
private:

	ChandelierMiniGame* myChandelierMiniGame;
	ChessBoardMiniGame* myChessBoardMiniGame;
};

