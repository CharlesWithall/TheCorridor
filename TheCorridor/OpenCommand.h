#pragma once
#include "command.h"

class OpenCommand : public Command
{
public:
	OpenCommand();
	~OpenCommand();
	void Execute(Player* aPlayer);
};

