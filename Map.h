#ifndef MAP_H
#define MAP_H
#include "Player.h"
#include "Guard.h"

typedef struct
{
    int length;
    int width;
    Player* player;
    Guard** guards; // array of guard pointers
    int numGuards;
    int** structure; // this will contain any map data, such as the bounds and empty areas on the map
} Map;

Map* genMap(int len, int wid);
bool populateMap(Map* map);
void freeMap(Map* map);
void printMap(Map* map);

bool movePlayer(Map* map, int dx, int dy);
bool setPlayerPos(Map* map, int x, int y);

#endif // MAP_H