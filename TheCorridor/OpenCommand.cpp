#include "stdafx.h"
#include "OpenCommand.h"


OpenCommand::OpenCommand()
{
}


OpenCommand::~OpenCommand()
{
}

void OpenCommand::Execute(Player* aPlayer)
{
	if (aPlayer->GetNumberOfKeysAcquired() == TOTAL_NUMBER_OF_KEYS)
	{
		aPlayer->CompleteGame();
	}
}