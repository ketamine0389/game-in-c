#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
// window info
#include <sys/ioctl.h>
#include <unistd.h>
// key info
#include <termios.h>
#include <string.h> // memcpy
//#include <stdlib.h>
//#include <time.h>
// user-defined
#include "Map.h"
#include "Player.h"

struct winsize getTerminalSize();
int getKey();

int main()
{
    // seed rng
    srand(time(NULL));

    // vars
    int key; 
    Map* map;
    struct winsize win;

    // get size of terminal window
    win = getTerminalSize();
    printf("Width = %d, Height = %d\n", win.ws_col, win.ws_row);

    map = genMap(win.ws_col, win.ws_row);
    if (map == NULL) return 1;

    printMap(map);

    // Game loop
    for (;;)
    {
        key = getKey();

        if (key == -1) break; // error

        // ctrl + d, esc
        if (key == 0x1B || key == 0x04) break;
        else 
        {
            printf("\033[%d;%dHKEYPRESS = %c", win.ws_row, win.ws_col - 11, key);
            fflush(stdout);
        }
    }
    
    freeMap(map);
    return 0;
}

struct winsize getTerminalSize()
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w;
}

int getKey()
{
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    // set terminal to raw
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 1;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);
    // validate character before parsing
    

    // read character
    //  -1 if no char avail
    character = fgetc(stdin);

    // restore terminal attributes
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
    
    return character;
}
