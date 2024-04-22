#include <stdio.h>
#include <math.h>
#include <string.h>

// Definición de la estructura para almacenar datos del vehículo
struct precio
{
    int mantenimiento;
    int seguro;
    int gomas;
    float gomakm;
    int carro;
    char nombrecar[50];
    int timmant;
    int timcar;
};

// Definición de la estructura para almacenar precios de diferentes tipos de gasolina
struct gasolina
{
    float gasolina_premium;
    float gasolina_regular;
    float gasoil_regular;
    float gasoil_optimo;
    float avtur;
    float kerosene;
    float fuel_oil_6;
    float fuel_oil_1S;
    float glp;
    float gas_natural;
};

// Variable global para almacenar los kilómetros recorridos en el viaje
float klm;

// Prototipo de la función para grabar datos del vehículo en un archivo
void grabar_datos(FILE *);

// Prototipo de la función para calcular el costo del viaje
void calcular_costo(FILE *, FILE *, FILE *);

// Función principal
int main()
{
    FILE *archivo;
    FILE *cos;
    FILE *par;
    char nom[50] = "";
    int res;

    // Bucle principal del programa
    do
    {
        printf("\n\nHola!");
        printf("\n\nQue quieres hacer?\n1. Calcular el costo de viaje \n2. Introducir datos sobre tu vehiculo\n3. Salir\
               \n\nIntroduce el numero corresponiente: ");
        scanf("%d", &res);

        switch (res)
        {
            case 2:
                archivo = fopen("Datos_sobre_el_vehiculo.txt", "w");
                if (archivo != NULL)
                {
                    grabar_datos(archivo); // Llama a la función para grabar datos del vehículo
                    fclose(archivo);
                }
                else
                {
                    printf("Error al abrir el archivo para escritura.");
                    return 0;
                }
                break;

            case 1:
                printf("\nQue nombre le quieres poner al archivo: ");
                scanf("%s", nom);
                cos = fopen(nom, "w");
                par = fopen("Detalles_sobre_el_vehiculo.txt", "w+");
                archivo = fopen("Datos_sobre_el_vehiculo.txt", "r");
                if ((archivo != NULL) && (cos != NULL) && (par != NULL))
                {
                    calcular_costo(cos, archivo, par); // Llama a la función para calcular el costo del viaje
                    fclose(archivo);
                    fclose(cos);
                    fclose(par);
                }
                else
                {
                    printf("Error al abrir el archivo para lectura.");
                    return 1;
                }
                break;

            case 3:
                res = 0;
                break;

            default:
                printf("\nEse valor no esta permitido");
                break;
        }
    }
    while (res < 3 && res >= 1);

    return 0;
}

// Función para grabar datos del vehículo en un archivo
void grabar_datos(FILE *archivo)
{
    struct precio pr;

    printf("Cuanto pagas de..?");
    printf("\nMantenimiento: ");
    scanf("%d", &pr.mantenimiento);
    printf("\nCuantas veces al ano llevas el vehiculo a mantenimiento: ");
    scanf("%d", &pr.timmant);
    printf("\nSeguro: ");
    scanf("%d", &pr.seguro);
    printf("\nPrecio de las gomas: ");
    scanf("%d", &pr.gomas);
    printf("\nCada cuantos kilometros tienes que cambiar las gomas: ");
    scanf("%f", &pr.gomakm);
    printf("\nVehiculo: ");
    scanf("%d", &pr.carro);
    printf("\nCual es el modelo de tu vehiculo: ");
    scanf("%s", pr.nombrecar);
    printf("\nEn cuantos anos terminas de pagar el vehiculo: ");
    scanf("%d", &pr.timcar);

    fwrite(&pr, sizeof(struct precio), 1, archivo);
}

