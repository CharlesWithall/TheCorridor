#pragma once
#include "Command.h"

class TakeCommand : public Command
{
public:
	TakeCommand(const Direction& aDirection);
	~TakeCommand(void);
	void Execute(Player* aPlayer);
private:
	Direction myDirection;
};

