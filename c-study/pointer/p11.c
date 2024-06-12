#include <stdio.h>

int main(int argc, char **argv) {
    
    while(argc-- > 0) {
        printf((argc > 0 ? "%s " : "%s\n"), *(argv++));
    }
    
    char *pmsg = "hello";
    char amsg[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("pmsg: %s, amsg: %s\n", pmsg, amsg);        // pmsg: hello, amsg: hello
    printf("pmsg: %c, amsg: %c\n", *pmsg, *amsg);      // pmsg: h, amsg: h
    printf("pmsg: %c, amsg: %c\n", pmsg[0], amsg[0]);  // pmsg: h, amsg: h
    
    char *p[] = {
        "hello",
        "nihao"
    };
    char a[][6] = {
        {'h', 'e', 'l', 'l', 'o', '\0'},
        {'n', 'i', 'h', 'a', 'o', '\0'}
    };
    printf("a: %s, p: %s\n", *(p+1), a[1]);     // a: nihao, p: nihao
    printf("a: %c, p: %c\n", **(p+1), *a[1]);   // a: n, p: n
    printf("a: %c, p: %c\n", *p[1], a[1][0]);   // a: n, p: n
}