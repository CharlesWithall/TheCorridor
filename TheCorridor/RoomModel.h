#pragma once

#include <string>

class RoomModel
{
public:
	RoomModel(void);
	~RoomModel(void);

private:
	RoomName myRoomName;

	Room* myNorthRoom;
	Room* myEastRoom;
	Room* myWestRoom;
	Room* mySouthRoom;

	std::string myEntryText;

	int xCoordinate;
	int yCoordinate;
};

