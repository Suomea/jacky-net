#include <stdio.h>
#define UPPER 300
#define STEP 20

int main() {
    printf("Fahr\tCelsius\n");
    for(int i = 0; i <= UPPER; i += STEP) {
        printf("%3d\t%7.2f\n", i, (i - 32) * 5.0 / 9);
    }
}