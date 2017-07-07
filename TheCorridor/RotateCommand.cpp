#include "stdafx.h"
#include "RotateCommand.h"


RotateCommand::RotateCommand(const LeftRight& aDialToTurn) : myDial(aDialToTurn)
{

}


RotateCommand::~RotateCommand(void)
{
}

void RotateCommand::Execute(Player* aPlayer)
{
	if (MiniGameComponent* miniGameComponent = aPlayer->GetMiniGameComponent())
	{
		if (WaterPipesMiniGame* waterPipesMiniGame = miniGameComponent->GetWaterPipesMiniGame())
		{
			if (waterPipesMiniGame->GetLocation() == aPlayer->GetCurrentRoom()->GetID())
			{
				waterPipesMiniGame->TurnDial(myDial);
			}
		}
	}	
}
