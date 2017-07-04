#pragma once

#include "ServiceLocator.h"

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void onNotify(const ItemID& anItemID, const Action& anAction) = 0;
};

