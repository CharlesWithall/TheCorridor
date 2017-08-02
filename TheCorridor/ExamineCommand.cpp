#include "stdafx.h"
#include "ExamineCommand.h"


ExamineCommand::ExamineCommand(const ItemID& anItemID) : myItemID(anItemID)
{
}


ExamineCommand::~ExamineCommand(void)
{
}

void ExamineCommand::Execute(Player* aPlayer)
{
	// Check if item is in the current room
	if (Room* currentRoom = aPlayer->GetCurrentRoom())
	{
		if (const Item* itemToExamine = currentRoom->GetItem(myItemID))
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(itemToExamine->GetDialogue());
			return;
		}
	}

	// Check if item is in the player's inventory
	if (ItemsComponent* itemsComponent = aPlayer->GetItemsComponent())
	{
		if (const Item* itemToExamine = itemsComponent->GetItem(myItemID))
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(itemToExamine->GetDialogue());
			return;
		}
	}
	
	// Otherwise - can't find item
	ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_STRING);
}