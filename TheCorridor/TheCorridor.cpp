// TheCorridor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "InputHandler.h"
#include "Player.h"
#include "Room.h"
#include "World.h"


int _tmain(int argc, _TCHAR* argv[])
{
	InputHandler inputHandler;
	std::string userInput;	
	World* world = new World();
	Player* player = new Player(world->GetPlayerStartingPosition());
	Command* currentCommand;

	

	while (true)
	{
		std::getline(std::cin, userInput);
		currentCommand = inputHandler.HandleInput(userInput);
		
		if (currentCommand)
		{
			currentCommand->Execute(player);
		}		
	}

	delete currentCommand;
	
	return 0;
}

