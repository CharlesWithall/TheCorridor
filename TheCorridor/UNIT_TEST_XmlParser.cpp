#include "stdafx.h"
#include "UNIT_TEST_XmlParser.h"

UNIT_TEST_XmlParser::UNIT_TEST_XmlParser(void)
{
}


UNIT_TEST_XmlParser::~UNIT_TEST_XmlParser(void)
{
}

void UNIT_TEST_XmlParser::RunTest()
{
	XMLParser2 parser;
	XMLElement* document = parser.ParseRoomData();
	
	CheckDocumentValidity(document);
	CheckFirstAttributeCorrectlySet(document);
	CheckFirstDialogueCorrectlySet(document);
	CheckFirstRoomSecondCommandLastDirection(document);

	delete document;
}

void UNIT_TEST_XmlParser::CheckDocumentValidity(XMLElement* aDocument)
{
	if (!aDocument)
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("Parser was unable to generate a document!");
}

void UNIT_TEST_XmlParser::CheckFirstAttributeCorrectlySet(XMLElement* aDocument)
{
	std::string expected = "0";
	std::string actual = aDocument->GetChildElements().front()->GetAttributeByKey(XMLAttributeDefinition::Id);

	if (actual != expected)
			ServiceLocator::GetConsoleWriter().WriteStringToConsole("The first attribute was set incorrectly, Expected: " + expected + " Actual: " + actual);
}

void UNIT_TEST_XmlParser::CheckFirstDialogueCorrectlySet(XMLElement* aDocument)
{
	std::string expected = "You step further down the Corridor";
	std::string actual = aDocument->GetChildElements().front()->GetChildElements().front()->GetChildElements().front()->GetAttributeByKey(XMLAttributeDefinition::Dialogue);

	if (actual != expected)
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The first line of dialogue was set incorrectly, Expected: " + expected + " Actual: " + actual);
}

void UNIT_TEST_XmlParser::CheckFirstRoomSecondCommandLastDirection(XMLElement* aDocument)
{
	std::string expected = "There is just a stone wall here";
	std::string actual = aDocument->GetChildElements().front()->GetChildElements()[1]->GetChildElements().back()->GetAttributeByKey(XMLAttributeDefinition::Dialogue);

	if (actual != expected)
		ServiceLocator::GetConsoleWriter().WriteStringToConsole("The Corridor_One, Look, West Dialogue was set incorrectly, Expected: " + expected + " Actual: " + actual);
}
