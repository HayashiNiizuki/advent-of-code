#include <stdio.h>

int main() {
  char c;
  int floor = 0;

  char in[65536];
  FILE *fp = fopen("input.txt", "r");
  fgets(in, sizeof(in), fp);

  int i = 0;
  while ((c = in[i++]) != '\n' && c != EOF) {
    if (c == '(') {
      floor++;
    } else if (c == ')') {
      floor--;
    }
  }

  printf("%d", floor);
}