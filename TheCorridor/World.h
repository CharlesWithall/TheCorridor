#pragma once

#include <array>
#include "Room.h"

#define MAX_WORLD_SIZE 16

#define CORRIDOR_ONE 0
#define CORRIDOR_TWO 1
#define CORRIDOR_THREE 2
#define CORRIDOR_FOUR 3
#define CORRIDOR_FIVE 4
#define CORRIDOR_SIX 5
#define CORRIDOR_SEVEN 6
#define DRAWING_ROOM 7
#define LIBRARY 8
#define SECRET_ROOM 9
#define TREASURY 10
#define WINERY 11
#define BATHROOM 12
#define PLAYROOM 13
#define COURTYARD 14

class World
{
public:
	World();
	~World();
	Room* GetPlayerStartingPosition();
	
private:
	void Init();

	Room** myMap;
	Room* myCorridorOne;
	Room* myCorridorTwo;
	Room* myCorridorThree;
	Room* myCorridorFour;
	Room* myCorridorFive;
	Room* myCorridorSix;
	Room* myCorridorSeven;

	Room* myDrawingRoom;
	Room* myLibrary;
	Room* mySecretRoom;
	Room* myTreasury;
	Room* myWinery;
	Room* myBathroom;
	Room* myPlayroom;
	Room* myCourtyard;
};

