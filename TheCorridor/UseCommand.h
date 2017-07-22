#pragma once
#include "command.h"

class UseCommand : public Command
{
public:
	UseCommand(const ItemID& anItemToUse);
	~UseCommand(void);
	void Execute(Player* aPlayer);
private:
	bool TryUnlockFont(Player* aPlayer, const RoomID& aCurrentRoomID);
	bool TryPutOutFireplace(Player* aPlayer, const RoomID& aCurrentRoomID);

	const ItemID myItemToUse;
};

