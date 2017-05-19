#pragma once

#include <string>

class ServiceLocator;

class StringDefiner
{
	friend class ServiceLocator;
public:
	~StringDefiner(void);
	const std::string INVALID_COMMAND;
private:
	StringDefiner();
};
