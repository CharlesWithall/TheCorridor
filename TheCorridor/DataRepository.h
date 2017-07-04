#pragma once

#include "Item.h"
#include "XMLParser2.h"
#include <string>

class DataRepository
{
	friend class ServiceLocator;

public:
	
	~DataRepository(void);

	std::string GetDialogueText(const int& aRoomID, const Action& anAction, const Direction& aDirection ) const;
	void LoadAllRoomModels() const;
	std::vector<Item*> LoadAllItems() const;
	ItemID GetItemIDByName(const std::string& anItemID) const;
private:
	DataRepository();

	XMLElement* myRoomData;
	XMLElement* myItemData;

};

