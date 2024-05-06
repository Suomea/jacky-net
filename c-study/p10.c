#include <stdio.h>

int power(int m, int n);

int main() 
{
    for(int i = 0; i < 10; ++ i) 
        printf("%d %5d %7d\n", i, power(2, i), power(-3, i));
}

int power(int m, int n) {
    int i, p;

    p = 1;
    for (i = 0; i < n; i ++) {
        p = p * m;
    }
    
    return p;
}