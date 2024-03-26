#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
float saldo = 0;

void *depositar(void *arg)
{
    int contador = 0;
    float monto;
    srand(time(NULL));
    while (contador < 5)
    {
        pthread_mutex_lock(&lock);
        if (saldo > 200)
        {
            pthread_mutex_unlock(&lock);
            break;
        }
        monto = (rand() % 20 + 1) + 1;
        printf("Depositando $%.2f\n", monto);
        saldo += monto;
        pthread_mutex_unlock(&lock);
        sleep(1);
        contador++;
    }
    return NULL;
}

int main()
{
    int contador = 0;
    pthread_t hilos[10];
    srand(time(NULL));
    while (contador < 10)
    {
        pthread_create(&hilos[contador], NULL, depositar, NULL);
        contador++;
    }

    contador = 0;

    while (contador < 10)
    {
        pthread_join(hilos[contador], NULL);
        contador++;
    }

    printf("Balance Final de la cuenta: $%.2f\n", saldo);

    return 0;
}
