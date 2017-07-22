#include "stdafx.h"
#include "TxtParser.h"


TxtParser::TxtParser()
{
}


TxtParser::~TxtParser()
{
}

StringList TxtParser::ParseTxtFile(const std::string& aTxtFilePath)
{
	StringList stringList;
	std::ifstream txtDocument;
	std::string currentLine;
	txtDocument.open(aTxtFilePath);

	if (txtDocument.is_open())
	{
		while (std::getline(txtDocument, currentLine))
		{
			stringList.push_back(currentLine);
		}
	}
	else
	{
		throw "Unable to open TXT Document! - " + aTxtFilePath;
	}

	txtDocument.close();

	return stringList;
}