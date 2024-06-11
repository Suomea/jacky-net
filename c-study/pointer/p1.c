#include <stdio.h>

int main() {
    char *pmessage = "hello world!";
    
    // *(pmessage) = 'x';  // wrong
    
    printf("%s\n", pmessage + 1);   // ello world!
    
    
    return 0;
}