#include "stdafx.h"
#include "Notifier.h"


Notifier::Notifier(void)
{
}


Notifier::~Notifier(void)
{
}

void Notifier::AddObserver(IObserver* anObserver)
{
	myObservers.push_back(anObserver);
}

void Notifier::RemoveObserver(IObserver* anObserver)
{
	 for (int i = 0; i < myObservers.size(); ++i)
	 {
		 if (myObservers[i] == anObserver)
		 {
			 myObservers.erase(myObservers.begin() + i);
		 }
	 }
}

void Notifier::NotifyObservers(const ItemID& anItemID, const Action& anAction)
{
	for (std::vector<IObserver*>::iterator it = myObservers.begin(); it != myObservers.end(); ++it)
	{
		(*it)->onNotify(anItemID, anAction);
	}
}