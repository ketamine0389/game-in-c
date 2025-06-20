#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include "Position.h"
#include <stdbool.h>

typedef struct 
{
    Position pos;
    int loudness;
} Player;

Player* initPlayer();
// moved player movement functions
int incrLoudness(Player* plr, int incr);

#endif // PLAYER_H