#include <stdio.h>

struct point {
    int x;
    int y;
} origin, *pp;

int main() {
    origin.x = 100;
    origin.y = 100;
    
    pp = &origin;
    printf("origin is (%d, %d)\n", (*pp).x, (*pp).y);
    printf("origin is (%d, %d)\n", pp->x, pp->y);
}