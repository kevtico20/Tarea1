#include <iostream>
#include <pthread.h>
using namespace std;

int arreglo[100];
int totalFibonacci = 1;

void *Fibonacci(void *numFib)
{
    int a = 0;
    int b = 1;
    int c;
    int var = *(int *)numFib;
    cout << "El Fibonacci para el número ingresado es: " << endl;
    cout << a << " " << b << " ";
    for (int i = 0; i < var - 1; i++)
    {
        c = a + b;
        arreglo[i] = c;
        cout << arreglo[i] << " ";
        a = b;
        b = c;
        totalFibonacci += arreglo[i];
    }
    cout << endl
         << "Total Fibonacci: " << totalFibonacci << endl;
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t hilo;
    int valor = atoi(argv[1]);
    pthread_create(&hilo, NULL, Fibonacci, &valor);
    pthread_join(hilo, NULL);

    exit(0);
}
