#include "stdafx.h"
#include "DataRepository.h"
#include "Item.h"
#include "Room.h"

DataRepository::DataRepository()
{
	XMLParser2 xmlParser;
	myRoomData = xmlParser.ParseRoomData();
	myItemData = xmlParser.ParseItemData();
}

DataRepository::~DataRepository(void)
{
}

std::string DataRepository::GetDialogueText(const int& aRoomID, const Action& anAction, const Direction& aDirection ) const
{
	return myRoomData->GetDialogueText(aRoomID, anAction, aDirection);
}

std::vector<RoomID> DataRepository::GetAllRoomIds() const
{
	std::vector<RoomID> roomIds;
	std::vector<XMLElement*> roomData = myRoomData->GetAllElementsWithAttribute(Id);

	for (XMLElement* element : roomData)
	{
		const RoomID roomID = (RoomID)element->GetAttributeIDByKey(Id);
		roomIds.push_back(roomID);
	}

	return roomIds;
}

std::string DataRepository::GetRoomNameByID(const RoomID& aRoomID) const
{
	if (XMLElement* element = myRoomData->GetElementById(aRoomID))
	{
		return element->GetAttributeByKey(Name);
	}

	return std::string();
}

std::array<RoomID, 4> DataRepository::GetAllAdjacentRooms(const RoomID& aRoomID) const
{
	std::array<RoomID, 4> roomIDs;

	if (XMLElement* element = myRoomData->GetElementById(aRoomID))
	{
		roomIDs[NORTH] = (RoomID)element->GetAttributeIDByKey(North);
		roomIDs[EAST] = (RoomID)element->GetAttributeIDByKey(East);
		roomIDs[SOUTH] = (RoomID)element->GetAttributeIDByKey(South);
		roomIDs[WEST] = (RoomID)element->GetAttributeIDByKey(West);
	}

	return roomIDs;
}

std::vector<Item*> DataRepository::LoadAllItems() const
{
	std::vector<Item*> items;
	std::vector<XMLElement*> itemData = myItemData->GetAllElementsWithAttribute(RoomIdentifier);

	for (XMLElement* element : itemData)
	{
		std::string itemName = element->GetAttributeByKey(Name);
		std::string examineDialogue = element->GetAttributeByKey(Examine);
		RoomID roomID = (RoomID)element->GetAttributeIDByKey(RoomIdentifier);
		ItemID itemID = (ItemID)element->GetAttributeIDByKey(Id);
		bool itemLocked = element->GetAttributeBoolByKey(ItemLocked);
		bool itemIsUnusable = element->GetAttributeBoolByKey(StartsUnusable);

		Item* newItem = new Item(itemName, examineDialogue, itemID, roomID, itemLocked, !itemIsUnusable);
		items.push_back(newItem);
	}

	return items;
}

ItemID DataRepository::GetItemIDByName(const std::string& anItemName) const
{
	for (XMLElement* element : myItemData->GetAllElementsWithAttribute(Id))
	{
		if (element->GetAttributeByKey(Name) == anItemName)
		{
			return (ItemID)element->GetAttributeIDByKey(Id);
		}
	}

	return ITEM_INVALID;
}

StringList DataRepository::GetTitleArt()
{
	TxtParser txtParser;
	return txtParser.ParseTxtFile(TITLEART_FILEPATH);
}

StringList DataRepository::GetTutorialDialogue()
{
	TxtParser txtParser;
	return txtParser.ParseTxtFile(TUTORIAL_FILEPATH);
}