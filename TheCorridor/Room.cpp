#include "stdafx.h"
#include "Room.h"

Room::Room(std::string anEntryText, Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom) : myEntryText(anEntryText)
{
	myAdjacentRooms[NORTH] = aNorthRoom;
	myAdjacentRooms[WEST] = aWestRoom;
	myAdjacentRooms[SOUTH] = aSouthRoom;
	myAdjacentRooms[EAST] = anEastRoom;
}

Room::~Room(void)
{
}

void Room::Enter()
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myEntryText);
}

void Room::Exit()
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myEntryText);
}

Room* Room::GetAdjacentRoom(Direction aDirection)
{
	return myAdjacentRooms[aDirection];
}
