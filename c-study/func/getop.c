#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getch();
void ungetch(int);

int getop(char s[]) {
    int i, c;

    // 获取第一个操作字符，忽略前置的空格和 TAB
    while((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';

    // 判断字符如果是不属于数字直接返回
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }

    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-';
        }   
    }
    
    // 如果是多位数
    if (isdigit(c)) {
        while(isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    // 如果遇到小数位继续获取后续的小数部分
    if (c == '.') {
        /* code */
        while(isdigit(s[++i] = c = getch())) {
            ;
        }
    }

    s[i] = '\0';

    // 缓存多读取的下一个元素
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}