#include "stdafx.h"
#include "Definitions.h"


Definitions::Definitions(void)
{
}


Definitions::~Definitions(void)
{
}

const std::string Definitions::ourActionStrings[] = { "GO", "LOOK", "TAKE", "INVESTIGATE" };
const std::string Definitions::ourDirectionStrings[] = { "NORTH", "EAST", "SOUTH", "WEST" };
const std::string Definitions::ourRoomStrings[] = { "CORRIDOR_ONE", "CORRIDOR_TWO", "CORRIDOR_THREE", "CORRIDOR_FOUR", "CORRIDOR_FIVE", "CORRIDOR_SIX", "CORRIDOR_SEVEN", "DRAWING_ROOM", "LIBRARY", "SECRET_ROOM", "TREASURY", "WINERY", "BATHROOM", "PLAYROOM", "COURTYARD" };