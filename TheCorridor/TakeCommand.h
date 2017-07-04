#pragma once
#include "Command.h"

class TakeCommand : public Command
{
public:
	TakeCommand(const ItemID& anItemID);
	~TakeCommand(void);
	void Execute(Player* aPlayer);
private:
	const ItemID myItemID;
};

