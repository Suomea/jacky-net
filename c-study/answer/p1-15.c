#include <stdio.h>

float ceisius(float);

int main() {
    for(float i = 0; i < 300; i += 20) {
        printf("%3.0f %6.1f\n", i, ceisius(i));
    }
}

float ceisius(float fahr) {
    return (5.0 / 9) * (fahr - 32);
}