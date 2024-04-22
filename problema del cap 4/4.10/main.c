#include <stdio.h>

/* Programa M�ltiplo.
Determina si el segundo n�mero entero ingresado es m�ltiplo del primero. */

int esMultiplo(int, int); // Prototipo de funci�n.

int main(void)
{
    int num1, num2, resultado;

    // Solicitar al usuario que ingrese dos n�meros
    printf("Ingresa los dos numeros: ");
    scanf("%d %d", &num1, &num2);

    // Llamada a la funci�n esMultiplo
    resultado = esMultiplo(num1, num2);

    // Imprimir si el segundo n�mero es m�ltiplo del primero
    if (resultado)
        printf("El segundo numero es multiplo del primero\n");
    else
        printf("El segundo numero no es multiplo del primero\n");

    return 0; // A�adido retorno de 'main'.
}

int esMultiplo(int n1, int n2) // Implementaci�n de la funci�n.
// Determina si n2 es m�ltiplo de n1.
{
    return (n2 % n1) == 0; // Simplificaci�n del retorno.
}
