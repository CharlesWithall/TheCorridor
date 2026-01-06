#include "stdafx.h"
#include "MusicRoomMiniGame.h"

#include <cstring>

#define ITEM_REWARD_ID IVORY_KEY
#define CORRECT_MELODY "GAGECD"

MusicRoomMiniGame::MusicRoomMiniGame(const MiniGameID& aMiniGameID, Room* aRoom) : MiniGame(aMiniGameID, aRoom)
{
	myPuzzleComplete = false;
	myCurrentNoteIndex = 0;
}

MusicRoomMiniGame::~MusicRoomMiniGame()
{
}

void MusicRoomMiniGame::PlayNote(const char& aNote)
{
	const char noteToPlay = toupper(aNote);

	if (noteToPlay < 'A' || noteToPlay > 'G')
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_NOTE_STRING);
		return;
	}

	if (myPuzzleComplete)
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("You play a familiar bar of music. The hidden compartment in the PIANO remains open.");
		return;
	}

	std::string noteString;
	noteString += noteToPlay;
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You press the %s key and a soft note rings out.", noteString);

	if (noteToPlay == CORRECT_MELODY[myCurrentNoteIndex])
	{
		++myCurrentNoteIndex;

		if (myCurrentNoteIndex == strlen(CORRECT_MELODY))
		{
			myPuzzleComplete = true;
			if (myRoom->UnlockItem(ITEM_REWARD_ID))
			{
				PostMiniGameCompleteEvent();
				ServiceLocator::GetConsoleWriter().WriteStringToConsole("The melody echoes through the room. A secret compartment opens on the PIANO revealing an %s!", myRoom->GetItem(ITEM_REWARD_ID)->GetItemName());
				return;
			}
		}

		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The notes sound right. You continue the melody...");
	}
	else
	{
		ResetMelody();
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("A discordant clang interrupts the tune and the melody resets.");
	}
}

void MusicRoomMiniGame::ResetMelody()
{
	myCurrentNoteIndex = 0;
}
