#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int ribbon(int w, int l, int h) {
  if (w > l)
    swap(&w, &l);

  if (l > h)
    swap(&l, &h);

  if (w > h)
    swap(&w, &h);

  return 2 * (w + l) + w * l * h;
}

int main() {
  int w, l, h;
  int length = 0;
  while (1) {
    scanf("%dx%dx%d", &w, &l, &h);
    length += ribbon(w, l, h);
    printf("Length: %d\n", length);
  }

  return 0;
}