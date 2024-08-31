#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define N 5

sem_t chopstick[N];
pthread_t T[N];

void* philo(void*);
void think(int);
void eat(int);

int main() {
    int i, var[N];
    for (i = 0; i < N; i++)
        sem_init(&chopstick[i], 0, 1);

    for (i = 0; i < N; i++) {
        var[i] = i;
        pthread_create(&T[i], NULL, philo, &var[i]);
    }

    for (i = 0; i < N; i++)
        pthread_join(T[i], NULL);

    return 0;
}

void* philo(void* n) {
    while (1) {
        int ph = *(int*)n;
        think(ph);
        printf("\nPhilosopher %d is HUNGRY & wants to EAT", ph);
        printf("\nPhilosopher %d tries to pick left chopstick", ph);
        sem_wait(&chopstick[ph]);
        printf("\nPhilosopher %d has successfully picked up the left chopstick -> %d", ph, ph);
        printf("\nPhilosopher %d tries to pick the right chopstick", ph);
        sem_wait(&chopstick[(ph + 1) % N]);
        printf("\nPhilosopher %d has successfully picked up the right chopstick -> %d", ph, (ph + 1) % N);
        eat(ph);
        printf("\nPhilosopher %d has finished EATING", ph);
        sem_post(&chopstick[(ph + 1) % N]);
        printf("\nPhilosopher %d puts down the right chopstick -> %d ", ph, (ph + 1) % N);
        sem_post(&chopstick[ph]);
        printf("\nPhilosopher %d puts down the left chopstick -> %d", ph, ph);
    }
}

void eat(int ph) {
    printf("\n\tPhilosopher %d begins to EAT using Chopsticks: %d (LEFT) & %d (RIGHT)", ph, ph, (ph + 1) % N);
    sleep(1);
}

void think(int ph) {
    printf("\nPhilosopher %d is THINKING", ph);
    sleep(1);
}
