#include "thread.h"

#define N 100000

long sum = 0;

int xchg(int volatile *ptr, int newval) {
  int result;
  asm volatile(
    "lock xchgl %0, %1"
    : "+m"(*ptr), "=a"(result)
    : "1"(newval)
    : "memory"
  );
  return result;
}

int locked = 0;

void lock() {
  while (xchg(&locked, 1)) ;
}

void unlock() {
  xchg(&locked, 0);
}

void Tsum() {
  for (int i = 0; i < N; i++) {
    lock();
    sum++;
    unlock();
  }
}

int main() {
  create(Tsum);
  create(Tsum);
  join();
  printf("sum = %ld\n", sum);
}