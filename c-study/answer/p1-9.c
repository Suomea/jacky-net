#include <stdio.h>

int main() {
    int c;
    int ws = 0;
    
    while((c = getchar()) != EOF) {
        if(c == ' ') {
            if(ws == 0) {
                putchar(c);
                ws = 1;
            }
        } else {
            putchar(c);
            ws = 0;
        }
    }
}