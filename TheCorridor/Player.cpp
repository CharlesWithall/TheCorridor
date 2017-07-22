#include "stdafx.h"
#include "Player.h"

Player::Player(World* aWorld) : myWorld(aWorld), myCurrentRoom(aWorld->GetPlayerStartingPosition()), hasCompletedGame(false)
{
	myAchievements = new AchievementComponent(this);
	myMiniGames = new MiniGameComponent(aWorld);
	myItems = new ItemsComponent();

	RegisterListeners();

	myCurrentRoom->Enter();
}

Player::~Player(void)
{
	delete myMiniGames;
}

void Player::MoveTo(Room* aNewRoom)
{
	myCurrentRoom = aNewRoom;
}

void Player::RegisterListeners()
{
	for (MiniGame* miniGame : myMiniGames->myMiniGames)
	{
		myAchievements->RegisterAsListener(miniGame);
		myWorld->RegisterAsListener(miniGame);
	}

	myAchievements->RegisterAsListener(myItems);
}

int Player::GetNumberOfKeysAcquired() const
{
	int numberOfKeys = 0;
	ItemID keys[TOTAL_NUMBER_OF_KEYS] = { BLUE_KEY, GREEN_KEY, PURPLE_KEY, RED_KEY, YELLOW_KEY };

	for (int i = 0; i < TOTAL_NUMBER_OF_KEYS; ++i)
	{
		if (myItems->GetItem(keys[i]))
		{
			++numberOfKeys;
		}
	}

	return numberOfKeys;
}