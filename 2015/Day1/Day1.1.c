#include <stdio.h>

int main() {
  char c;
  int floor = 0;
  while ((c = getchar()) != '\n' && c != EOF) {
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
  }

  printf("%d", floor);
}