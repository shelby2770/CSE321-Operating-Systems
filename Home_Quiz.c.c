#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;
int remaining_ticket = 10, curr_person = 1;

void *purchase_ticket(void *person)
{
    int curr = *((int *)person);
    pthread_mutex_lock(&mutex);

    while (curr != curr_person)
        pthread_cond_wait(&cv, &mutex);

    if (remaining_ticket > 0)
    {
        printf("Person %d is purchasing\nTickets left: %d\n", curr, remaining_ticket);
        sleep(1);
        remaining_ticket--;
        printf("Person %d, Purchase Done\n", curr);
        curr_person++;
    }
    else
    {
        printf("Person %d can not purchase\nTickets left: 0\nPerson %d, Purchase failed\n", curr, curr);
        curr_person++;
    }

    pthread_cond_broadcast(&cv);
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

signed main()
{
    pthread_t persons[13];

    for (int i = 1; i <= 12; ++i)
    {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&persons[i], 0, purchase_ticket, (void *)id);
    }

    for (int i = 1; i <= 12; ++i)
        pthread_join(persons[i], 0);
}