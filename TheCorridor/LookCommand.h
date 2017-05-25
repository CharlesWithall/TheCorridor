#pragma once
#include "Command.h"

class LookCommand : public Command
{
public:
	LookCommand(Direction aDirection);
	~LookCommand(void);
	void Execute(Player* aPlayer);
private:
	const Direction myDirection;
};

