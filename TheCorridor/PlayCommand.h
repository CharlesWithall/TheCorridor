#pragma once

#include "Command.h"

class PlayCommand : public Command
{
public:
	PlayCommand(const char& aNoteToPlay);
	~PlayCommand(void);

	void Execute(Player* aPlayer);

private:
	char myNoteToPlay;
};
