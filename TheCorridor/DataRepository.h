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

	std::string GetDialogueText(const DataType& aDataType, const int& anID, const Action& anAction = INVALID_ACTION, const Direction& aDirection = INVALID_DIRECTION) const;
	std::string GetNameByID(const DataType& aDataType, const int& anID) const;
	std::array<RoomID, DIRECTION_COUNT> GetAllAdjacentRooms(const RoomID& aRoomID) const;
	std::vector<RoomID> GetAllRoomIds() const;
	std::vector<ItemID> GetAllItemIds() const;
	std::vector<Item*> LoadAllItems() const;
	RoomID GetRoomIDByItemID(const ItemID& anItemID) const;
	ItemID GetItemIDByName(const std::string& anItemID) const;
	bool GetStartsLocked(const ItemID& anItemID) const;
	bool GetStartsUnusable(const ItemID& anItemID) const;

	StringList GetTutorialDialogue();
	StringList GetTitleArt();
private:
	DataRepository();	
	XMLElement* GetDataFromDataType(const DataType& aDataType) const;

	XMLElement* myRoomData;
	XMLElement* myItemData;

};

