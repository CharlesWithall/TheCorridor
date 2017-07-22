#pragma once

#include <vector>

#include "Event.h"

class IObserver;

class Notifier
{
public:
	Notifier();
	~Notifier();

	virtual void Notify(const Event* const anEvent) = 0;
	void RegisterListener(IObserver* anObserver);
	void UnregisterListener(IObserver* anObserver);

protected:
	std::vector<IObserver*> myObservers;
};

