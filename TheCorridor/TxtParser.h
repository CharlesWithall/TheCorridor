#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

typedef std::vector<std::string> StringList;

class TxtParser
{
public:
	TxtParser();
	~TxtParser();

	StringList ParseTxtFile(const std::string& aTxtFilePath);
};

