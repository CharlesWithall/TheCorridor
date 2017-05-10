#pragma once
#include "Command.h"

class GoCommand : public Command
{
public:
	GoCommand(void);
	~GoCommand(void);
	void Execute() {}
};

