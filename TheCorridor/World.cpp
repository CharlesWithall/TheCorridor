#include "stdafx.h"
#include "World.h"
#include <iostream>


World::World(void)
{
	Init();

	new ( myMap[CORRIDOR_ONE]	)	Room( myMap[CORRIDOR_TWO],		NULL,						NULL,						NULL,					CORRIDOR_ONE	);
	new ( myMap[CORRIDOR_TWO]	)	Room( myMap[CORRIDOR_THREE],	myMap[DRAWING_ROOM],		myMap[CORRIDOR_ONE],		NULL,					CORRIDOR_TWO	);
	new ( myMap[CORRIDOR_THREE] )	Room( myMap[CORRIDOR_FOUR],		NULL,						myMap[CORRIDOR_TWO],		myMap[LIBRARY],			CORRIDOR_THREE	);
	new ( myMap[CORRIDOR_FOUR]	)	Room( NULL,						myMap[WINERY],				myMap[CORRIDOR_THREE],		myMap[TREASURY],		CORRIDOR_FOUR	);
	new ( myMap[CORRIDOR_FIVE]	)	Room( myMap[CORRIDOR_SIX],		myMap[BATHROOM],			NULL,						myMap[PLAYROOM],		CORRIDOR_FIVE	);
	new ( myMap[CORRIDOR_SIX]	)	Room( myMap[CORRIDOR_SEVEN],	NULL,						myMap[CORRIDOR_FIVE],		NULL,					CORRIDOR_SIX	);
	new ( myMap[CORRIDOR_SEVEN] )	Room( NULL,						NULL,						myMap[CORRIDOR_SIX],		myMap[COURTYARD],		CORRIDOR_SEVEN	);
										  
	new ( myMap[DRAWING_ROOM]	)	Room( NULL,						NULL,						NULL,						myMap[CORRIDOR_TWO],	DRAWING_ROOM	);
	new ( myMap[LIBRARY]		)	Room( NULL,						myMap[CORRIDOR_THREE],		NULL,						myMap[SECRET_ROOM],		LIBRARY			);
	new ( myMap[SECRET_ROOM]	)	Room( NULL,						myMap[LIBRARY],				NULL,						NULL,					SECRET_ROOM		);
	new ( myMap[WINERY]			)	Room( myMap[BATHROOM],			NULL,						NULL,						myMap[CORRIDOR_FOUR],	WINERY			);
	new ( myMap[TREASURY]		)	Room( NULL,						myMap[CORRIDOR_FOUR],		NULL,						NULL,					TREASURY		);
	new ( myMap[BATHROOM]		)	Room( NULL,						NULL,						myMap[WINERY],				myMap[CORRIDOR_FIVE],	BATHROOM		);
	new ( myMap[PLAYROOM]		)	Room( NULL,						myMap[CORRIDOR_FIVE],		NULL,						NULL,					PLAYROOM		);
	new ( myMap[COURTYARD]		)	Room( NULL,						myMap[CORRIDOR_SEVEN],		NULL,						NULL,					COURTYARD		);
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

