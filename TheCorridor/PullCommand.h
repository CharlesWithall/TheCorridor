#pragma once
#include "Command.h"

class PullCommand : public Command
{
public:
	PullCommand(const char& aThingToPull);
	~PullCommand(void);
	void Execute(Player* aPlayer);
private:
	const char myThingToPull;
};

