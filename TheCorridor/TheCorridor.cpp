// TheCorridor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include "InputHandler.h"
#include "Player.h"
#include "Room.h"
#include "UNIT_TEST_XmlParser.h"
#include "UNIT_TEST_DataRepository.h"
#include "World.h"
#include "XMLParser2.h"

void RunUnitTests();

int _tmain(int argc, _TCHAR* argv[])
{
	RunUnitTests();

	InputHandler inputHandler;
	std::string userInput;
	Command* currentCommand;

	World* world = new World();
	Player* player = new Player(world);

	std::cout << "Watcha wanna do?!" << std::endl;

	while (true)
	{
		std::getline(std::cin, userInput);
		currentCommand = inputHandler.HandleInput(player, userInput);

		if (currentCommand)
		{
			currentCommand->Execute(player);
			delete currentCommand;
		}		
	}
	
	delete player;
	delete world;

	return 0;
}

void RunUnitTests()
{
	std::vector<UNIT_TEST*> unitTests;

	UNIT_TEST_XmlParser* xmlParserUnitTest = new UNIT_TEST_XmlParser();
	UNIT_TEST_DataRepository* dataRepositoryUnitTest = new UNIT_TEST_DataRepository();

	unitTests.push_back(xmlParserUnitTest);
	unitTests.push_back(dataRepositoryUnitTest);

	for (UNIT_TEST* unitTest : unitTests)
	{
		unitTest->RunTest();
	}
}

