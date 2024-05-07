#include <stdio.h>

int main() {

    char tmp[] = {'a', 'b', 'c', '\0', 'd', 'e', 'f'};

    printf("%s\n", tmp);    // 打印 abc

    return 0;
}