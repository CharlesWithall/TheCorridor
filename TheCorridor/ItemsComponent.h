#pragma once

#include "IObserver.h"
#include "Item.h"
#include "ItemAcquiredEvent.h"
#include "Notifier.h"
#include "ServiceLocator.h"
#include <vector>

class Player;

class ItemsComponent : public Notifier
{
public:
	ItemsComponent(void);
	~ItemsComponent(void);

	virtual void Notify(const Event* const anEvent) override;

	void AddItemToInventory(Player* aPlayer, Item* anItem);
	std::vector<Item*> GetInventory() const { return myInventory; }
	const Item* GetItem(const ItemID& anItemID);
private:
	void PostItemAcquiredEvent(const ItemID& anItemID, const RoomID& aRoomID);
	std::vector<Item*> myInventory;
};

