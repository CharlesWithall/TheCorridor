#include "stdafx.h"
#include "Item.h"


Item::Item(const std::string anItemName, const std::string anExamineDialogue, const std::string anAfterUseExamineDialogue, ItemID anItemID, const RoomID aRoomID, bool isLocked, bool isUsable) :
	myItemName(anItemName), myDefaultExamineDialogue(anExamineDialogue), myAfterUseExamineDialogue(anAfterUseExamineDialogue), myItemID(anItemID), myRoomID(aRoomID), myIsOwnedByPlayer(false), myIsLocked(isLocked), myIsUsable(isUsable)
{

}


Item::~Item(void)
{
}

void Item::SwitchDialogue()
{
	const std::string tempString = myDefaultExamineDialogue;
	myDefaultExamineDialogue = myAfterUseExamineDialogue;
	myAfterUseExamineDialogue = tempString;
}