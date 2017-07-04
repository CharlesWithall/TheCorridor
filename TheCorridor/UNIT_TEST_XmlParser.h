#pragma once

#include "UNIT_TEST.h"
#include "XMLParser2.h"

class UNIT_TEST_XmlParser : public UNIT_TEST
{
public:
	UNIT_TEST_XmlParser(void);
	~UNIT_TEST_XmlParser(void);

	void RunTest();
private:
	void UNIT_TEST_XmlParser::CheckDocumentValidity(XMLElement* aDocument);
	void UNIT_TEST_XmlParser::CheckFirstAttributeCorrectlySet(XMLElement* aDocument);
	void UNIT_TEST_XmlParser::CheckFirstDialogueCorrectlySet(XMLElement* aDocument);
	void UNIT_TEST_XmlParser::CheckFirstRoomSecondCommandLastDirection(XMLElement* aDocument);
};

