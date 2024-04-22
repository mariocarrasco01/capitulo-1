#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10

// Declaración de variables
int i, cambio, n, buf;
int a[ARRAY_SIZE];
time_t semilla;

int main(int argc, char* argv[]) {
  // Inicialización de la semilla del generador de números aleatorios
  semilla = 0;
  srand(time(&semilla));

  // Cálculo del tamaño real del array
  n = sizeof(a) / sizeof(*a);

  // Llenado del array con números aleatorios entre 0 y 999
  for (i = 0; i < n; i++) {
    a[i] = rand() % 1000;
  }

  // Impresión de los elementos del array antes de ordenar
  for (i = 0; i < n; i++) {
    printf("Elemento a[%d]: %d\n", i, a[i]);
  }

  // Inicio del proceso de ordenación con cambio en 1
  cambio = 1;

  // Bucle para la ordenación
  while (cambio == 1) {
    // Reinicio del cambio a 0 al inicio de cada pasada
    cambio = 0;

    // Bucle para comparar e intercambiar elementos adyacentes
    for (i = 0; i < n - 1; i++) {
      // Si el elemento actual es mayor que el siguiente, intercambian sus posiciones
      if (a[i] > a[i+1]) {
        buf = a[i];
        a[i] = a[i+1];
        a[i+1] = buf;

        // Indicación de que se ha realizado un cambio
        cambio = 1;
      }
    }
  }

  // Impresión de los elementos del array ya ordenados
  printf("\n----------------\n");
  for (i = 0; i < n; i++) {
    printf("Elemento a[%d]: %d\n", i, a[i]);
  }

  return 0;  // Retorno de 0 indica que el programa se ejecutó correctamente
}
