#pragma once

#include "IObserver.h"
#include <vector>

class Notifier
{
public:
	Notifier(void);
	~Notifier(void);

	void AddObserver(IObserver* anObserver);
	void RemoveObserver(IObserver* anObserver);

protected:
	void NotifyObservers(const ItemID& anItemID, const Action& anAction);

private:
	std::vector<IObserver*> myObservers;
};

