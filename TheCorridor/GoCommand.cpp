#include "stdafx.h"
#include "GoCommand.h"


GoCommand::GoCommand(const Direction& aDirection) : myDirection(aDirection)
{

}


GoCommand::~GoCommand(void)
{

}

void GoCommand::Execute(Player* aPlayer)
{
	Room* newRoom = aPlayer->GetCurrentRoom()->GetAdjacentRoom(myDirection);

	if (newRoom)
	{
		aPlayer->GetCurrentRoom()->Exit();
		aPlayer->MoveTo(newRoom);
		aPlayer->GetCurrentRoom()->Enter();
	}
	else
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIRECTION_STRING);
	}	
}
