#pragma once

#include "ServiceLocator.h"

#include <assert.h>
#include <exception>
#include <string>
#include <vector>

class UNIT_TEST
{
public:
	UNIT_TEST(void) {}
	virtual ~UNIT_TEST(void) {}
	virtual void RunTest() = 0;
};

