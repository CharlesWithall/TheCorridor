#pragma once

#include "Definitions.h"
#include <string>
#include <fstream>
#include <iostream>

#define ROOM_DATA "..\\Data\\room_data.xml"
#define ITEM_DATA "..\\Data\\item_data.xml"

class XMLParser
{
	friend class ServiceLocator;

public:
	~XMLParser(void);
	
	std::string GetDialogueText(const std::string& aRoom, const std::string& anAction, const std::string& aDirection);	
private:
	XMLParser(void);

	std::string GetNodeNameFromCurrentLine() const;
	std::string GetValueFromCurrentLine() const;

	bool NavigateToLine(const std::string& aNodeNameToFind, const std::string& aNodeNameToSearchWithin = XML_ROOT);
	bool IsEndOfNode(const std::string& aNodeName) const;

	std::ifstream myXmlDocument;
	std::string myCurrentLine;
};

