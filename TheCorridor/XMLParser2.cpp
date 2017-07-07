#include "stdafx.h"
#include "XMLParser2.h"

#include <iostream>


XMLParser2::XMLParser2(void)
{
}


XMLParser2::~XMLParser2(void)
{
}

XMLElement* XMLParser2::ParseDocument(const std::string& anXmlPath)
{	
	myParsedDocument = new XMLElement();
	myXmlDocument.open(anXmlPath);

	if (myXmlDocument.is_open())
	{
		myCurrentElements.push(myParsedDocument);

		while(std::getline(myXmlDocument, myCurrentLine))
		{
			if (!IsComment())
			{
				SetCurrentNodeName();
				myShouldCloseElementFlag = false;

				if (IsOpeningBracket())
				{
					XMLElement* newXmlElement = new XMLElement(myCurrentNodeName);
					AddAllAttributesToElement(newXmlElement);
					AddElementToParsedDocument(newXmlElement);

					if (myShouldCloseElementFlag)
					{
						CloseElement();
					}
				}
				else
				{
					CloseElement();
				}
			}			
		}
	}
	else
	{
		throw "Unable to open XML Document! - " + anXmlPath;
	}

	myXmlDocument.close();

	return myParsedDocument;
}

void XMLParser2::AddAllAttributesToElement(XMLElement* anXmlElement)
{
	std::string currentLine = myCurrentLine;

	// Navigate to start of attributes
	int startIndex = currentLine.find(myCurrentNodeName) + myCurrentNodeName.length();
	currentLine = currentLine.substr(startIndex);

	while (!currentLine.empty() && currentLine[0] != '/' && currentLine[0] != '>')
	{
		std::string attributeKey;
		std::string attributeValue;

		// Get attribute key
		currentLine = currentLine.substr(currentLine.find_first_not_of(' '));
		attributeKey = currentLine.substr(0, currentLine.find_first_of(" ="));
		//std::cout << "Att. Key " << attributeKey << std::endl;

		// Get attribute value
		currentLine = currentLine.substr(currentLine.find_first_of('"') + 1);
		attributeValue = currentLine.substr(0, currentLine.find_first_of('"'));
		//std::cout << "Att. Value " << attributeValue << std::endl;
	
		// Write key/value to map
		anXmlElement->AddAttribute(attributeKey, attributeValue);

		// Prepare for next attribute
		currentLine = currentLine.substr(attributeValue.length());
		currentLine = currentLine.substr(currentLine.find_first_not_of(" ,\""));
	}

	if (currentLine[0] == '/')
	{
		myShouldCloseElementFlag = true;
	}	
}

void XMLParser2::AddElementToParsedDocument(XMLElement* anXmlElement)
{	
	myCurrentElements.top()->AddChildElement(anXmlElement);
	myCurrentElements.push(myCurrentElements.top()->GetChildElements().back());
}

bool XMLParser2::IsOpeningBracket()
{
	return myCurrentNodeName[0] != '/';
}

void XMLParser2::CloseElement()
{
	myCurrentElements.pop();
}

void XMLParser2::SetCurrentNodeName()
{
	int startIndex = myCurrentLine.find_first_of('<') + 1;
	int stringLength = myCurrentLine.find_first_of(" >") - startIndex;
	myCurrentNodeName = myCurrentLine.substr(startIndex, stringLength);
}

bool XMLParser2::IsComment()
{
	if (myCurrentLine.length() > 2 && myCurrentLine[0] == '<' && myCurrentLine[1] == '!')
	{
		return true;
	}

	return false;
}