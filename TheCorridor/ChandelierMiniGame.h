#pragma once

#include "MiniGame.h"

#include <array>

class ChandelierMiniGame : public MiniGame
{
public:
	ChandelierMiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~ChandelierMiniGame();

	void LightCandle(int aCandleToToggle);
	
	virtual bool IsPuzzleComplete() const override;

private:
	void DisplayCandleArrangement() const;

	std::array<bool, 9> myChandeliers;
};

