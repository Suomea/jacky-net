#include <stdio.h>

#define MAXLINE 10
#define PLEN 15

int get_line(char *, int);

int main() {
    int len;
    char line[MAXLINE];
    
    while((len = get_line(line, MAXLINE)) > 0) {
        if(len > PLEN) {
            printf("%s", line);
        }
    }
}

int get_line(char line[], int lim) {
    int c;
    int l = 0, i = 0;
    while((c = getchar()) != EOF && c != '\n') {
        if(l < lim - 2) {
            line[i++] = c;
        }
        l ++;
    }
    
    if(c == '\n') {
        line[i ++] = c;
        l ++;
    }
    
    line[i] = '\0';
    return l;
}