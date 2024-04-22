#include <stdio.h>
#include <stdlib.h>

int main()
{
    double numero = 0.0;
    double estimacion = 0.0;

    int iteraciones = 0;

    printf("Cálculo de raíz cuadrada\n");
    printf("Ingrese el número: ");
    scanf("%lf", &numero);

    estimacion = numero;

    while(!(estimacion == ( numero/estimacion)))
    {
        printf("\nIteraciones para cálculo: %d", iteraciones);
        printf("\nLa raíz cuadrada de %lf es: %lf", numero, estimacion);
        estimacion = 0.5 * ((numero/estimacion) + estimacion);
        iteraciones++;
        if(iteraciones >= 25)
        {
            break;
        }
    }
    return 0;
}
