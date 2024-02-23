#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <errno.h>
#include <pthread.h>

sem_t* eventopen(const char *name)
{
    if (name == NULL)
    {
        fprintf(stderr, "Eroare: Numele semaforului este NULL\n");

        return NULL;
    }

    sem_t *sem = sem_open(name, O_CREAT, 0644, 0);

    if (sem == SEM_FAILED)
    {
        perror("sem_open failed");
        exit(1);
    }

    return sem;
}

void eventclose(sem_t *sem)
{
    if (sem != NULL)
        sem_close(sem);
    else
    {
        fprintf(stderr, "Semaforul este NULL\n");

        return;
    }

}

void eventwait(sem_t *sem)
{
    int ret;

    if (sem == NULL)
    {
        fprintf(stderr, "Semaforul este NULL\n");

        return;
    }

    while (1)
    {
        ret = sem_wait(sem);

        if (ret == 0)
            break;
        else
        if (errno == EINTR)
            continue;
        else
        {
            perror("sem_wait failed");
            break;
        }

    }

}

void eventsignal(sem_t *sem, int num_signals, int* shr_val, int target_value)
{
    if (sem == NULL)
    {
        fprintf(stderr, "Eroare: Semaforul este NULL\n");

        return;
    }

    if (num_signals <= 0)
    {
        fprintf(stderr, "Eroare: Numărul de semnale trebuie să fie pozitiv\n");

        return;
    }

    while (1) {
        if (*shr_val >= target_value) {
            break;
        }
    }


    if (sem != NULL)
        for (int i = 0; i < num_signals; ++i)
            sem_post(sem);
    else
    {
        fprintf(stderr, "Semaforul este NULL\n");

        return;
    }
}


int main()
{


    return 0;
}
