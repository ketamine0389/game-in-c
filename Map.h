#ifndef MAP_H
#define MAP_H

typedef struct
{
    int length;
    int width;
    int** structure;
} Map;

Map* genMap();
void freeMap(Map*);

#endif // MAP_H