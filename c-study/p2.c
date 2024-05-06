#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;
    
    lower = 0;
    upper = 300;
    step = 20;
    
    fahr = lower;
    
    printf("%6s\t%9s\n", "Fahr/℉", "Celsius/℃");
    while (fahr <= upper)
    {
        celsius = 5 * (fahr - 32) / 9;
        printf("%6.0f\t%9.1f\n", fahr, celsius);
        fahr += step;
    }
    
}