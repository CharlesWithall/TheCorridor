#include "stdafx.h"
#include "ItemsComponent.h"
#include "Player.h"


ItemsComponent::ItemsComponent(void)
{
}


ItemsComponent::~ItemsComponent(void)
{
}

void ItemsComponent::AddItemToInventory(Player* aPlayer, Item* anItem)
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
	
	PostItemAcquiredEvent(anItem->GetItemID(), aPlayer->GetCurrentRoom()->GetID());
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

void ItemsComponent::PostItemAcquiredEvent(const ItemID& anItemID, const RoomID& aRoomID)
{
	ItemAcquiredEvent* itemAcquiredEvent = new ItemAcquiredEvent(anItemID, aRoomID);
	Notify(itemAcquiredEvent);
	delete itemAcquiredEvent;
}