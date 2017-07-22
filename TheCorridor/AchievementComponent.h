#pragma once

#include "IObserver.h"
#include "Notifier.h"

class Player;

class AchievementComponent : public IObserver
{
public:
	AchievementComponent(Player* const aPlayer);
	~AchievementComponent();

	virtual void OnNotify(const Event* const anEvent) override;
private:
	Player* const myPlayer;
};

