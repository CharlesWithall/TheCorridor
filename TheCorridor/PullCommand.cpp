#include "stdafx.h"
#include "PullCommand.h"


PullCommand::PullCommand(const char& aThingToPull) : myThingToPull(aThingToPull)
{
}


PullCommand::~PullCommand(void)
{
}

void PullCommand::Execute(Player* aPlayer)
{
	if (MiniGameComponent* miniGamesComponent = aPlayer->GetMiniGameComponent())
	{
		if (BookCaseMiniGame* bookCaseMiniGames = miniGamesComponent->GetBookCaseMiniGame())
		{
			bookCaseMiniGames->RemoveBook(myThingToPull);
		}
	}
}