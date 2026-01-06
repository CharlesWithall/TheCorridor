#include "stdafx.h"
#include "PlayCommand.h"

#include "MusicRoomMiniGame.h"

PlayCommand::PlayCommand(const char& aNoteToPlay) : myNoteToPlay(aNoteToPlay)
{
}

PlayCommand::~PlayCommand(void)
{
}

void PlayCommand::Execute(Player* aPlayer)
{
	if (MiniGameComponent* miniGamesComponent = aPlayer->GetMiniGameComponent())
	{
		if (MusicRoomMiniGame* musicRoomMiniGame = miniGamesComponent->GetMusicRoomMiniGame())
		{
			musicRoomMiniGame->PlayNote(myNoteToPlay);
			return;
		}
	}

	ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_COMMAND_STRING);
}
