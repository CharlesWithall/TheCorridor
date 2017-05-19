#include "stdafx.h"
#include "ConsoleWriter.h"


ConsoleWriter::ConsoleWriter(void)
{
}


ConsoleWriter::~ConsoleWriter(void)
{
}

void ConsoleWriter::WriteStringToConsole(std::string aStringToDisplay)
{
	std::cout << aStringToDisplay << std::endl;
}
