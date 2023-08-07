#include "thread.h"

int x = 0, y = 0;

void T1() {
  x = 1; int t = y; // Store(x); Load(y)
//   __sync_synchronize();
  printf("%d", t);
}

void T2() {
  y = 1; int t = x; // Store(y); Load(x)
//   __sync_synchronize();
  printf("%d", t);
}

int main() {
  create(T1);
  create(T2);
  join();
}