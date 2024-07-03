#include <stdio.h>
#include <string.h>
#define MAXLINE 100

int get_line(char *, int);

void revese(char *, int);

int main() {
    char line[MAXLINE];
    while(get_line(line, MAXLINE) > 0) {
        printf("str len: %d, str: %s\n", strlen(line), line);
        revese(line, MAXLINE);
        if(line[0] != '\n') {
            printf("str len: %d, str: %s", strlen(line), line);
        }
    }
}

void revese(char line[], int max) {
    int i;
    for(i = 0; i < max && (line[i] != '\n') && line[i] != '\0'; i ++) {
        printf("%c - %d\n", line[i], i);
    }
    
    int right = i - 1, left = 0;
    while(left < right) {
        int tmp = line[left];
        line[left] = line[right];
        line[right] = tmp;
        
        left ++;ccc 
        right --;
    }
}

int get_line(char line[], int max) {
    int c;
    int i = 0, l = 0;
    
    while((c = getchar()) != EOF && c != '\n') {
        if(i < max - 2) {
            line[i++] = c;
        }
        l++;
    }
    
    if(c == '\n') {
        line[i] = '\n';
        l ++;
    }
    
    line[i] = '\0';
    return l;
}