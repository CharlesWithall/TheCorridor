#pragma once
#include "Command.h"

class TakeCommand : public Command
{
public:
	TakeCommand(void);
	~TakeCommand(void);
	void Execute() {}
};

