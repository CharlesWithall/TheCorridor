#pragma once

#include "XMLElement.h"
#include <string>
#include <stack>
#include <fstream>
#include <iostream>
#include <map>

#define ROOM_DATA "..\\Data\\room_data.xml"
#define ITEM_DATA "..\\Data\\item_data.xml"

class XMLParser2
{
public:
	XMLParser2(void);
	~XMLParser2(void);

	XMLElement* ParseRoomData() { return ParseDocument(ROOM_DATA); }
	XMLElement* ParseItemData() { return ParseDocument(ITEM_DATA); }
private:
	std::string myCurrentLine;
	std::string myCurrentNodeName;
	std::stack<XMLElement*> myCurrentElements;

	std::ifstream myXmlDocument;
	XMLElement* myParsedDocument;
	XMLElement myCurrentElement;

	bool myShouldCloseElementFlag;

	XMLElement* ParseDocument(const std::string& anXmlPath);

	void AddAllAttributesToElement(XMLElement* anXmlElement);
	void AddElementToParsedDocument(XMLElement* anXmlElement);
	void SetCurrentNodeName();
	void WriteAttributesToElement();

	void CloseElement();
	bool IsOpeningBracket();
	bool IsComment();
};

