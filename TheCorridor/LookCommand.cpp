#include "stdafx.h"
#include "LookCommand.h"


LookCommand::LookCommand(Direction aDirection) : myDirection(aDirection)
{
}


LookCommand::~LookCommand(void)
{
}

void LookCommand::Execute(Player* aPlayer)
{
	aPlayer->GetCurrentRoom()->Look(myDirection);
}
