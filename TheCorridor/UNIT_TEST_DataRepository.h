#pragma once

#include "DataRepository.h"
#include "UNIT_TEST.h"
#include "XMLParser2.h"

class UNIT_TEST_DataRepository : public UNIT_TEST
{
public:
	UNIT_TEST_DataRepository(void);
	~UNIT_TEST_DataRepository(void);

	void RunTest();
private:
	void UNIT_TEST_DataRepository::CheckDialogueGetter(const DataRepository& aDataRepository);
};

