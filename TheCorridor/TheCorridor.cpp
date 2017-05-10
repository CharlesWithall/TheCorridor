// TheCorridor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "InputHandler.h"


int _tmain(int argc, _TCHAR* argv[])
{
	InputHandler inputHandler;

	while (true)
	{
		std::string userInput;
		std::getline(std::cin, userInput);
		inputHandler.HandleInput(userInput);
	}
	
	return 0;
}

