#include "liblove.c"
#include "words_c.h"
#include <time.h>

int main() {
  Keyboard kbd;
  Keyboard_(&kbd);
  setbuf(stdout, NULL);

  time_t t = time(NULL);

  int nwords = 0;
  for (;; nwords++) {
    if (!words[nwords]) {
      nwords--;
      break;
    }
  }
  printf("%d\n", nwords);

  int ntype = 0;
  int nmiss = 0;
  int nq = 20;
  for (int i = 0; i < nq; i++) {
    int n = rand() % nwords;
    const char* word = words[n];
    printf("%s (%d/%d)\n", word, i + 1, nq);

    for (int j = 0;; j++) {
      int c = word[j];
      if (!c) break;
      for (;;) {
        int k = Keyboard_inkey(&kbd);
        if (k == 0) continue;
        if (k != c) {
          putchar('\a');
          nmiss++;
          continue;
        }
        putchar(c);
        ntype++;
        break;
      }
    }
    putchar('\n');
  }

  int sec = (int)(time(NULL) - t);

  printf("\ntime: %d sec\n", sec);
  int speed = ntype * 60 / sec;
  printf("speed: %d type/min\n", speed);
  printf("ntype: %d\n", ntype);
  printf("nmiss: %d\n", nmiss);
  int score = speed - nmiss;
  printf("score: %d point (speed - nmiss)\n", score);

  Keyboard__(&kbd);
  return 0;
}
