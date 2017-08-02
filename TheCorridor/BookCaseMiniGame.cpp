#include "stdafx.h"
#include "BookCaseMiniGame.h"

#define CORRECT_BOOK_SELECTION_ONE 'N'
#define CORRECT_BOOK_SELECTION_TWO 'Y'

BookCaseMiniGame::BookCaseMiniGame(const MiniGameID& aMiniGameID, Room* aRoom) : MiniGame(aMiniGameID, aRoom)
{
}

BookCaseMiniGame::~BookCaseMiniGame()
{
}

void BookCaseMiniGame::RemoveBook(const char& bookToRemove)
{
	if (!myFirstSelectedBook)
	{
		myFirstSelectedBook = bookToRemove;
		std::string bookTitle = std::string() += bookToRemove;
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("You pull out book %s slightly", bookTitle);
		return;
	}

	if (myFirstSelectedBook == CORRECT_BOOK_SELECTION_ONE || myFirstSelectedBook == CORRECT_BOOK_SELECTION_TWO)
	{
		if ((bookToRemove == CORRECT_BOOK_SELECTION_ONE || bookToRemove == CORRECT_BOOK_SELECTION_TWO) && bookToRemove != myFirstSelectedBook)
		{
			PostMiniGameCompleteEvent();
			myRoom->GetItem(BOOKCASE)->SwitchDialogue();
			ServiceLocator::GetConsoleWriter().WriteStringToConsole("You pull out the second book and hear a click. The bookcase slides aside to reveal a Secret Room!");
			myBookCaseIsOpen = true;
			return;
		}
	}

	myFirstSelectedBook = NULL;
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("Both books mysteriously withdraw themselves back into the BOOKCASE");	
}