#include <stdio.h>

/* Programa Múltiplo.
Determina si el segundo número entero ingresado es múltiplo del primero. */

int esMultiplo(int, int); // Prototipo de función.

int main(void)
{
    int num1, num2, resultado;

    // Solicitar al usuario que ingrese dos números
    printf("Ingresa los dos numeros: ");
    scanf("%d %d", &num1, &num2);

    // Llamada a la función esMultiplo
    resultado = esMultiplo(num1, num2);

    // Imprimir si el segundo número es múltiplo del primero
    if (resultado)
        printf("El segundo numero es multiplo del primero\n");
    else
        printf("El segundo numero no es multiplo del primero\n");

    return 0; // Añadido retorno de 'main'.
}

int esMultiplo(int n1, int n2) // Implementación de la función.
// Determina si n2 es múltiplo de n1.
{
    return (n2 % n1) == 0; // Simplificación del retorno.
}
