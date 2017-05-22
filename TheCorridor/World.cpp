#include "stdafx.h"
#include "World.h"
#include <iostream>


World::World(void)
{
	Init();

	new ( myMap[CORRIDOR_ONE]	)	Room("You are in the corridor",			myMap[CORRIDOR_TWO],		NULL,						NULL,						NULL);
	new ( myMap[CORRIDOR_TWO]	)	Room("You are in the corridor",			myMap[CORRIDOR_THREE],		myMap[DRAWING_ROOM],		myMap[CORRIDOR_ONE],		NULL);
	new ( myMap[CORRIDOR_THREE] )	Room("You are in the corridor",			myMap[CORRIDOR_FOUR],		NULL,						myMap[CORRIDOR_TWO],		myMap[LIBRARY]);
	new ( myMap[CORRIDOR_FOUR]	)	Room("You are in the corridor",			NULL,						myMap[WINERY],				myMap[CORRIDOR_THREE],		myMap[TREASURY]);
	new ( myMap[CORRIDOR_FIVE]	)	Room("You are in the corridor",			myMap[CORRIDOR_SIX],		myMap[BATHROOM],			NULL,						myMap[PLAYROOM]);
	new ( myMap[CORRIDOR_SIX]	)	Room("You are in the corridor",			myMap[CORRIDOR_SEVEN],		NULL,						myMap[CORRIDOR_FIVE],		NULL);
	new ( myMap[CORRIDOR_SEVEN] )	Room("You are in the corridor",			NULL,						NULL,						myMap[CORRIDOR_SIX],		myMap[COURTYARD]);

	new ( myMap[DRAWING_ROOM]	)	Room("You are in the drawing room",		NULL,						NULL,						NULL,						myMap[CORRIDOR_TWO]);
	new ( myMap[LIBRARY]		)	Room("You are in the library",			NULL,						myMap[CORRIDOR_THREE],		NULL,						myMap[SECRET_ROOM]);
	new ( myMap[SECRET_ROOM]	)	Room("You are in the secret room",		NULL,						myMap[LIBRARY],				NULL,						NULL);
	new ( myMap[WINERY]			)	Room("You are in the winery",			myMap[BATHROOM],			NULL,						NULL,						myMap[CORRIDOR_FOUR]);
	new ( myMap[TREASURY]		)	Room("You are in the treasury",			NULL,						myMap[CORRIDOR_FOUR],		NULL,						NULL);
	new ( myMap[BATHROOM]		)	Room("You are in the bathroom",			NULL,						NULL,						myMap[WINERY],				myMap[CORRIDOR_FIVE]);
	new ( myMap[PLAYROOM]		)	Room("You are in the playroom",			NULL,						myMap[CORRIDOR_FIVE],		NULL,						NULL);
	new ( myMap[COURTYARD]		)	Room("You are in the courtyard",		NULL,						myMap[CORRIDOR_SEVEN],		NULL,						NULL);
}


World::~World(void)
{
	for (int i = 0; i < MAX_WORLD_SIZE; ++i)
	{
		delete myMap[i];
	}

	delete[] myMap;
}

void World::Init()
{
	myMap = new Room*[MAX_WORLD_SIZE];

	for (int i = 0; i < MAX_WORLD_SIZE; ++i)
	{
		myMap[i] = (Room*) operator new(sizeof(Room));
	}
}

Room* World::GetPlayerStartingPosition()
{
	return myMap[CORRIDOR_ONE];
}

