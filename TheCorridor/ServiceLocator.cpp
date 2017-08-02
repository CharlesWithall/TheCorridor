#include "stdafx.h"
#include "ServiceLocator.h"

ConsoleWriter* ServiceLocator::theConsoleWriterInstance;
Definitions* ServiceLocator::theDefinitionsInstance;
DataRepository* ServiceLocator::theDataInstance;

ServiceLocator::ServiceLocator(void)
{

}


ServiceLocator::~ServiceLocator(void)
{
	
}

void ServiceLocator::DeleteServices()
{
	if (theConsoleWriterInstance)
	{
		delete theConsoleWriterInstance;
	}

	if (theDefinitionsInstance)
	{
		delete theDefinitionsInstance;
	}

	if (theDataInstance)
	{
		delete theDefinitionsInstance;
	}
}

ConsoleWriter& ServiceLocator::GetConsoleWriter()
{
	if (!theConsoleWriterInstance)
	{
		theConsoleWriterInstance = new ConsoleWriter();
	}
	return *theConsoleWriterInstance;
}

Definitions& ServiceLocator::GetDefinitions()
{
	if (!theDefinitionsInstance)
	{
		theDefinitionsInstance = new Definitions();
	}
	return *theDefinitionsInstance;
}

DataRepository& ServiceLocator::GetData()
{
	if (!theDataInstance)
	{
		theDataInstance = new DataRepository();
	}
	return *theDataInstance;
}
