#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int paper(int w, int l, int h) {
  if (w > l)
    swap(&w, &l);

  if (l > h)
    swap(&l, &h);

  if (w > h)
    swap(&w, &h);

  return 2 * w * l + 2 * w * h + 2 * h * l + w * l;
}

int main() {
  int w, l, h;
  int area = 0;
  while (1) {
    scanf("%dx%dx%d", &w, &l, &h);
    area += paper(w, l, h);
    printf("Area: %d\n", area);
  }

  return 0;
}