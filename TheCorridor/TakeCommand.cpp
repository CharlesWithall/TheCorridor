#include "stdafx.h"
#include "TakeCommand.h"


TakeCommand::TakeCommand(const ItemID& anItemID) : myItemID(anItemID)
{

}


TakeCommand::~TakeCommand(void)
{
}

void TakeCommand::Execute(Player* aPlayer)
{
	Item* takenItem = aPlayer->GetCurrentRoom()->GetItem(myItemID);

	if (takenItem && !takenItem->IsLocked())
	{
		if (takenItem->IsOwnedByPlayer())
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_ALREADY_OWNED_STRING);
		}
		else if (ItemsComponent* itemsComponent = aPlayer->GetItemsComponent())
		{
			itemsComponent->AddItemToInventory(aPlayer, takenItem);
		}
	}
	else
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_PICKUP_STRING);
	}
}
