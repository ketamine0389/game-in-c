#include "Player.h"
#include <stdbool.h>

bool movePlayer(Player* plr, Map* map, int dx, int dy)
{
    return setPlayerPos(plr, map, plr->x_pos + dx, plr->y_pos + dy);
}

bool setPlayerPos(Player* plr, Map* map, int x, int y)
{
    if (x > map->width || x < 0) return false;
    else if (y > map->length || y < 0) return false;
    
    plr->x_pos = x;
    plr->y_pos = y;

    return true;
}

int incrLoudness(Player* plr, int incr)
{
    plr->loudness += incr;
    return plr->loudness;
}
