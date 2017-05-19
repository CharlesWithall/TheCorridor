#pragma once

#include "ServiceLocator.h"
#include "Player.h"

class Command
{
public:
	virtual ~Command(void);
	virtual void Execute(Player* aPlayer) = 0;
};

