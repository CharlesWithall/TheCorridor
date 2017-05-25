#include "stdafx.h"
#include "ServiceLocator.h"

ConsoleWriter* ServiceLocator::theConsoleWriterInstance;
Definitions* ServiceLocator::theDefinitionsInstance;
XMLParser* ServiceLocator::theDataInstance;

ServiceLocator::ServiceLocator(void)
{

}


ServiceLocator::~ServiceLocator(void)
{
	if (theConsoleWriterInstance != NULL)
	{
		delete theConsoleWriterInstance;
	}

	if (theDefinitionsInstance != NULL)
	{
		delete theDefinitionsInstance;
	}
}

ConsoleWriter& ServiceLocator::GetConsoleWriter()
{
	if (theConsoleWriterInstance == NULL)
	{
		theConsoleWriterInstance = new ConsoleWriter();
	}
	return *theConsoleWriterInstance;
}

Definitions& ServiceLocator::GetDefinitions()
{
	if (theDefinitionsInstance == NULL)
	{
		theDefinitionsInstance = new Definitions();
	}
	return *theDefinitionsInstance;
}

XMLParser& ServiceLocator::GetData()
{
	if (theDataInstance == NULL)
	{
		theDataInstance = new XMLParser();
	}
	return *theDataInstance;
}