// Función para calcular el costo del viaje
void calcular_costo(FILE *im, FILE *lee, FILE *para)
{
    struct precio pr;
    int likm;
    float gal = 0.264172;
    float depreciacion = 700000;
    float kman = 20000;
    fread(&pr, sizeof(struct precio), 1, lee);

    printf("\n\tUsted paga %d de mantenimiento %d veces al ano", pr.mantenimiento, pr.timmant);
    printf("\n\n\tUsted paga %d de seguro", pr.seguro);
    printf("\n\n\tUsted paga %d en sus gomas cada %.1f kilometros", pr.gomas, pr.gomakm);
    printf("\n\n\tSu %s cuesta %d", pr.nombrecar, pr.carro);
    printf("\n\n\tUsted termina de pagar su vehiculo en %d anos", pr.timcar);

    fprintf(para, "\n\tUsted paga %d de mantenimiento %d veces al ano", pr.mantenimiento, pr.timmant);
    fprintf(para, "\n\n\tUsted paga %d de seguro", pr.seguro);
    fprintf(para, "\n\n\tUsted paga %d en sus gomas cada %.1f kilometros", pr.gomas, pr.gomakm);
    fprintf(para, "\n\n\tSu %s cuesta %d", pr.nombrecar, pr.carro);
    fprintf(para, "\n\n\tUsted termina de pagar su vehiculo en %d anos", pr.timcar);

    struct gasolina as;

    int gon = 20000;

    int gas;
    char tipo[50];
    float cam;

    as.gasolina_premium = 290.1;
    as.gasolina_regular = 272.5;
    as.gasoil_regular = 221.6;
    as.gasoil_optimo = 239.10;
    as.avtur = 194.89;
    as.kerosene = 225.40;
    as.fuel_oil_6 = 159.87;
    as.fuel_oil_1S = 173.72;
    as.glp = 132.60;
    as.gas_natural = 43.97;

    printf("\n\nCuantos kilometros recorridos quieres calcular? ");
    scanf("%f", &klm);
    printf("\nQue tipo de gasolina usaste para ese viaje...? ");
    printf("\n1. Gasolina Premium \n2. Gasolina Regular \n3. Gasoil Regular \
           \n4. Gasoil Optimo \n5. Avtur \n6.Kerosene \n7. Fuel Oil #6\n8. Fuel Oil 1S \
           \n9. Gas Licuado de petroleo (GLP) \n10. Gas Natural");
    printf("\nIngrese el numero: ");
    scanf("%d", &gas);

    switch (gas)
    {
        case 1:
            strcpy(tipo, "Gasolina Premium");
            cam = as.gasolina_premium;
            break;
        case 2:
            strcpy(tipo, "Gasolina Regular");
            cam = as.gasolina_regular;
            break;
        case 3:
            strcpy(tipo, "Gasoil Regular");
            cam = as.gasoil_regular;
            break;
        case 4:
            strcpy(tipo, "Gasoil Optimo");
            cam = as.gasoil_optimo;
            break;
        case 5:
            strcpy(tipo, "Avtur");
            cam = as.avtur;
            break;
        case 6:
            strcpy(tipo, "Kerosene");
            cam = as.kerosene;
            break;
        case 7:
            strcpy(tipo, "Fuel Oil #6");
            cam = as.fuel_oil_6;
            break;
        case 8:
            strcpy(tipo, "Fuel Oil 1S");
            cam = as.fuel_oil_1S;
            break;
        case 9:
            strcpy(tipo, "Gasolina Licuada de petroleo(GLP)");
            cam = as.glp;
            break;
        case 10:
            strcpy(tipo, "Gas Natural");
            cam = as.gas_natural;
            break;
        default:
            printf("\nEse valor no es admitido");
            return;
    }
    fprintf(im, "\n");
    fprintf(im, "| Kilometros recorridos: %f |\tTipo de gasolina: %s|", klm, tipo);
    fprintf(im, "\n");

    fprintf(im, "\n\n");
    fprintf(im, "|consumo    Costo por km \tkm por galon \tTotal del viaje           |\n");

    printf("\n\n");
    printf("\n|consumo    Costo por km \tkm por galon \tTotal del viaje           |\n");

    for (likm = 8; likm <= 16; likm++)
    {
        float gal2 = likm * gal;
        float r = gal2 / 100;
        float kmga = cam * r;

        float carto = pr.carro - depreciacion;
        carto = carto / pr.timcar;
        float manto = pr.mantenimiento * pr.timmant;

        float len = kman / pr.gomakm;
        float goma = ceil(len);
        float gomas = pr.gomas * goma;

        float cokm = (carto + manto + pr.seguro + gomas) * pr.timcar;
        cokm = cokm / kman * pr.timcar;

        float total_viaje = cokm * kmga;

        printf("\n");
        printf("    %dL / 100 km \t%.3f  \tRD$%.3f  \tRD$%.3f \n", likm, cokm, kmga, total_viaje);
        printf("\n");

        fprintf(im, "    %dL / 100 km \t%.3f  \tRD$%.3f  \tRD$%.3f      \n", likm, cokm, kmga, total_viaje);
        fprintf(im, "\n");
    }
}

