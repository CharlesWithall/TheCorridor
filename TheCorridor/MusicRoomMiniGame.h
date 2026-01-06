#pragma once

#include "MiniGame.h"

class MusicRoomMiniGame : public MiniGame
{
public:
	MusicRoomMiniGame(const MiniGameID& aMiniGameID, Room* aRoom);
	~MusicRoomMiniGame();

	void PlayNote(const char& aNote);

	virtual bool IsPuzzleComplete() const override { return myPuzzleComplete; }

private:
	void ResetMelody();

	bool myPuzzleComplete;
	int myCurrentNoteIndex;
};
