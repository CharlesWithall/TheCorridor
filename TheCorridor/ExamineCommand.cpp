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
	if (ItemsComponent* itemsComponent = aPlayer->GetItemsComponent())
	{
		if (const Item* itemToExamine = itemsComponent->GetItem(myItemID))
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(itemToExamine->GetDialogue());
			return;
		}
	}
	
	if (Room* currentRoom = aPlayer->GetCurrentRoom())
	{
		if (const Item* itemToExamine = currentRoom->GetItem(myItemID))
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(itemToExamine->GetDialogue());
			return;
		}
	}
}