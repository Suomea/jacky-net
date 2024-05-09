#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int maxline);
void copy(char from[], char to[]);

int main() {
    int len;
    int max;
    
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    if (max > 0) {
        printf("%s", longest);
    }

    return 0;
}

int get_line(char s[], int lim) {
    int c, i;
    
    for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i ++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i ++;
    }

    s[i] = '\0';
    return i;
}

void copy(char from[], char to[]) {
    int i;

    for(i = 0; (to[i] = from[i]) != '\0'; i ++) {
        ;
    }
}