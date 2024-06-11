#include <stdio.h>

int strcmp1(char *, char *);
int strcmp2(char *, char *);

int main()
{
    char str1[] = "a!a";   
    char *str2 = "a!";
    
    printf("strcmp1 result: %d\n", strcmp1(str1, str2));
    printf("strcmp2 result: %d\n", strcmp2(str1, str2));
}

int strcmp1(char *s, char *t)
{
    int i = 0;
    while (s[i] == t[i])
    {
        if (s[i] == '\0')
        {
            return 0;
        }
        i++;
    }

    return s[i] - t[i];
}

int strcmp2(char *s, char *t)
{
    while (*s == *t)
    {
        if (*s == '\0')
        {
            return 0;
        }
        s++, t++;
    }
    return *s - *t;
}