#define ALLOSIZE 10000

static char allocbuf[ALLOSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    if (allocbuf + ALLOSIZE - allocp >= n) {
        allocp += n;
        
        return allocp - n;
    } else {
        return 0;
    }
}

void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + ALLOSIZE) {
        allocp = p;
    }
}