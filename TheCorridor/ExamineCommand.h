#pragma once
#include "Command.h"

class ExamineCommand : public Command
{
public:
	ExamineCommand(const ItemID& anItemID);
	~ExamineCommand(void);
	void Execute(Player* aPlayer);
private:
	ItemID myItemID;
};

