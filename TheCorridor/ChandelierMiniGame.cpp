#include "stdafx.h"
#include "ChandelierMiniGame.h"

#define ITEM_REWARD_ID YELLOW_KEY

ChandelierMiniGame::ChandelierMiniGame(const MiniGameID& aMiniGameID, Room* aRoom) : MiniGame(aMiniGameID, aRoom)
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
		ServiceLocator::GetConsoleWriter().ReportError(ERROR_INVALID_CANDLE_SELECTION);

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

	if (IsPuzzleComplete() && myRoom->UnlockItem(ITEM_REWARD_ID))
	{
		PostMiniGameCompleteEvent();
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("A %s dropped out of the wall!", myRoom->GetItem(ITEM_REWARD_ID)->GetItemName());
	}
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

bool ChandelierMiniGame::IsPuzzleComplete() const
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

	return isPuzzleComplete;
}