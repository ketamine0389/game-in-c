#ifndef PLAYER_H
#define PLAYER_H

#include "Map.h"
#include <stdbool.h>

typedef struct 
{
    int x_pos;
    int y_pos;
    int loudness;
} Player;

bool movePlayer(Player* plr, Map* map, int dx, int dy);
bool setPlayerPos(Player* plr, Map* map, int x, int y);
int incrLoudness(Player* plr, int incr);

#endif // PLAYER_H