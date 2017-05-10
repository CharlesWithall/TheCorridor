#pragma once

#include "BaseRoom.h"
#include <assert.h>

class Room_CorridorOne : public BaseRoom
{
public:
	Room_CorridorOne(void)
	{
		assert(!myIsInstantiated);
		myIsInstantiated = true;
	}
	~Room_CorridorOne(void)
	{
		myIsInstantiated = false;
	}

	void Enter();
	void Exit();

private:
	static bool myIsInstantiated;
};

