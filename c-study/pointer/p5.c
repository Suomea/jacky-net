#include <stdio.h>
#define MAXLEN 1000

char *alloc(int);

int get_line(char *line, int lim) {
    
    int c, i;
    for (i = 0; i < lim && (c = getchar()) != '\n' && c != EOF; i ++) {
        *(line + i) = c;
    }
    
    if (c == '\n') {
        *(line + i) = '\n';
        i++;
    }
    
    *(line + i) = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    
    char *p, line[MAXLEN];
    
    nlines = 0;
    while((len = get_line(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines ++] = p;
        }
    }
    
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    
    for(i = 0; i < nlines; i ++) {
        printf("%s\n", lineptr[i]);
    }
}