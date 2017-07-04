#pragma once

#include "ConsoleWriter.h"
#include "DataRepository.h"
#include "Definitions.h"

class ServiceLocator
{
public:
	ServiceLocator(void);
	~ServiceLocator(void);

	static ConsoleWriter& GetConsoleWriter();
	static Definitions& GetDefinitions();
	static DataRepository& GetData();
private:
	static ConsoleWriter* theConsoleWriterInstance;
	static Definitions* theDefinitionsInstance;
	static DataRepository* theDataInstance;
};

