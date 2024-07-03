#include <stdio.h>

int main() {
    int ws = 0, tab = 0, nl = 0;

    int c;
    while((c = getchar()) != EOF) {
        switch(c) {
            case '\n':
                nl ++;
                break;
            case '\t':
                tab ++;
                break;
            case ' ':
                ws ++;
                break;
            default:
                break;
        }
    }

    printf("ws: %d, tab: %d, nl: %d\n", ws, tab, nl);
}