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
	Item* fragmentedItem = nullptr;

	for (Item* inventoryItem : myInventory)
	{
		if (anItem->GetItemName() == inventoryItem->GetItemName())
		{
			fragmentedItem = inventoryItem;
		}
	}
	
	if (fragmentedItem)
	{
		fragmentedItem->CombineItems(anItem->GetDialogue());
	}
	else
	{
		myInventory.push_back(anItem);
	}
	
	PostItemAcquiredEvent(anItem->GetItemID());
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

void ItemsComponent::Notify(const Event* const anEvent)
{
	for (IObserver* observer : myObservers)
	{
		observer->OnNotify(anEvent);
	}
}

void ItemsComponent::PostItemAcquiredEvent(const ItemID& anItemID)
{
	ItemAcquiredEvent* itemAcquiredEvent = new ItemAcquiredEvent(anItemID);
	Notify(itemAcquiredEvent);
	delete itemAcquiredEvent;
}