#include "stdafx.h"
#include "ChandelierMiniGame.h"

ChandelierMiniGame::ChandelierMiniGame(Room* aRoom) : myRoom(aRoom), myReward(YELLOW_KEY)
{
	myChandeliers[0] = true;
	myChandeliers[1] = false;
	myChandeliers[2] = false;
	myChandeliers[3] = true;
	myChandeliers[4] = true;
	myChandeliers[5] = false;
	myChandeliers[6] = false;
	myChandeliers[7] = true;
	myChandeliers[8] = false;
}


ChandelierMiniGame::~ChandelierMiniGame(void)
{
}

void ChandelierMiniGame::LightCandle(int aCandleToToggle)
{
	if (aCandleToToggle < 1 || aCandleToToggle > myChandeliers.size())
		throw "Candle selected is outside the bounds of the chandelier arrangement";

	int numberOfCandlesToToggle = 3;

	while (numberOfCandlesToToggle != 0)
	{
		if (aCandleToToggle == myChandeliers.size())
		{
			aCandleToToggle = 0;
		}
		else if (aCandleToToggle == -1)
		{
			aCandleToToggle = myChandeliers.size() - 1;
		}

		myChandeliers[aCandleToToggle] = !myChandeliers[aCandleToToggle];
		
		--numberOfCandlesToToggle;
		--aCandleToToggle;
	}

	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You ignited a candle");
	DisplayCandleArrangement();
	IsPuzzleComplete();
}

void ChandelierMiniGame::DisplayCandleArrangement() const
{
	std::string visualCandleArrangement;

	for (bool candle : myChandeliers)
	{
		visualCandleArrangement += candle ? 'O' : 'X';
		visualCandleArrangement += ' ';
	}

	ServiceLocator::GetConsoleWriter().WriteStringToConsole(visualCandleArrangement);
}

bool ChandelierMiniGame::IsPuzzleComplete()
{
	bool isPuzzleComplete = true;

	for (bool candleIsLit : myChandeliers)
	{
		if (!candleIsLit)
		{
			isPuzzleComplete = false;
			break;
		}
	}

	if (isPuzzleComplete && myRoom->UnlockItem(myReward))
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("A %s dropped out of the wall!", myRoom->GetItem(myReward)->GetItemName());
	}

	return isPuzzleComplete;
}