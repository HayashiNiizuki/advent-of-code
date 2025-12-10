#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int max_index(char *label, int start, int end) {
  if (start == end - 1)
    return start;
  int pos = start;
  for (start++; start < end; start++) {
    if (label[start] > label[pos])
      pos = start;
  }
  return pos;
}

long long joltage(char label[], int digits) {
  int hits[digits];
  for (int i = 0; i < digits; i++) {
    hits[i] = max_index(label, i == 0 ? 0 : hits[i - 1] + 1,
                        strlen(label) - (digits - i) + 1);
  }
  long long sum = 0;
  for (int i = 0; i < digits; i++) {
    sum += (int)(label[hits[i]] - '0') * (pow(10, digits - i - 1));
  }
  return sum;
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  long long sum = 0;
  char buf[256];

  while (fgets(buf, sizeof(buf), fp)) {
    buf[strcspn(buf, "\n")] = '\0';
    sum += joltage(buf, 12);
  }

  printf("%lld", sum);

  fclose(fp);
  return 0;
}