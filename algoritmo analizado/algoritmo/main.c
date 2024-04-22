#include <stdio.h>
#include <time.h>

#define ARRAY_SIZE 10

// Declaraci�n de variables
int i, cambio, n, buf;
int a[ARRAY_SIZE];
time_t semilla;

int main(int argc, char* argv[]) {
  // Inicializaci�n de la semilla del generador de n�meros aleatorios
  semilla = 0;
  srand(time(&semilla));

  // C�lculo del tama�o real del array
  n = sizeof(a) / sizeof(*a);

  // Llenado del array con n�meros aleatorios entre 0 y 999
  for (i = 0; i < n; i++) {
    a[i] = rand() % 1000;
  }

  // Impresi�n de los elementos del array antes de ordenar
  for (i = 0; i < n; i++) {
    printf("Elemento a[%d]: %d\n", i, a[i]);
  }

  // Inicio del proceso de ordenaci�n con cambio en 1
  cambio = 1;

  // Bucle para la ordenaci�n
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

        // Indicaci�n de que se ha realizado un cambio
        cambio = 1;
      }
    }
  }

  // Impresi�n de los elementos del array ya ordenados
  printf("\n----------------\n");
  for (i = 0; i < n; i++) {
    printf("Elemento a[%d]: %d\n", i, a[i]);
  }

  return 0;  // Retorno de 0 indica que el programa se ejecut� correctamente
}
