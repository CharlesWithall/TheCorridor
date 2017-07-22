#include "stdafx.h"
#include "UseCommand.h"


UseCommand::UseCommand(const ItemID& anItemToUse) : myItemToUse(anItemToUse)
{

}


UseCommand::~UseCommand()
{
}

void UseCommand::Execute(Player* aPlayer)
{
	const RoomID currentRoomID = aPlayer->GetCurrentRoom()->GetID();

	if (aPlayer->GetItemsComponent()->GetItem(myItemToUse))
	{
		if (TryUnlockFont(aPlayer, currentRoomID))
			return;

		if (TryPutOutFireplace(aPlayer, currentRoomID))
			return;
	}

	ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_USE);
}

bool UseCommand::TryUnlockFont(Player* aPlayer, const RoomID& aCurrentRoomID)
{
	if (aCurrentRoomID == COURTYARD)
	{
		switch (myItemToUse)
		{
		case GOULAINE:
			if (aPlayer->GetCurrentRoom()->GetItem(PURPLE_KEY)->IsLocked())
			{
				aPlayer->GetCurrentRoom()->GetItem(PURPLE_KEY)->Unlock();
				ServiceLocator::GetConsoleWriter().WriteStringToConsole("As you pour the wine into the FONT, it rumbles slightly. A stone hatch at the bottom opens revealing a PURPLE KEY!");
			}
			else
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole("The PURPLE KEY has been revealed. The wine is resting gently in the font.");
			}
			break;
		case RICASOLI:
		case CODORNIU:
			ServiceLocator::GetConsoleWriter().WriteStringToConsole("You pour the wine into the font; it immediately drains away.");
			break;
		}	

		return true;
	}

	return false;
}

bool UseCommand::TryPutOutFireplace(Player* aPlayer, const RoomID& aCurrentRoomID)
{
	if (aCurrentRoomID == DRAWING_ROOM && myItemToUse == BUCKET)
	{
		if (const Item* item = aPlayer->GetItemsComponent()->GetItem(myItemToUse))
		{
			if (item->IsUsable())
			{
				if (aPlayer->GetCurrentRoom()->GetItem(BLUE_KEY)->IsLocked())
				{
					aPlayer->GetCurrentRoom()->GetItem(BLUE_KEY)->Unlock();
					ServiceLocator::GetConsoleWriter().WriteStringToConsole("You pour the water on the FIREPLACE, putting out the flames and revealing the BLUE KEY!");
				}
				else
				{
					ServiceLocator::GetConsoleWriter().WriteStringToConsole("The flames have already died down, the BLUE KEY is yours for the taking");
				}
			}
			else
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole("You need to fill your bucket with water first");
			}

			return true;
		}
	}

	return false;
}
