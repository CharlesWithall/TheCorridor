#include "stdafx.h"
#include "DataRepository.h"

DataRepository::DataRepository()
{
	XMLParser2 parser;
	myRoomData = parser.ParseRoomData();
	myItemData = parser.ParseItemData();
}


DataRepository::~DataRepository(void)
{
}

std::string DataRepository::GetDialogueText(const int& aRoomID, const Action& anAction, const Direction& aDirection ) const
{
	return myRoomData->GetDialogueText(aRoomID, anAction, aDirection);
}

void DataRepository::LoadAllRoomModels() const
{
	

	//return myRoomData->GetDialogueText(aRoomID, anAction, aDirection);
}

std::vector<Item*> DataRepository::LoadAllItems() const
{
	std::vector<Item*> items;

	for (XMLElement* element : myItemData->GetAllElementsWithAttribute(RoomIdentifier))
	{
		std::string itemName = element->GetAttributeByKey(Name);
		RoomID roomID = (RoomID)element->GetAttributeIDByKey(RoomIdentifier);
		ItemID itemID = (ItemID)element->GetAttributeIDByKey(Id);
		bool itemLocked = element->GetAttributeBoolByKey(ItemLocked);

		Item* newItem = new Item(itemName, itemID, roomID, itemLocked);
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