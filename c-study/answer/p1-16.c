#include <stdio.h>

#define MAXLINE 100

int get_line(char *, int);

void copy(char *, char *);

int main() {
    
    char longest[MAXLINE];
    char line[MAXLINE];
    
    int max = 0;
    int len;
    
    while((len = get_line(line, MAXLINE)) > 0) {
        if(len > max) {
            copy(line, longest);
            max = len;
        }
    }
    
    printf("longest line len: %d, content: %s", max, longest);
}

void copy(char from[], char to[]) {
    int i = 0;
    while((to[i] = from[i]) != '\0') {
        i ++;
    }
}