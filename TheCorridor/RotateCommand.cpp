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
				if (aPlayer->GetItemsComponent()->GetItem(BUCKET))
				{
					waterPipesMiniGame->TurnDial(myDial);
				}
				else
				{
					ServiceLocator::GetConsoleWriter().WriteStringToConsole("You should find a bucket before you start trying to turn on the PIPES");
				}
			}
		}
	}	
}
