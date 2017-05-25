#include "stdafx.h"
#include "XMLParser.h"

XMLParser::XMLParser(void)
{
}


XMLParser::~XMLParser(void)
{
}

std::string XMLParser::GetDialogueText(const std::string& aRoom, const std::string& anAction, const std::string& aDirection)
{
	std::string outPutString;
	std::string xmlDocFilePath = ROOM_DATA;
	myXmlDocument.open(xmlDocFilePath);

	if (myXmlDocument.is_open())
	{
		NavigateToLine(aRoom);
		NavigateToLine(anAction, aRoom);
		NavigateToLine(aDirection, anAction);
		outPutString = GetValueFromCurrentLine();
	}
	else
	{
		throw "Unable to open XML Document! - " + xmlDocFilePath;
	}

	myXmlDocument.close();

	return outPutString;
}

bool XMLParser::NavigateToLine(const std::string& aNodeNameToFind, const std::string& aNodeNameToSearchWithin)
{
	bool navigationSuccessful = false;

	while (!IsEndOfNode(aNodeNameToSearchWithin) && !navigationSuccessful && myCurrentLine != "</MAIN>")
	{
		std::getline(myXmlDocument, myCurrentLine);

		if (GetNodeNameFromCurrentLine() == aNodeNameToFind)
		{
			navigationSuccessful = true;
		}
	}

	return navigationSuccessful;
}

std::string XMLParser::GetNodeNameFromCurrentLine() const
{
	int startIndex = myCurrentLine.find_first_of('<') + 1;
	int stringLength = myCurrentLine.find_first_of(" >") - startIndex;

	return myCurrentLine.substr(startIndex, stringLength);
}

bool XMLParser::IsEndOfNode(const std::string& aNodeName) const
{
	return GetNodeNameFromCurrentLine() == '/' + aNodeName;
}

std::string XMLParser::GetValueFromCurrentLine() const
{
	int startIndex = myCurrentLine.find_first_of('"') + 1;
	int stringLength = myCurrentLine.find_last_of('"') - startIndex;

	return myCurrentLine.substr(startIndex, stringLength);
}