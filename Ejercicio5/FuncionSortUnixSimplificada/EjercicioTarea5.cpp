#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

void quicksort(char palabra[25][25], int izquierda, int derecha)
{
    int i;
    int j;
    char temp[25];
    char *pivot;

    i = izquierda;
    j = derecha;
    pivot = palabra[(izquierda + derecha) / 2];

    do
    {
        while ((strcmp(palabra[i], pivot) < 0) && (i < derecha))
        {
            i++;
        }
        while ((strcmp(palabra[j], pivot) > 0) && (j > izquierda))
        {
            j--;
        }
        if (i <= j)
        {
            strcpy(temp, palabra[i]);
            strcpy(palabra[i], palabra[j]);
            strcpy(palabra[j], temp);
            i++;
            j--;
        }
    } while (i <= j);

    if (izquierda < j)
    {
        quicksort(palabra, izquierda, j);
    }
    if (i < derecha)
    {
        quicksort(palabra, i, derecha);
    }
}

int main()
{
    char palabra[25][25];
    int numPalabras, izq, der, res;
    int cont = 0;
    int ch;

    do
    {
        cout << "Digite la cantidad de palabras que desea ordenar: ";
        cin >> numPalabras;
        for (int i = 0; i < numPalabras; i++)
        {
            cout << "Palabra #" << i + 1 << ": ";
            if (cont == 0)
            {
                cin.ignore();
                cont++;
            }
            cin.getline(palabra[i], 25);
        }
        izq = 0;
        der = numPalabras - 1;
        quicksort(palabra, izq, der);

        cout << endl
             << "El orden de las palabras es: " << endl;

        for (int i = 0; i < numPalabras; i++)
        {
            cout << i + 1 << ". " << palabra[i] << endl;
        }

        cout << "Desea volver a ordenar otras palabras? (SI = 1 / NO = Ctrl+d): ";
        cin >> res;

        if (res == 1)
        {
            system("cls");
            cont = 0;
        }
        else
        {
            while (EOF != (ch = getchar()))
            {
                putchar(ch);
            }
        }
    } while (res == 1);

    return 0;
}
