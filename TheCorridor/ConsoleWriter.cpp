#include "stdafx.h"
#include "ConsoleWriter.h"

ConsoleWriter::ConsoleWriter(void)
{
}


ConsoleWriter::~ConsoleWriter(void)
{
}

void ConsoleWriter::WriteStringToConsole(const std::string& aStringToDisplay, const std::string& anArgument)
{
	std::string output;

	bool isInsertingArgument = false;

	for(char c : aStringToDisplay)
	{
		if (c == '%')
		{
			isInsertingArgument = true;
		}
		else if (isInsertingArgument)
		{
			if (c == 's')
			{
				output += anArgument;
			}
			else
			{
				output += "%" + c;
			}

			isInsertingArgument = false;
		}
		else
		{
			output += c;
		}
	}

	std::cout << output << std::endl;
}
