#pragma once
#include "Command.h"

class InvestigateCommand : public Command
{
public:
	InvestigateCommand(void);
	~InvestigateCommand(void);
	void Execute() {}
};

