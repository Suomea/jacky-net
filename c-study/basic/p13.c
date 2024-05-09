#include <stdio.h>

int global_var; // 定义 define

int main() {

    extern int global_var;  // 声明 declaration

    global_var = 100;

    printf("%d\n", global_var);
}