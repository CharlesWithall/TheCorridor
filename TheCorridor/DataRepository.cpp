#include "stdafx.h"
#include "DataRepository.h"
#include "Item.h"
#include "ItemBuilder.h"
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

std::string DataRepository::GetDialogueText( const DataType& aDataType, const int& anID, const Action& anAction, const Direction& aDirection ) const
{
	switch (aDataType)
	{
	case ITEM_DATA_TYPE:
		return myItemData->GetElementById(anID)->GetAttributeByKey(Examine);
	case ROOM_DATA_TYPE:
		return myRoomData->GetDialogueText(anID, anAction, aDirection);
	default:
		return std::string();
	}
	
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

std::string DataRepository::GetNameByID(const DataType& aDataType, const int& anID) const
{
	XMLElement* dataToSearch = GetDataFromDataType(aDataType);

	if (XMLElement* element = dataToSearch->GetElementById(anID))
	{
		return element->GetAttributeByKey(Name);
	}

	return std::string();
}

RoomID DataRepository::GetRoomIDByItemID(const ItemID& anItemID) const
{
	if (XMLElement* element = myItemData->GetElementById(anItemID))
		return (RoomID)element->GetAttributeIDByKey(RoomIdentifier);

	return INVALID_ROOM;
}

bool DataRepository::GetStartsLocked(const ItemID& anItemID) const
{
	if (XMLElement* element = myItemData->GetElementById(anItemID))
		return element->GetAttributeBoolByKey(ItemLocked);

	return false;
}

bool DataRepository::GetStartsUnusable(const ItemID& anItemID) const
{
	if (XMLElement* element = myItemData->GetElementById(anItemID))
		return element->GetAttributeBoolByKey(StartsUnusable);

	return false;
}

std::array<RoomID, 4> DataRepository::GetAllAdjacentRooms(const RoomID& aRoomID) const
{
	std::array<RoomID, 4> roomIDs;
	roomIDs.fill(INVALID_ROOM);

	if (XMLElement* element = myRoomData->GetElementById(aRoomID))
	{
		roomIDs[NORTH] = element->GetAttributeIDByKey(North) >= 0 ? (RoomID)element->GetAttributeIDByKey(North) : INVALID_ROOM;
		roomIDs[EAST] = element->GetAttributeIDByKey(East) >= 0 ? (RoomID)element->GetAttributeIDByKey(East) : INVALID_ROOM;
		roomIDs[SOUTH] = element->GetAttributeIDByKey(South) >= 0 ? (RoomID)element->GetAttributeIDByKey(South) : INVALID_ROOM;
		roomIDs[WEST] = element->GetAttributeIDByKey(West) >= 0 ? (RoomID)element->GetAttributeIDByKey(West) : INVALID_ROOM;
	}

	return roomIDs;
}


std::vector<ItemID> DataRepository::GetAllItemIds() const
{
	std::vector<ItemID> itemIds;
	std::vector<XMLElement*> itemData = myItemData->GetAllElementsWithAttribute(Id);

	for (XMLElement* element : itemData)
	{
		const ItemID itemID = (ItemID)element->GetAttributeIDByKey(Id);
		itemIds.push_back(itemID);
	}

	return itemIds;
}

std::vector<Item*> DataRepository::LoadAllItems() const
{
	std::vector<Item*> items;
	std::vector<XMLElement*> itemData = myItemData->GetAllElementsWithAttribute(RoomIdentifier);

	for (XMLElement* element : itemData)
	{
		ItemBuilder itemBuilder;
		itemBuilder.setItemName(element->GetAttributeByKey(Name))
					.setExamineDialogue(element->GetAttributeByKey(Examine))
					.setAfterUseExamineDialogue(element->GetAttributeByKey(PostExamine))
					.setRoomID((RoomID)element->GetAttributeIDByKey(RoomIdentifier))
					.setItemID((ItemID)element->GetAttributeIDByKey(Id))
					.setIsLocked(element->GetAttributeBoolByKey(ItemLocked))
					.setIsUsable(!element->GetAttributeBoolByKey(StartsUnusable));

		items.push_back(itemBuilder.Build());
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

XMLElement* DataRepository::GetDataFromDataType(const DataType& aDataType) const
{
	switch (aDataType)
	{
	case ITEM_DATA_TYPE:
		return myItemData;
	case ROOM_DATA_TYPE:
		return myRoomData;
	default:
		throw ("Invalid Data Type Selected");
	}
}