#include <inttypes.h>
#include <stdio.h>
#include <string.h>

int joltage(char label[]) {
  int a = 0, b = 0;
  for (int i = 1; i < strlen(label) - 2; i++) {
    if (label[i] > label[a]) {
      a = i;
    }
  }
  b = a + 1;
  for (int i = a + 2; i < strlen(label) - 1; i++) {
    if (label[i] > label[b]) {
      b = i;
    }
  }
  return 10 * (int)(label[a] - '0') + (int)(label[b] - '0');
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  int sum = 0;
  char buf[256];

  while (fgets(buf, sizeof(buf), fp)) {
    sum += joltage(buf);
  }

  printf("%d", sum);

  fclose(fp);
  return 0;
}