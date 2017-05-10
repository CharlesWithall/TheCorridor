#pragma once

class Command
{
public:
	virtual ~Command(void);
	virtual void Execute() = 0;
};

