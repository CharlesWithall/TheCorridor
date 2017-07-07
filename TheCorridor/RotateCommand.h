#pragma once
#include "Command.h"

class RotateCommand : public Command
{
public:
	RotateCommand(const LeftRight& aDialToTurn);
	~RotateCommand(void);
	void Execute(Player* aPlayer);
private:
	const LeftRight myDial;
};

