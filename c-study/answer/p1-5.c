#include <stdio.h>
#define UPPER 300
#define STEP 20

int main() {
    for(int i = UPPER; i >= 0; i-=STEP) {
        printf("%3d\t%7.2f\n", i, (i - 32) * 5.0 / 9);
    }
}