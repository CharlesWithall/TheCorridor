#pragma once
#include "command.h"
#include "ChandelierMiniGame.h"

class IgniteCommand : public Command
{
public:
	IgniteCommand(const int aCandleToIgnite);
	~IgniteCommand(void);
	void Execute(Player* aPlayer);
private:
	const int myCandleToIgnite;
};

