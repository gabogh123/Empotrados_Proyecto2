#include <cstdlib> // Para system()
#include <iostream>

int main() {
    // Llamar al script de Python para aplicar el filtro negativo
    std::cout << "Aplicando filtro negativo..." << std::endl;
    int result = system("python3 negative.py");
    if (result != 0) {
        std::cerr << "Error al aplicar el filtro negativo" << std::endl;
        return 1; // Termina si hay un error
    }

    // Llamar al script de Python para aplicar el filtro suavizado
    std::cout << "Aplicando filtro suavizado..." << std::endl;
    result = system("python3 smoothed.py");
    if (result != 0) {
        std::cerr << "Error al aplicar el filtro suavizado" << std::endl;
        return 1; // Termina si hay un error
    }

    std::cout << "Filtros aplicados con éxito." << std::endl;
    return 0; // Éxito
}

