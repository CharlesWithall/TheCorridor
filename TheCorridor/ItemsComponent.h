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
private:
	std::vector<Item*> myInventory;
};

