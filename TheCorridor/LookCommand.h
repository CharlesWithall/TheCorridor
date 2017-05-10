#pragma once
#include "Command.h"

class LookCommand : public Command
{
public:
	LookCommand(void);
	~LookCommand(void);
	void Execute() {}
};

