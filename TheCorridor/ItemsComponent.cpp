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
