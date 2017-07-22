#pragma once

#include "Room.h"
#include "World.h"

#include "AchievementComponent.h"
#include "ItemsComponent.h"
#include "MiniGameComponent.h"

class Player
{
public:
	Player(World* aWorld);
	~Player(void);
	Room* GetCurrentRoom() const { return myCurrentRoom; }
	int GetNumberOfKeysAcquired() const;
	void MoveTo(Room* aNewRoom);
	void CompleteGame() { hasCompletedGame = true; }
	bool HasCompletedGame() { return hasCompletedGame; }

	AchievementComponent* GetAchivementComponent() const { return myAchievements; }
	ItemsComponent* GetItemsComponent() const { return myItems; }
	MiniGameComponent* GetMiniGameComponent() const { return myMiniGames; }
private:
	void RegisterListeners();

	bool hasCompletedGame;

	World* myWorld;
	Room* myCurrentRoom;

	AchievementComponent* myAchievements;
	ItemsComponent* myItems;
	MiniGameComponent* myMiniGames;
};

