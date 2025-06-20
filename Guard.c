#include "Guard.h"
#include <stdlib.h>

Guard* initGuard()
{
    Guard* grd = malloc(sizeof(Guard));
    if (grd == NULL) return NULL;

    grd->pos.x = -1;
    grd->pos.y = -1;
    grd->facing = 0;

    return grd;
}

/*
 * Prototype code
*/

unsigned char updateGuardFacing(Guard* grd, unsigned char facing)
{
    if (facing > 3) return 0xFF;
    
    grd->facing = facing;
    return grd->facing;
}

Position moveGuard(Guard* grd, int d)
{
    // Note about facing in Guard.h
    Position invalidPos = {-1, -1};

    switch (grd->facing)
    {
        case 0:
            return setGuardPos(grd, grd->pos.x, grd->pos.y - 1);
        case 1:
            return setGuardPos(grd, grd->pos.x + 1, grd->pos.y);
        case 2:
            return setGuardPos(grd, grd->pos.x, grd->pos.y + 1);
        case 3:
            return setGuardPos(grd, grd->pos.x - 1, grd->pos.y);
        default:
            return invalidPos;
    }
}

Position setGuardPos(Guard* grd, int x, int y)
{
    // if (x > map->width || x < 0) return false;
    // else if (y > map->length || y < 0) return false;
    
    // map->player->pos.x = x;
    // map->player->pos.y = y;

    // return true;
}

