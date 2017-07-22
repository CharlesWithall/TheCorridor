#include "stdafx.h"
#include "IgniteCommand.h"

#define NEED_MATCHBOX_STRING "You need to find a match box with which to ignite the candles!"

IgniteCommand::IgniteCommand(const int aCandleToIgnite) : myCandleToIgnite(aCandleToIgnite)
{
	
}

IgniteCommand::~IgniteCommand(void)
{
}

void IgniteCommand::Execute(Player* aPlayer)
{
	if (MiniGameComponent* miniGameComponent = aPlayer->GetMiniGameComponent())
	{
		if (ChandelierMiniGame* chandelierMiniGame = miniGameComponent->GetChandelierMiniGame())
		{
			if (aPlayer->GetItemsComponent()->GetItem(MATCHBOX) == nullptr)
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(NEED_MATCHBOX_STRING);
				return;
			}
			else if (chandelierMiniGame->GetLocation() == aPlayer->GetCurrentRoom()->GetID())
			{
				chandelierMiniGame->LightCandle(myCandleToIgnite);
				return;
			}
		}
	}

	ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_COMMAND_STRING);
}
