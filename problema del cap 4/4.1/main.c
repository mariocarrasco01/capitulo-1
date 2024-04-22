#include <stdio.h>

/* Cubo -1.
El programa calcula el cubo de los 10 primeros números naturales utilizando una función.
Se utiliza una variable global para la solución del problema, aunque esto no es muy recomendable. */

int cubo(void); // Prototipo de función.
int I; // Variable global.

int main(void)
{
    int CUB;
    for (I = 1; I <= 10; I++)
    {
        CUB = cubo(); // Llamada a la función cubo.
        printf("\nEl cubo de %d es: %d", I, CUB);
    }
    return 0; // Añadido retorno de 'main'.
}

int cubo(void) // Declaración de la función.
// La función calcula el cubo de la variable global I.
{
    return I * I * I;
}
