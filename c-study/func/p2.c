#include <stdio.h>

struct Point{
    int x;
    int y;
};

struct Point p;

int main() {
    printf("p.x = %d\n", p.x);
    printf("p.y = %d\n", p.y);

    struct Point p2;
    printf("p2.x = %d\n", p2.x);
    printf("p2.y = %d\n", p2.y);
    
    int test;
    printf("test = %d\n", test);
    
    return 0;
}