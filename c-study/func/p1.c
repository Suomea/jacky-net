#include <stdio.h>

#define MAXLINE 100

char pattern[] = "ould";

int get_line(char*, int);

int strindex(char*, char*);

int main() {

    char line[MAXLINE];

    while(get_line(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
        }
    }
}

int get_line(char *line, int lim) {
    int c;
    int i = 0;

    while(--lim > 0 && (c = getchar()) != '\n' && c != EOF) {
        line[i++] = c;
    }

    if (c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

int strindex(char *line, char *p) {
    int i, j, k;

    for(i = 0; line[i] != '\0'; i ++) {
        j = i;
        k = 0;

        while (p[k] != '\0' && line[j] == p[k]) {
            j ++;
            k ++;
        }

        if (k > 0 && p[k] == '\0') {
            return i;
        }
    }
    return -1;
}