#pragma once

#include <string>

#define INVALID_COMMAND_STRING "Command not recognised"
#define INVALID_DIRECTION_STRING "Direction not recognised"

#define XML_ROOT "MAIN"

#define MAX_WORLD_SIZE 16

// ROOM DEFINES
#define CORRIDOR_ONE 0
#define CORRIDOR_TWO 1
#define CORRIDOR_THREE 2
#define CORRIDOR_FOUR 3
#define CORRIDOR_FIVE 4
#define CORRIDOR_SIX 5
#define CORRIDOR_SEVEN 6
#define DRAWING_ROOM 7
#define LIBRARY 8
#define SECRET_ROOM 9
#define TREASURY 10
#define WINERY 11
#define BATHROOM 12
#define PLAYROOM 13
#define COURTYARD 14

enum Action { GO, LOOK, TAKE, INVESTIGATE };
enum Direction { NORTH, EAST, SOUTH, WEST };

class Definitions
{
	friend class ServiceLocator;

public:
	
	~Definitions(void);

	const std::string GetStringForAction(Action anAction) { return ourActionStrings[anAction]; }
	const std::string GetStringForDirection(Direction aDirection) { return ourDirectionStrings[aDirection]; }
	const std::string GetStringForRoom(int aRoom) { return ourRoomStrings[aRoom]; }
private:
	Definitions();

	static const std::string ourActionStrings[];
	static const std::string ourDirectionStrings[];
	static const std::string ourRoomStrings[];
};

