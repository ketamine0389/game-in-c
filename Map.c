#include "Map.h"

#include "Player.h"
#include "Guard.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

Map* genMap(int len, int wid)
{
    Map* map = (Map*)malloc(sizeof(Map));
    if (map == NULL) return NULL;

    map->length = len;
    map->width = wid;

    map->structure = (int**)malloc(len * sizeof(int*));
    if(map->structure == NULL)
    {
        free(map);
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        map->structure[i] = (int*)malloc(wid * sizeof(int));
        if (map->structure[i] == NULL)
        {
            freeMap(map);
            return NULL;
        }
    }

    if (!populateMap(map))
    {
        freeMap(map);
        return NULL;
    }

    return map;
}

bool populateMap(Map* map)
{
    // init player
    map->player = initPlayer();

    // place player
    if (!setPlayerPos(map, 10, 10))
    {
        // handle error
        return false;
    }

    // pop/init guards arr
    for (int i = 0; i < map->numGuards; i++)
    {
        map->guards[i] = initGuard();
        if (map->guards[i] == NULL) 
        {
            // handle error
            return false;
        }

        // place guards
        // guard code is prototyped temp
        // guards will not be utilized
        // until player movement and map
        // identifiers completed
    }

    return true;
}

void freeMap(Map* map)
{
    for (int i = 0; i < map->length; i++)
    {
        free(map->structure[i]);
        map->structure[i] = NULL;
    }

    for (int i = 0; i < map->numGuards; i++)
    {
        free(map->guards[i]);
        map->guards = NULL;
    }

    free(map->structure);
    map->structure = NULL;

    free(map->player);
    map->player = NULL;

    free(map);
    map = NULL;
}

void printMap(Map* map)
{
    for (int i = 0; i < map->width-2; i++) // - 2 for the info row and the output row
    {
        for (int j = 0; j < map->length; j++)
        {
            if (i == map->player->pos.y && j == map->player->pos.x) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}

bool movePlayer(Map* map, int dx, int dy)
{
    return setPlayerPos(map, map->player->pos.x + dx, map->player->pos.y + dy);
}

bool setPlayerPos(Map* map, int x, int y)
{
    if (x > map->width || x < 0) return false;
    else if (y > map->length || y < 0) return false;
    
    map->player->pos.x = x;
    map->player->pos.y = y;

    return true;
}
