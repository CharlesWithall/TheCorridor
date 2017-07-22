#include "stdafx.h"
#include "MiniGameComponent.h"


MiniGameComponent::MiniGameComponent(const World* aWorld)
{
	myBookCaseMiniGame = new BookCaseMiniGame(MG_BOOKS, aWorld->GetRoomByID(LIBRARY));
	myChandelierMiniGame = new ChandelierMiniGame(MG_CHANDELIERS, aWorld->GetRoomByID(CORRIDOR_SIX));
	myChessBoardMiniGame = new ChessBoardMiniGame(MG_CHESSBOARD, aWorld->GetRoomByID(PLAYROOM));
	myWaterPipesMiniGame = new WaterPipesMiniGame(MG_WATERPIPES, aWorld->GetRoomByID(BATHROOM));

	myMiniGames.push_back(myBookCaseMiniGame);
	myMiniGames.push_back(myChandelierMiniGame);
	myMiniGames.push_back(myChessBoardMiniGame);
	myMiniGames.push_back(myWaterPipesMiniGame);
}

MiniGameComponent::~MiniGameComponent(void)
{
	delete myBookCaseMiniGame;
	delete myChandelierMiniGame;
	delete myChessBoardMiniGame;
	delete myWaterPipesMiniGame;
}