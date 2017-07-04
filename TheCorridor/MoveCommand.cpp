#include "stdafx.h"
#include "MoveCommand.h"


MoveCommand::MoveCommand(const Direction aDirectionToStep) : myDirection(aDirectionToStep)
{

}


MoveCommand::~MoveCommand(void)
{
}

void MoveCommand::Execute(Player* aPlayer)
{
	if (MiniGameComponent* miniGameComponent = aPlayer->GetMiniGameComponent())
	{
		if (ChessBoardMiniGame* chessBoardMiniGame = miniGameComponent->GetChessBoardMiniGame())
		{
			chessBoardMiniGame->MoveToPodium(myDirection);
		}		
	}
}
