#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORD 20

int wordLen[MAXWORD];

int
main()
{
  int state = OUT;
  int len = 0;
  int overflow = 0;

  // 单词计数逻辑
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\n' || c == '\t' || c == ' ') {
      if (state == IN) {
        if (len <= MAXWORD) {
          wordLen[len - 1]++;
        } else {
          overflow++;
        }
      }
      len = 0;
      state = OUT;
    } else {
      if (state == OUT) {
        state = IN;
        len++;
      } else {
        len++;
      }
    }
  }

  if (state == IN) {
    if (len <= MAXWORD) {
      wordLen[len - 1]++;
    } else {
      overflow++;
    }
  }

  // 打印水平方向
  for (int i = 0; i < sizeof wordLen / sizeof(int); i++) {
    printf("%2d : ", i + 1);
    for (int j = 0; j < wordLen[i]; j++) {
      putchar('*');
    }
    printf(" %d\n", wordLen[i]);
  }

  if (overflow > 0) {
    printf("There ard %d words > %d\n", overflow, MAXWORD);
  }

  // 打印垂直方向
  int maxvalue = 0;
  for (int i = 0; i < MAXWORD; i++) {
    if (wordLen[i] > maxvalue) {
      maxvalue = wordLen[i];
    }
  }

  for (int i = maxvalue + 1; i > 0; i--) {
    for (int j = 0; j < MAXWORD; j++) {
      if (wordLen[j] == i - 1) {
        printf("%3d", i - 1);
      } else if (wordLen[j] >= i) {
        printf("  *");
      } else {
        printf("  \\");
      }
    }
    putchar('\n');
  }

  for (int i = 0; i < MAXWORD; i++) {
    printf("%3d", i + 1);
  }

  putchar('\n');
  if (overflow > 0) {
    printf("There ard %d words > %d\n", overflow, MAXWORD);
  }
}
