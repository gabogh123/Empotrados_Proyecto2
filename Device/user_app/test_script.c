#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion;
    printf("Bienvenido al programa de prueba\n");
    printf("Seleccione una opción:\n");
    printf("1. Ejecutar script 1\n");
    printf("2. Ejecutar script 2\n");
    printf("3. Ejecutar script 3\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            system("python script1.py");
            break;
        case 2:
            system("python script2.py");
            break;
        case 3:
            system("python script3.py");
            break;
        default:
            printf("Opción no válida\n");
            break;
    }

    return 0;
}

