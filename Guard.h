#ifndef GUARD_H
#define GUARD_H

#include "Position.h"

typedef struct
{
    Position pos;
    
    // valid values: 0, 1, 2, 3
    // 0: up, 1: right, 2: down, 3: left
    unsigned char facing;
} Guard;

/*
 * Later in development, facing will do more than just
 * determine which direction the guard moves.
*/

Guard* initGuard();
unsigned char updateGuardFacing(Guard* grd, unsigned char facing);
Position moveGuard(Guard* grd, int d);
Position setGuardPos(Guard* grd, int x, int y);

#endif // GUARD_H