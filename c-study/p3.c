#include <stdio.h>

int main() {
    float fahr;
    
    printf("%6s\t%9s\n", "Fahr/℉", "Celsius/℃");
    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%6.0f\t%9.1f\n", fahr, 5 * (fahr - 32) / 9);
    }
    
}