#include <stdio.h>

int main() {
  char m;
  int grid[1 << 16][2];

  for (int i = 0; i < 1 << 16; i++) {
    grid[i][0] = 0;
    grid[i][1] = 0;
  }

  int x = 0, y = 0;
  int received = 1;
  while ((m = getchar()) != '\n' && m != EOF) {
    if (m == '^') {
      y++;
    } else if (m == '<') {
      x--;
    } else if (m == 'v') {
      y--;
    } else if (m == '>') {
      x++;
    } else {
      continue;
    }

    printf("x: %d, y: %d\n", x, y);

    unsigned char finded = 0;
    int i = 0;
    while (!(grid[i][0] == 0 && grid[i][1] == 0)) {
      if ((grid[i][0] == x && grid[i][1] == y) || (x == 0 && y == 0)) {
        finded = 1;
        break;
      }
      i++;
    }

    if (!finded) {
      grid[i][0] = x;
      grid[i][1] = y;
      received++;
    }
  }

  printf("%d", received);
}