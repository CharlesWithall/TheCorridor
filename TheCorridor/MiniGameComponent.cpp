#include "stdafx.h"
#include "MiniGameComponent.h"


MiniGameComponent::MiniGameComponent(const World* aWorld)
{
	myChandelierMiniGame = new ChandelierMiniGame(aWorld->GetRoomByID(CORRIDOR_SIX));
	myChessBoardMiniGame = new ChessBoardMiniGame(aWorld->GetRoomByID(PLAYROOM));
	myWaterPipesMiniGame = new WaterPipesMiniGame(aWorld->GetRoomByID(BATHROOM));
}


MiniGameComponent::~MiniGameComponent(void)
{
	delete myChandelierMiniGame;
	delete myChessBoardMiniGame;
}
