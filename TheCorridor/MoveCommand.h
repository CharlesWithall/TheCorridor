#pragma once
#include "command.h"
#include "ChessBoardMiniGame.h"

class MoveCommand : public Command
{
public:
	MoveCommand(const Direction aDirectionToStep);
	~MoveCommand(void);
	void Execute(Player* aPlayer);
private:
	const Direction myDirection;
};