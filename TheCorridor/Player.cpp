#include "stdafx.h"
#include "Player.h"


Player::Player(Room* aStartingLocation) : myCurrentRoom(aStartingLocation)
{

}


Player::~Player(void)
{
}

void Player::MoveTo(Room* aNewRoom)
{
	myCurrentRoom = aNewRoom;
}