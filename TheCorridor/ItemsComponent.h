#pragma once

#include "Item.h"
#include "ServiceLocator.h"
#include <vector>

class ItemsComponent
{
public:
	ItemsComponent(void);
	~ItemsComponent(void);
	void AddItemToInventory(Item* anItem);
	const Item* GetItem(const ItemID& anItemID);
private:
	std::vector<Item*> myInventory;
};

