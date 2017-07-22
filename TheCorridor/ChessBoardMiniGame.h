#pragma once

#include "MiniGame.h"

#include <array>

#define LENGTH_OF_PATH 14

class ChessBoardMiniGame : public MiniGame
{
public:
	ChessBoardMiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~ChessBoardMiniGame(void);

	void MoveToPodium(const Direction& aDirection);

	virtual bool IsPuzzleComplete() const override { return currentPosition >= LENGTH_OF_PATH; }
private:
	int currentPosition;
	std::array<Direction, LENGTH_OF_PATH> pathToEnd;
};

