#include "stdafx.h"
#include "AchievementComponent.h"
#include "ItemAcquiredEvent.h"
#include "MiniGameCompleteEvent.h"
#include "Player.h"

#define BASE_ACHIEVEMENT_STRING "Achievement Unlocked! "

AchievementComponent::AchievementComponent(Player* const aPlayer) : myPlayer(aPlayer)
{
}


AchievementComponent::~AchievementComponent()
{
}

void AchievementComponent::OnNotify(const Event* const anEvent)
{
	std::string achievementString = BASE_ACHIEVEMENT_STRING;

	if (const MiniGameCompleteEvent* const miniGameComplete = dynamic_cast<const MiniGameCompleteEvent* const>(anEvent))
	{
		switch (miniGameComplete->myMiniGameID)
		{
		case MG_BOOKS:
			achievementString += "BOOK WORM";
			break;
		case MG_CHANDELIERS:
			achievementString += "FIRE STARTER";
			break;
		case MG_CHESSBOARD:
			achievementString += "TILE TRAVELLER";
			break;
		case MG_WATERPIPES:
			achievementString += "POSEIDON";
			break;
		}
	}
	else if (const ItemAcquiredEvent* const itemAcquired = dynamic_cast<const ItemAcquiredEvent* const>(anEvent))
	{
		if (myPlayer->GetNumberOfKeysAcquired() == TOTAL_NUMBER_OF_KEYS)
		{
			achievementString += "KEEPER OF THE KEYS";
		}
	}

	if(achievementString != BASE_ACHIEVEMENT_STRING)
	{
		ServiceLocator::GetConsoleWriter().WriteAchievementToConsole(achievementString);
	}
}
