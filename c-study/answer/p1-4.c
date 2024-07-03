#include <stdio.h>
#define UPPER 300
#define STEP 20

int main() {
    printf("Celsius\t   Fahr\n");
    for(int i = 0; i <= UPPER; i += STEP) {
        printf("%7d\t%7.0f\n", i, i * 9.0 / 5 + 32);
    }
}