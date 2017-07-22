#pragma once

#include "Event.h"
#include "Notifier.h"
#include "ServiceLocator.h"

class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void OnNotify(const Event* const anEvent) = 0;
	virtual void RegisterAsListener(Notifier* const aNotifier) { aNotifier->RegisterListener(this); }
};

