#pragma once

#include "ConsoleWriter.h"
#include "StringDefiner.h"
#include "CorridorStringDefinitions.h"

enum Action { GO, LOOK, TAKE, INVESTIGATE };
enum Direction { NORTH, EAST, SOUTH, WEST };

class ServiceLocator
{
public:
	ServiceLocator(void);
	~ServiceLocator(void);

	static ConsoleWriter& GetConsoleWriter();
private:
	static ConsoleWriter* theConsoleWriterInstance;
};

