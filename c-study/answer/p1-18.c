#include <stdio.h>
#include <string.h>

#define MAXLINE 100

int get_line(char *, int);
void remove_end_blank(char *, int);

int main() {
    char line[MAXLINE];
    
    int len;
    while((len = get_line(line, MAXLINE)) > 0) {
        printf("str len: %d, str: %s", strlen(line), line);
        remove_end_blank(line, MAXLINE);
        if(line[0] != '\n') {
            printf("str len: %d, str: %s", strlen(line), line);
        }
    }   
}

void remove_end_blank(char line[], int max) {
    int i;
    for(i = 0; i < max && line[i] != '\0'; i ++);
    
    for(i = i - 1; i >= 0 && (line[i] == '\t' || line[i] == ' ' || line[i] == '\n'); i--);
    
    line[i + 1] = '\n';
    line[i + 2] = '\0';
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
        line[i++] = '\n';
        l++;
    }
    
    line[i] = '\0';
    return l;
}