#include "stdafx.h"
#include "Player.h"


Player::Player(World* aWorld) : myWorld(aWorld), myCurrentRoom(aWorld->GetPlayerStartingPosition())
{
	myMiniGames = new MiniGameComponent(aWorld);
	myItems = new ItemsComponent();
}

Player::~Player(void)
{
	delete myMiniGames;
}

void Player::MoveTo(Room* aNewRoom)
{
	myCurrentRoom = aNewRoom;
}