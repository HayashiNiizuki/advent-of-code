#include <stdio.h>

int main() {
  char c;
  int floor = 0;
  int pos = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    if (c == '(') {
      floor++;
      pos++;
    } else if (c == ')') {
      floor--;
      pos++;
    }
    if (floor < 0) {
      printf("%d", pos);
      return 0;
    }
  }
  return 0;
}