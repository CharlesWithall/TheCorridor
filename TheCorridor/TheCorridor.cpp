// TheCorridor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
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

void EndGame();
void RunUnitTests();
void SetConsoleWindowSize();
void WriteTitleArt();
void WriteTutorial();

int _tmain(int argc, _TCHAR* argv[])
{
	RunUnitTests();
	SetConsoleWindowSize();

	InputHandler inputHandler;
	std::string userInput;

	Command* currentCommand = nullptr;
	World* world = new World();
	Player* player = new Player(world);

	WriteTitleArt();
	WriteTutorial();

	while (!player->HasCompletedGame())
	{
		std::getline(std::cin, userInput);
		currentCommand = inputHandler.HandleInput(player, userInput);

		if (currentCommand)
		{
			currentCommand->Execute(player);
		}		
	}

	EndGame();
	
	delete currentCommand;
	delete player;
	delete world;

	return 0;
}

void EndGame()
{
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You carefully open the great stone door...");
	_getch();
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("You have escaped the corridor!");
	_getch();
	ServiceLocator::GetConsoleWriter().WriteStringToConsole("Press any key to exit...");
	_getch();
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

void SetConsoleWindowSize()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
}

void WriteTitleArt()
{
	std::vector<std::string> titleArt = ServiceLocator::GetData().GetTitleArt();

	for (std::string line : titleArt)
	{
		std::cout << line << std::endl;
	}

	std::cout << ' ' << std::endl;
	std::cout << ' ' << std::endl;

	_getch();
}

void WriteTutorial()
{
	std::vector<std::string> tutorialText = ServiceLocator::GetData().GetTutorialDialogue();
	
	for (std::string line : tutorialText)
	{
		ServiceLocator::GetConsoleWriter().WriteTutorialToConsole(line);
		_getch();
	}
}

