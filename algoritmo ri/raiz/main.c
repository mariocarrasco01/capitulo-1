#include <stdio.h>
#include <stdlib.h>

int main()
{
    double numero = 0.0;
    double estimacion = 0.0;

    int iteraciones = 0;

    printf("C�lculo de ra�z cuadrada\n");
    printf("Ingrese el n�mero: ");
    scanf("%lf", &numero);

    estimacion = numero;

    while(!(estimacion == ( numero/estimacion)))
    {
        printf("\nIteraciones para c�lculo: %d", iteraciones);
        printf("\nLa ra�z cuadrada de %lf es: %lf", numero, estimacion);
        estimacion = 0.5 * ((numero/estimacion) + estimacion);
        iteraciones++;
        if(iteraciones >= 25)
        {
            break;
        }
    }
    return 0;
}
