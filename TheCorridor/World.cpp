#include "stdafx.h"
#include "World.h"
#include <iostream>


World::World(void)
{
	//Init()
	void * raw_memory = operator new(sizeof(Room) * MAX_WORLD_SIZE);
	myMap = static_cast<Room**>(raw_memory);

	new ( &myMap[CORRIDOR_ONE] )	Room("You are in the corridor",			myMap[CORRIDOR_TWO],		NULL,						NULL,						NULL);
	new ( &myMap[CORRIDOR_TWO] )	Room("You are in the corridor",			myMap[CORRIDOR_THREE],		NULL,						myMap[CORRIDOR_ONE],		NULL);
	new ( &myMap[CORRIDOR_THREE] )	Room("You are in the corridor",			myMap[CORRIDOR_FOUR],		NULL,						myMap[CORRIDOR_TWO],		myMap[LIBRARY]);
	new ( &myMap[CORRIDOR_FOUR] )	Room("You are in the corridor",			NULL,						myMap[WINERY],				myMap[CORRIDOR_THREE],		myMap[TREASURY]);
	new ( &myMap[CORRIDOR_FIVE] )	Room("You are in the corridor",			myMap[CORRIDOR_SIX],		myMap[BATHROOM],			NULL,						myMap[PLAYROOM]);
	new ( &myMap[CORRIDOR_SIX] )	Room("You are in the corridor",			myMap[CORRIDOR_SEVEN],		NULL,						myMap[CORRIDOR_FIVE],		NULL);
	new ( &myMap[CORRIDOR_SEVEN] )	Room("You are in the corridor",			NULL,						NULL,						myMap[CORRIDOR_SIX],		myMap[COURTYARD]);

	for (int i = 0; i < 7; ++i)
	{
		std::cout << myMap[i]->myEntryText << std::endl;
	}

	/*myMap[DRAWING_ROOM] = new Room("You are in the drawing room",		NULL,						NULL,						NULL,						myMap[CORRIDOR_TWO]);
	myMap[LIBRARY] = new Room("You are in the library",					NULL,						myMap[CORRIDOR_THREE],		NULL,						myMap[SECRET_ROOM]);
	myMap[SECRET_ROOM] = new Room("You are in the secret room",			NULL,						myMap[LIBRARY],				NULL,						NULL);
	myMap[WINERY] = new Room("You are in the winery",					myMap[BATHROOM],			NULL,						NULL,						myMap[CORRIDOR_FOUR]);
	myMap[TREASURY] = new Room("You are in the treasury",				NULL,						myMap[CORRIDOR_FOUR],		NULL,						NULL);
	myMap[BATHROOM] = new Room("You are in the bathroom",				NULL,						NULL,						myMap[WINERY],				myMap[CORRIDOR_FIVE]);
	myMap[PLAYROOM] = new Room("You are in the playroom",				NULL,						myMap[CORRIDOR_FIVE],		NULL,						NULL);
	myMap[COURTYARD] = new Room("You are in the courtyard",				NULL,						myMap[CORRIDOR_SEVEN],		NULL,						NULL);*/

	/*myCorridorOne = new (myCorridorOne) Room("You are in the corridor",		myCorridorTwo,		NULL,				NULL,				NULL);
	myCorridorTwo = new (myCorridorTwo) Room("You are in the corridor",		myCorridorThree,	myDrawingRoom,		myCorridorOne,		NULL);
	myCorridorThree = new (myCorridorThree) Room("You are in the corridor", myCorridorFour,		NULL,				myCorridorTwo,		myLibrary);
	myCorridorFour = new (myCorridorFour) Room("You are in the corridor",	NULL,				myWinery,			myCorridorThree,	myTreasury);
	myCorridorFive = new (myCorridorFive) Room("You are in the corridor",	myCorridorSix,		myBathroom,			NULL,				myPlayroom);
	myCorridorSix = new (myCorridorSix) Room("You are in the corridor",		myCorridorSeven,	NULL,				myCorridorFive,		NULL);
	myCorridorSeven = new (myCorridorSeven) Room("You are in the corridor", NULL,				NULL,				myCorridorSix,		myCourtyard);

	myDrawingRoom = new (myDrawingRoom) Room("You are in the drawing room", NULL,				NULL,				NULL,				myCorridorTwo);
	myLibrary = new (myLibrary) Room("You are in the library",				NULL,				myCorridorThree,	NULL,				mySecretRoom);
	mySecretRoom = new (mySecretRoom) Room("You are in the secret room",	NULL,				myLibrary,			NULL,				NULL);
	myWinery = new (myWinery) Room("You are in the winery",					myBathroom,			NULL,				NULL,				myCorridorFour);
	myTreasury = new (myTreasury) Room("You are in the treasury",			NULL,				myCorridorFour,		NULL,				NULL);
	myBathroom = new (myBathroom) Room("You are in the bathroom",			NULL,				NULL,				myWinery,			myCorridorFive);
	myPlayroom = new (myPlayroom) Room("You are in the playroom",			NULL,				myCorridorFive,		NULL,				NULL);
	myCourtyard = new (myCourtyard) Room("You are in the courtyard",		NULL,				myCorridorSeven,	NULL,				NULL);*/
}


World::~World(void)
{
	delete[] myMap;
}

void World::Init()
{
	/*myCorridorOne = (Room*) ::operator new(sizeof(Room));
	myCorridorTwo = (Room*) ::operator new(sizeof(Room));
	myCorridorThree = (Room*) ::operator new(sizeof(Room));
	myCorridorFour = (Room*) ::operator new(sizeof(Room));
	myCorridorFive = (Room*) ::operator new(sizeof(Room));
	myCorridorSix = (Room*) ::operator new(sizeof(Room));
	myCorridorSeven = (Room*) ::operator new(sizeof(Room));

	myDrawingRoom = (Room*) ::operator new(sizeof(Room));
	myLibrary = (Room*) ::operator new(sizeof(Room));
	mySecretRoom = (Room*) ::operator new(sizeof(Room));
	myWinery = (Room*) ::operator new(sizeof(Room));
	myTreasury = (Room*) ::operator new(sizeof(Room));
	myBathroom = (Room*) ::operator new(sizeof(Room));
	myPlayroom = (Room*) ::operator new(sizeof(Room));
	myCourtyard = (Room*) ::operator new(sizeof(Room));*/
}

Room* World::GetPlayerStartingPosition()
{
	return myMap[CORRIDOR_ONE];
}

