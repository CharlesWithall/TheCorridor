#include "stdafx.h"
#include "ServiceLocator.h"

ConsoleWriter* ServiceLocator::theConsoleWriterInstance;

ServiceLocator::ServiceLocator(void)
{

}


ServiceLocator::~ServiceLocator(void)
{
	if (theConsoleWriterInstance != NULL)
	{
		delete theConsoleWriterInstance;
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
