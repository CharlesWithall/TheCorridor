#include "stdafx.h"
#include "IgniteCommand.h"


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
			if (chandelierMiniGame->GetLocation() == aPlayer->GetCurrentRoom()->GetID())
			{
				chandelierMiniGame->LightCandle(myCandleToIgnite);
			}
		}
	}	
}
