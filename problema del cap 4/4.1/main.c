#include <stdio.h>

/* Cubo -1.
El programa calcula el cubo de los 10 primeros n�meros naturales utilizando una funci�n.
Se utiliza una variable global para la soluci�n del problema, aunque esto no es muy recomendable. */

int cubo(void); // Prototipo de funci�n.
int I; // Variable global.

int main(void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo(); // Llamada a la funci�n cubo.
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
    return 0; // A�adido retorno de 'main'.
}

int cubo(void) // Declaraci�n de la funci�n.
// La funci�n calcula el cubo de la variable global I.
{
    return I * I * I;
}
