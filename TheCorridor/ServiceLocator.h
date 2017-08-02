#pragma once

#include "ConsoleWriter.h"
#include "DataRepository.h"
#include "Definitions.h"

class ServiceLocator
{
public:
	~ServiceLocator(void);

	static void DeleteServices();
	static ConsoleWriter& GetConsoleWriter();
	static Definitions& GetDefinitions();
	static DataRepository& GetData();
private:
	ServiceLocator(void);

	static ConsoleWriter* theConsoleWriterInstance;
	static Definitions* theDefinitionsInstance;
	static DataRepository* theDataInstance;
};

