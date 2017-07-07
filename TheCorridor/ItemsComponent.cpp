#include "stdafx.h"
#include "ItemsComponent.h"


ItemsComponent::ItemsComponent(void)
{
}


ItemsComponent::~ItemsComponent(void)
{
}

void ItemsComponent::AddItemToInventory(Item* anItem)
{
	myInventory.push_back(anItem);
	anItem->Pickup();
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You picked up the %s", anItem->GetItemName());
}

const Item* ItemsComponent::GetItem(const ItemID& anItemID)
{
	for (Item* item : myInventory)
	{
		if (item->GetItemID() == anItemID)
		{
			return item;
		}
	}

	return nullptr;
}