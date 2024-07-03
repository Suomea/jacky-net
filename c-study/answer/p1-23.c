#include <stdio.h>

void echo_quote(int);

int main() {
    printf("hello \" world!\n");
    printf("// helloworld /* nihaos */ \n");
    int c;
    // hello world
    /*
        hello world // 
        ' '
        "hello world"
    */
    int d;
    while((c = getchar()) != EOF) {
        if(c == '/') {
            if((d = getchar()) == '*') {
                c = getchar();
                d = getchar();
                while(c != '*' || d != '/') {
                    c = d;
                    d = getchar();
                }
            } else if(d == '/') {
                while((c = getchar()) != EOF && c != '\n')
                    ;
                if(c == '\n') {
                    putchar(c);
                }
            } else {
                putchar(c);
                putchar(d);
            }
        }  else if(c == '\'' || c == '"') {
            echo_quote(c);
        } else {
            putchar(c);
        }
    }
}

void echo_quote(int c) {
    int d;
    putchar(c);
    
    while((d = getchar()) != c) {
        putchar(d);
        if(d == '\\') {
            putchar(getchar());
        }
    }
    
    putchar(d);
}