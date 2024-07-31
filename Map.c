#include "Map.h"
#include <math.h>
#include <stdlib.h>

Map genMap(int len, int wid)
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
        map->structure[i] = (int*)malloc(wid * sizeof(int*));
        if (map->structure[i] == NULL)
        {
            freeMap(map);
            return NULL;
        }
    }

    return map;
}

void freeMap(Map* map)
{
    for (int i = 0; i < map->length; i++)
        free(map->structure[i]);
    free(map->structure);

    free(map);
}
