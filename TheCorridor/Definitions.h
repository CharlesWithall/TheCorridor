#pragma once

#include <string>

#define XML_ROOT "MAIN"

#define MAX_WORLD_SIZE 15
#define MAX_PLAYER_INVENTORY_SIZE 16
#define MAX_ROOM_INVENTORY_SIZE 8
#define TOTAL_NUMBER_OF_KEYS 5

// DEFAULT DIALOGUE STRINGS
#define INVALID_COMMAND_STRING "Command not recognised"
#define INVALID_DIRECTION_STRING "You cannot go this way"
#define INVALID_LOOK_STRING "You cannot look in this direction"
#define INVALID_ITEM_STRING "Item not recognised"
#define INVALID_ITEM_PICKUP_STRING "Can't pick up this item - you could EXAMINE it"
#define INVALID_ITEM_ALREADY_OWNED_STRING "You already have this item"
#define INVALID_PULL_STRING "You cannot pull that: you must select a letter (eg \"PULL A\")"
#define INVALID_CANDLE_STRING "Cannot light this candle; the candles are numbered 1 - 9"
#define INVALID_DIAL_DIRECTION_STRING "An invalid dial turning direction was selected"
#define INVALID_ITEM_USE "Nothing happened"

#define FIRST_MOVE_HINT_STRING "Hint: Type 'GO NORTH' to get going..."

#define ERROR_INVALID_ACTION_COMMAND "INVALID ACTION COMMAND GENERATED"
#define ERROR_INVALID_CANDLE_SELECTION "CANDLE SELECTED IS OUTSIDE THE BOUNDS OF THE CHANDELIER ARRANGEMENT"
#define ERROR_INVALID_DIAL_STRING "AN INVALID DIAL WAS SELECTED"


// ENUMS
enum Action { GO, LOOK, TAKE, EXAMINE, IGNITE, MOVE, ROTATE, PULL, USE, OPEN, ACTION_COUNT, INVALID_ACTION };
enum DataType { ROOM_DATA_TYPE, ITEM_DATA_TYPE };
enum Direction { NORTH, EAST, SOUTH, WEST, DIRECTION_COUNT, INVALID_DIRECTION };
enum LeftRight { LEFT, RIGHT };
// !!! KEEP SYNCHRONISED WITH item_data.xml !!!
enum ItemID { INFERNO, PURGATORIO, PARADISUM, GOULAINE, RICASOLI, CODORNIU, BUCKET, BLUE_KEY, GREEN_KEY, PURPLE_KEY, RED_KEY, YELLOW_KEY, MAP, MATCHBOX, NOTE, POKER, STAFF, BLACK_KEY,
			FIREPLACE = 117, PIPES, TILES, CANDELABRA, FONT, BOOKCASE, WINERACK, CHEST, BOX, TAPESTRY, RUBBLE, PAINTING, HERMIT, JUDITH, DAVID, SALOME, DOOR, ITEM_INVALID };
enum MiniGameID { MG_BOOKS, MG_CHANDELIERS, MG_CHESSBOARD, MG_WATERPIPES };
enum RoomID { CORRIDOR_ONE, CORRIDOR_TWO, CORRIDOR_THREE, CORRIDOR_FOUR, CORRIDOR_FIVE, CORRIDOR_SIX, CORRIDOR_SEVEN,
			DRAWING_ROOM, LIBRARY, SECRET_ROOM, TREASURY, WINERY, BATHROOM, PLAYROOM, COURTYARD, INVALID_ROOM }; // !!! KEEP SYNCHRONISED WITH room_data.xml !!!

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

