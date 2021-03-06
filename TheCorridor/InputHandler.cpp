#include "stdafx.h"
#include "InputHandler.h"

InputHandler::InputHandler(void)
{

}

InputHandler::~InputHandler(void)
{
}

Command* InputHandler::HandleInput(const Player* aPlayer, const std::string& aUserInput)
{
	std::string firstWord;
	std::string lastWord;
	Action action;
	Direction direction;
	ItemID itemID;

	if (HandleSpecialInputs(aPlayer, aUserInput))
		return NULL;

	GetFirstTwoWordsFromString(aUserInput, firstWord, lastWord);	

	if (!ConvertStringToAction(firstWord, action, aPlayer))
	{
		ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_COMMAND_STRING);
		return nullptr;
	}
	else
	{
		switch (action)
		{
		case GO:
			if (!ConvertStringToDirection(lastWord, direction))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIRECTION_STRING);
				return nullptr;
			}

			return new GoCommand(direction);
		case LOOK:
			if (!ConvertStringToDirection(lastWord, direction))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_LOOK_STRING);
				return nullptr;
			}

			return new LookCommand(direction);
		case TAKE:
			if (!ConvertStringToItem(lastWord, itemID))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_STRING);
				return nullptr;
			}

			return new TakeCommand(itemID);
		case EXAMINE:
			if (!ConvertStringToItem(lastWord, itemID))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_STRING);
				return nullptr;
			}

			return new ExamineCommand(itemID);
		case IGNITE:
			int candleNumber;

			if (!ConvertStringToInt(lastWord, candleNumber))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_CANDLE_STRING);
				return nullptr;
			}

			return new IgniteCommand(candleNumber);
		case MOVE:
			if (!ConvertStringToDirection(lastWord, direction))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIRECTION_STRING);
				return nullptr;
			}

			return new MoveCommand(direction);
		case ROTATE:
			LeftRight dial;

			if (!ConvertStringToLeftRight(lastWord, dial))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_DIAL_DIRECTION_STRING);
				return nullptr;
			}

			return new RotateCommand(dial);
		case PULL:
			if (lastWord.length() != 1)
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_PULL_STRING);
				return nullptr;
			}

			return new PullCommand(toupper(lastWord[0]));
		case USE:
			if (!ConvertStringToItem(lastWord, itemID))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_ITEM_STRING);
				return nullptr;
			}

			return new UseCommand(itemID);
		case OPEN:
			if (!CompareStringOrFirstLetter(lastWord, "DOOR"))
			{
				ServiceLocator::GetConsoleWriter().WriteStringToConsole(INVALID_COMMAND_STRING);
				return nullptr;
			}

			return new OpenCommand();
		default:
			ServiceLocator::GetConsoleWriter().ReportError(ERROR_INVALID_ACTION_COMMAND);
			return nullptr;
		}
	}	
}

void InputHandler::GetFirstTwoWordsFromString(const std::string& anInputString, std::string& aFirstWord, std::string& aSecondWord)
{	
	aFirstWord = anInputString.substr(0, anInputString.find_first_of(" \t"));
	aSecondWord = anInputString.substr(anInputString.find_first_of(" \t")+1, std::string::npos);	
}

bool InputHandler::ConvertStringToAction(const std::string& anInputString, Action& anAction, const Player* aPlayer)
{
	if (CompareStringOrFirstLetter(anInputString, "GO"))
	{
		anAction = Action::GO;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "LOOK"))
	{
		anAction = Action::LOOK;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "TAKE"))
	{
		anAction = Action::TAKE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "EXAMINE"))
	{
		anAction = Action::EXAMINE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "IGNITE") && aPlayer->GetCurrentRoom()->GetID() == aPlayer->GetMiniGameComponent()->GetChandelierMiniGame()->GetLocation())
	{
		anAction = Action::IGNITE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "MOVE") && aPlayer->GetCurrentRoom()->GetID() == aPlayer->GetMiniGameComponent()->GetChessBoardMiniGame()->GetLocation())
	{
		anAction = Action::MOVE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "ROTATE") && aPlayer->GetCurrentRoom()->GetID() == aPlayer->GetMiniGameComponent()->GetWaterPipesMiniGame()->GetLocation())
	{
		anAction = Action::ROTATE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "PULL") && aPlayer->GetCurrentRoom()->GetID() == aPlayer->GetMiniGameComponent()->GetBookCaseMiniGame()->GetLocation())
	{
		anAction = Action::PULL;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "USE"))
	{
		anAction = Action::USE;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "OPEN") && aPlayer->GetCurrentRoom()->GetID() == CORRIDOR_SEVEN)
	{
		anAction = Action::OPEN;
		return true;
	}

	return false;
}

bool InputHandler::ConvertStringToDirection(const std::string& anInputString, Direction& aDirection)
{
	if (CompareStringOrFirstLetter(anInputString, "NORTH"))
	{
		aDirection = Direction::NORTH;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "EAST"))
	{
		aDirection = Direction::EAST;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "SOUTH"))
	{
		aDirection = Direction::SOUTH;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "WEST"))
	{
		aDirection = Direction::WEST;
		return true;
	}

	return false;
}

bool InputHandler::ConvertStringToItem(const std::string& anInputString, ItemID& anItemID)
{
	std::string inputString = anInputString;

	for(int i = 0; i < inputString.length(); ++i)
	{
		inputString[i] = toupper(inputString[i]);
	}

	anItemID = ServiceLocator::GetData().GetItemIDByName(inputString);

	return anItemID != ITEM_INVALID;
}

bool InputHandler::ConvertStringToInt(const std::string& anInputString, int& aCandleNumber)
{
	aCandleNumber = anInputString[0] - '0';
	if (aCandleNumber < 1 || aCandleNumber > 9)
	{
		return false;
	}

	return true;
}

bool InputHandler::ConvertStringToLeftRight(const std::string& anInputString, LeftRight& aDirection)
{
	if (CompareStringOrFirstLetter(anInputString, "LEFT"))
	{
		aDirection = LEFT;
		return true;
	}

	if (CompareStringOrFirstLetter(anInputString, "RIGHT"))
	{
		aDirection = RIGHT;
		return true;
	}

	return false;
}

bool InputHandler::CompareStringOrFirstLetter(const std::string& aUserString, const std::string& aGameString)
{
	if (aUserString.length() == aGameString.length())
	{
		for (int i = 0; i < aUserString.length(); ++i)
		{
			if (toupper(aUserString[i]) != aGameString[i])
			{
				return false;
			}
		}
	}
	else
	{
		if (aUserString.length() == 1 && toupper(aUserString[0]) == aGameString[0])
		{
			return true;
		}

		return false;
	}

	return true;
}

bool InputHandler::HandleSpecialInputs(const Player* aPlayer, const std::string& anUserInput)
{
	if (CompareStringOrFirstLetter(anUserInput, "INVENTORY"))
	{
		const std::vector<Item*>& items = aPlayer->GetItemsComponent()->GetInventory();

		for (Item* item : items)
		{
			ServiceLocator::GetConsoleWriter().WriteStringToConsole(item->GetItemName(), std::string(), COLOUR_SPECIAL);
		}

		return true;
	}

	if (CompareStringOrFirstLetter(anUserInput, "HELP"))
	{
		std::vector<std::string> stringList = ServiceLocator::GetData().GetTutorialDialogue();

		for (std::string line : stringList)
		{
			ServiceLocator::GetConsoleWriter().WriteTutorialToConsole(line);
		}

		return true;
	}

	return false;
}