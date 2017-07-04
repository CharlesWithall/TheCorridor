#pragma once

#include "Room.h"
#include "World.h"

#include "ItemsComponent.h"
#include "MiniGameComponent.h"

class Player
{
public:
	Player(World* aWorld);
	~Player(void);
	Room* GetCurrentRoom() const { return myCurrentRoom; }
	void MoveTo(Room* aNewRoom);
	ItemsComponent* GetItemsComponent() const { return myItems; }
	MiniGameComponent* GetMiniGameComponent() const { return myMiniGames; }
private:
	World* myWorld;
	Room* myCurrentRoom;

	ItemsComponent* myItems;
	MiniGameComponent* myMiniGames;
};

