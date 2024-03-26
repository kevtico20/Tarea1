#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
{
    char palabra[100];
    int n = 0;

    cout << "Ingrese el texto: ";
    cin.getline(palabra, 100);

    while (palabra[n] != '\0')
    {
        if (palabra[n] == ' ' || palabra[n] == '\t')
        {
            for (int i = n; i < strlen(palabra); i++)
            {
                palabra[i] = palabra[i + 1];
            }
            palabra[strlen(palabra) - 1] = '\0';
        }
        else
        {
            n++;
        }
    }

    cout << endl
         << "La palabra resultante es: " << palabra << endl;
    return 0;
}
