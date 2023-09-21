#include "thread.h"
#include "thread-sync.h"

#define N 5

mutex_t avail[N];

void Tphilosopher(int id) {
    int lhs = (id + N - 1) % N;
    int rhs = id % N;
    // lock ordering
    if (lhs > rhs) {
        int temp = lhs;
        lhs = rhs;
        rhs = temp;
    }
    while (1)
    {
        mutex_lock(&avail[lhs]);
        printf("+ %d by T%d\n", lhs, id);
        mutex_lock(&avail[rhs]);
        printf("+ %d by T%d\n", rhs, id);

        // eat

        printf("- %d by T%d\n", lhs, id);
        printf("- %d by T%d\n", rhs, id);
        mutex_unlock(&avail[lhs]);
        mutex_unlock(&avail[rhs]);   
    }
}


int main(int argc, char *argv[]) {
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&avail[i], NULL);
    }

    for (int i = 0; i < N; i++)
    {
        create(Tphilosopher);
    }

    join();
    return 0;
}