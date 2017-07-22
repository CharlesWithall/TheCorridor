#include "stdafx.h"
#include "Notifier.h"


Notifier::Notifier()
{
}


Notifier::~Notifier()
{
}

void Notifier::RegisterListener(IObserver* anObserver)
{
	bool isObserverAlreadyRegistered = false;

	for (std::vector<IObserver*>::iterator it = myObservers.begin(); it != myObservers.end(); ++it)
	{
		if (*it == anObserver)
		{
			isObserverAlreadyRegistered = true;
		}
	}

	if (!isObserverAlreadyRegistered)
	{
		myObservers.push_back(anObserver);
	}	
}

void Notifier::UnregisterListener(IObserver* anObserver)
{
	for (std::vector<IObserver*>::iterator it = myObservers.begin(); it != myObservers.end(); ++it)
	{
		if (*it == anObserver)
		{
			myObservers.erase(it);
		}
	}
}
