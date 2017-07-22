#pragma once

#include "IObserver.h"
#include "Room.h"

class World : public IObserver
{
public:
	World();
	~World();
	Room* GetPlayerStartingPosition();
	Room* GetRoomByID(const RoomID& aRoomID) const;
	virtual void OnNotify(const Event* const anEvent) override;
private:
	void Init();
	void InitRooms();
	void InitItems();

	Room** myMap;
	std::vector<Item*> myItems;
};

