#pragma once

#include "XMLParser2.h"
#include "TxtParser.h"
#include <array>
#include <string>

class Item;
class Room;

#define TUTORIAL_FILEPATH "..\\Data\\Tutorial.txt"
#define TITLEART_FILEPATH "..\\Data\\Title.txt"

class DataRepository
{
	friend class ServiceLocator;

public:
	
	~DataRepository(void);

	std::string GetDialogueText(const int& aRoomID, const Action& anAction, const Direction& aDirection ) const;
	std::string GetRoomNameByID(const RoomID& aRoomID) const;
	std::array<RoomID, DIRECTION_COUNT> GetAllAdjacentRooms(const RoomID& aRoomID) const;
	std::vector<RoomID> GetAllRoomIds() const;
	std::vector<Item*> LoadAllItems() const;
	ItemID GetItemIDByName(const std::string& anItemID) const;
	StringList GetTutorialDialogue();
	StringList GetTitleArt();
private:
	DataRepository();

	XMLElement* myRoomData;
	XMLElement* myItemData;

};

