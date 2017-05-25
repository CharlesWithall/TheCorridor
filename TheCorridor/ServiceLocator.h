#pragma once

#include "ConsoleWriter.h"
#include "Definitions.h"
#include "XMLParser.h"

class ServiceLocator
{
public:
	ServiceLocator(void);
	~ServiceLocator(void);

	static ConsoleWriter& GetConsoleWriter();
	static Definitions& GetDefinitions();
	static XMLParser& GetData();
private:
	static ConsoleWriter* theConsoleWriterInstance;
	static Definitions* theDefinitionsInstance;
	static XMLParser* theDataInstance;
};

