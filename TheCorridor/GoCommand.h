#pragma once
#include "Command.h"

class GoCommand : public Command
{
public:
	GoCommand(const Direction& aDirection);
	~GoCommand(void);
	void Execute(Player* aPlayer);
private:
	const Direction myDirection;
};

