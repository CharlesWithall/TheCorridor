#include "stdafx.h"
#include "UNIT_TEST_DataRepository.h"


UNIT_TEST_DataRepository::UNIT_TEST_DataRepository(void)
{
}


UNIT_TEST_DataRepository::~UNIT_TEST_DataRepository(void)
{
}

void UNIT_TEST_DataRepository::RunTest()
{
	DataRepository& dataRepository = ServiceLocator::GetData();

	CheckDialogueGetter(dataRepository);
}

void UNIT_TEST_DataRepository::CheckDialogueGetter(const DataRepository& aDataRepository)
{
	std::string expected = "You step further down the Corridor";
	std::string actual = aDataRepository.GetDialogueText(ROOM_DATA_TYPE, 0, GO, NORTH);

	if (actual != expected)
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The data repo has not found the correct dialogue, Expected: " + expected + " Actual: " + actual);
}