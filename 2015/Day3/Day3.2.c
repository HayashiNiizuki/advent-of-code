#include <stdio.h>

int main() {
  char m;
  int grid[1 << 16][2];

  for (int i = 0; i < 1 << 16; i++) {
    grid[i][0] = 0;
    grid[i][1] = 0;
  }

  int x = 0, y = 0;
  int sx = 0, sy = 0;
  int rx = 0, ry = 0;
  int received = 1;

  int j = 0;
  while ((m = getchar()) != '\n' && m != EOF) {
    j++;
    if (m == '^') {
      if (j % 2)
        sy++;
      else
        ry++;
    } else if (m == '<') {
      if (j % 2)
        sx--;
      else
        rx--;
    } else if (m == 'v') {
      if (j % 2)
        sy--;
      else
        ry--;
    } else if (m == '>') {
      if (j % 2)
        sx++;
      else
        rx++;
    } else {
      continue;
    }

    if (j % 2) {
      x = sx;
      y = sy;
    } else {
      x = rx;
      y = ry;
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