#include <stdio.h>

int str_len(char *s);

int main() {
    char s1[] = {'a', 'b', 'd', '\0'};
    char *s2 = "hello world!";
    
    printf("s1 len: %d\n", str_len(s1 + 1));    // 2
    printf("s2 len: %d\n", str_len(s2));    // 12
}

int str_len(char *s) {
    int n;
    for(n = 0; *s != '\0'; s ++) {
        n ++;
    }
    return n;
}