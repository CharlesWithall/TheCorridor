#pragma once

#include "World.h"
#include "BookCaseMiniGame.h"
#include "ChandelierMiniGame.h"
#include "ChessBoardMiniGame.h"
#include "MusicRoomMiniGame.h"
#include "WaterPipesMiniGame.h"

class MiniGameComponent
{
public:
	MiniGameComponent(const World* aWorld);
	~MiniGameComponent(void);

	BookCaseMiniGame* GetBookCaseMiniGame() const { return myBookCaseMiniGame; }
	ChandelierMiniGame* GetChandelierMiniGame() const { return myChandelierMiniGame; }
	ChessBoardMiniGame* GetChessBoardMiniGame() const { return myChessBoardMiniGame; }
	MusicRoomMiniGame* GetMusicRoomMiniGame() const { return myMusicRoomMiniGame; }
	WaterPipesMiniGame* GetWaterPipesMiniGame() const { return myWaterPipesMiniGame; }

	std::vector<MiniGame*> myMiniGames;
private:
	BookCaseMiniGame* myBookCaseMiniGame;
	ChandelierMiniGame* myChandelierMiniGame;
	ChessBoardMiniGame* myChessBoardMiniGame;
	MusicRoomMiniGame* myMusicRoomMiniGame;
	WaterPipesMiniGame* myWaterPipesMiniGame;
};
