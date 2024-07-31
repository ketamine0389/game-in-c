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

bool movePlayer(Player*, Map*, int, int);
bool setPlayerPos(Player*, Map*, int, int);
int incrLoudness(Player*, int);

#endif // PLAYER_H