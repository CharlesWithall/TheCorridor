#pragma once

#include "MiniGame.h"
#include "World.h"

class BookCaseMiniGame : public MiniGame
{
public:
	BookCaseMiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~BookCaseMiniGame();

	void RemoveBook(const char& bookToRemove);
	void UnlockSecretRoom(); // Maybe send an event? AddRoomToWorldEvent

	virtual bool IsPuzzleComplete() const override { return myBookCaseIsOpen; }

private:
	
	bool myBookCaseIsOpen;
	char myFirstSelectedBook;
};

