#include <stdio.h>

#define STEP 20
#define LOWER 0
#define UPPER 300

int main() {
    float fahr;
    
    printf("%6s\t%9s\n", "Fahr/℉", "Celsius/℃");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%6.0f\t%9.1f\n", fahr, 5 * (fahr - 32) / 9);
    }
    
}