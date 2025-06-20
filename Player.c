#include "Map.h"
#include "Player.h"
#include <stdbool.h>
#include <stdlib.h>

Player* initPlayer()
{
    Player* plr = malloc(sizeof(Player));
    if (plr == NULL) return NULL;

    plr->loudness = 0;
    plr->pos.x = -1;
    plr->pos.y = -1;
    
    return plr;
}

int incrLoudness(Player* plr, int incr)
{
    plr->loudness += incr;
    return plr->loudness;
}
