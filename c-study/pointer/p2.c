#include <stdio.h>

void str_copy1(char*, char*);
void str_copy2(char*, char*);
void str_copy3(char*, char*);

int main() {
    
    char s1[] = "hello world!";
    char t1[] = "nihao";
    
    str_copy1(s1, t1);
    printf("%s\n", s1);  // nihao
    
    char s2[] = "how much!";
    char t2[] = "duoshao";
    
    str_copy2(s2, t2);
    printf("%s\n", s2); // duoshao
    
    char s3[] = "thank you!";
    char t3[] = "tks";
    
    str_copy3(s3, t3);
    printf("%s\n", s3); // tks
}

void str_copy1(char *s, char *t) {
    int i = 0;
    
    while((s[i] = t[i]) != '\0') {
        i ++;
    }
}

void str_copy2(char *s, char *t) {
    while((*s = *t) != '\0') {
        s ++;
        t ++;
    }
}

void str_copy3(char *s, char *t) {
    while((*s ++ = *t ++) != '\0') {    // 此处也可以省略和空字符 '\0' 的比较，因为空字符的值为 0 即 false
        ;
    }
}

void strcpy(char *s, char * t) {
    while(*s ++ = *t ++) {
        ;
    }
}