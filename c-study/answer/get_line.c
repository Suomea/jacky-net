#include <stdio.h>

int get_line(char *line, int lim) {
    int c;
    int i = 0, l = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if(i < lim - 2) {
            line[i++] = c;
        }
        
        l ++;
    } 
    
    if(c == '\n') {
        line[i++] = '\n';
        l ++;
    }
    
    line[i] = '\0';
    
    return l;
}