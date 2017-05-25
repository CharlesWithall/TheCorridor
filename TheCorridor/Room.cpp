#include "stdafx.h"
#include "Room.h"

Room::Room(Room* aNorthRoom, Room* aWestRoom, Room* aSouthRoom, Room* anEastRoom, const int& roomID) : myRoomId(roomID)
{
	Init();

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
	//ServiceLocator::GetConsoleWriter().WriteStringToConsole(myEntryText);
}

void Room::Exit(const Direction& aDirection)
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myGoDialogue[aDirection]);
}

void Room::Init()
{
	XMLParser& data = ServiceLocator::GetData();
	Definitions& definer = ServiceLocator::GetDefinitions();
	std::string roomString = definer.GetStringForRoom(myRoomId);

	std::string lookString = definer.GetStringForAction(LOOK);
	
	myLookDialogue[NORTH] = data.GetDialogueText(roomString, lookString, definer.GetStringForDirection(NORTH));
	myLookDialogue[EAST] = data.GetDialogueText(roomString, lookString, definer.GetStringForDirection(EAST));
	myLookDialogue[SOUTH] = data.GetDialogueText(roomString, lookString, definer.GetStringForDirection(SOUTH));
	myLookDialogue[WEST] = data.GetDialogueText(roomString, lookString, definer.GetStringForDirection(WEST));

	std::string goString = definer.GetStringForAction(GO);

	myGoDialogue[NORTH] = data.GetDialogueText(roomString, goString, definer.GetStringForDirection(NORTH));
	myGoDialogue[EAST] = data.GetDialogueText(roomString, goString, definer.GetStringForDirection(EAST));
	myGoDialogue[SOUTH] = data.GetDialogueText(roomString, goString, definer.GetStringForDirection(SOUTH));
	myGoDialogue[WEST] = data.GetDialogueText(roomString, goString, definer.GetStringForDirection(WEST));
}

void Room::Look(const Direction& aDirection)
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(myLookDialogue[aDirection]);
}

Room* Room::GetAdjacentRoom(const Direction& aDirection)
{
	return myAdjacentRooms[aDirection];
}
