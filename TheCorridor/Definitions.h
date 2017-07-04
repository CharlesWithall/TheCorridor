#pragma once

#include <string>
#include <map>

#define XML_ROOT "MAIN"

#define MAX_WORLD_SIZE 16
#define MAX_PLAYER_INVENTORY_SIZE 16
#define MAX_ROOM_INVENTORY_SIZE 8

// DEFAULT DIALOGUE STRINGS
#define INVALID_COMMAND_STRING "Command not recognised"
#define INVALID_DIRECTION_STRING "Direction not recognised"
#define INVALID_ITEM_STRING "Item not recognised"
#define INVALID_ITEM_PICKUP_STRING "Can't pick up this item"
#define INVALID_ITEM_ALREADY_OWNED_STRING "You already have this item"
#define INVALID_CANDLE_STRING "Cannot light this candle; the candles are numbered 1 - 9"

// ENUMS
enum Action { GO, LOOK, TAKE, EXAMINE, IGNITE, MOVE, ACTION_COUNT };
enum Direction { NORTH, EAST, SOUTH, WEST, DIRECTION_COUNT };
enum ItemID { INFERNO, PURGATORIO, PARADISUM, BOTTLE1, BOTTLE2, BOTTLE3, BUCKET, BLUE_KEY, GREEN_KEY, PURPLE_KEY, RED_KEY, YELLOW_KEY, MAP1, MAP2, MAP3, MATCHBOX, NOTE1, NOTE2, POKER, STAFF, ITEM_COUNT, ITEM_INVALID }; // !!! KEEP SYNCHRONISED WITH item_data.xml !!!
enum RoomID { CORRIDOR_ONE, CORRIDOR_TWO, CORRIDOR_THREE, CORRIDOR_FOUR, CORRIDOR_FIVE, CORRIDOR_SIX, CORRIDOR_SEVEN,
			DRAWING_ROOM, LIBRARY, SECRET_ROOM, TREASURY, WINERY, BATHROOM, PLAYROOM, COURTYARD}; // !!! KEEP SYNCHRONISED WITH room_data.xml !!!
enum XMLAttributeDefinition { Id, Name, Dialogue, RoomIdentifier, ItemLocked };

class Definitions
{
	friend class ServiceLocator;

public:
	
	~Definitions(void);

	static std::string GetStringForAction(Action anAction) { return ourActionStrings[anAction]; }
	static std::string GetStringForDirection(Direction aDirection) { return ourDirectionStrings[aDirection]; }
	std::string GetStringForRoom(int aRoom) { return ourRoomStrings[aRoom]; }

private:
	Definitions();

	static const std::string ourActionStrings[];
	static const std::string ourDirectionStrings[];
	static const std::string ourRoomStrings[];

};

