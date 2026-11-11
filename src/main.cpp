#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

struct Objeto {
    std::string nombre;
    double valor;
    double peso;
    double relacion;
};

template <typename T>
T leerNumero(const std::string& mensaje, T minimo) {
    T numero;
    std::string entrada;

    while (true) {
        std::cout << mensaje;
        std::getline(std::cin, entrada);
        std::istringstream flujo(entrada);

        if (flujo >> numero && flujo.eof() && numero >= minimo) {
            return numero;
        }

        std::cout << "Dato invalido. Intente nuevamente.\n";
    }
}

std::string leerTexto(const std::string& mensaje) {
    std::string texto;

    do {
        std::cout << mensaje;
        std::getline(std::cin, texto);

        if (texto.empty()) {
            std::cout << "El nombre no puede quedar vacio.\n";
        }
    } while (texto.empty());

    return texto;
}

void resolverMochilaFraccional() {
    const double capacidad = leerNumero<double>("Capacidad maxima de la mochila: ", 0.0);
    const int cantidad = leerNumero<int>("Cantidad de objetos: ", 0);
    std::vector<Objeto> objetos;

    for (int i = 0; i < cantidad; i++) {
        Objeto objeto;
        std::cout << "\nObjeto " << i + 1 << ":\n";
        objeto.nombre = leerTexto("Nombre: ");
        objeto.valor = leerNumero<double>("Valor: ", 0.0);
        objeto.peso = leerNumero<double>("Peso: ", std::numeric_limits<double>::min());
        objeto.relacion = objeto.valor / objeto.peso;
        objetos.push_back(objeto);
    }

    std::stable_sort(objetos.begin(), objetos.end(), [](const Objeto& primero, const Objeto& segundo) {
        return primero.relacion > segundo.relacion;
    });

    double capacidadRestante = capacidad;
    double valorTotal = 0.0;

    std::cout << "\nObjetos seleccionados:\n";
    std::cout << std::fixed << std::setprecision(2);

    for (const Objeto& objeto : objetos) {
        if (capacidadRestante <= 0.000001) {
            break;
        }

        const double pesoTomado = std::min(objeto.peso, capacidadRestante);
        const double fraccion = pesoTomado / objeto.peso;
        const double valorTomado = objeto.valor * fraccion;

        std::cout << "- " << objeto.nombre << ": " << pesoTomado << " de " << objeto.peso;
        if (fraccion == 1.0) {
            std::cout << " (completo)";
        } else {
            std::cout << " (" << fraccion * 100 << "%)";
        }
        std::cout << ", valor aportado: " << valorTomado << "\n";

        capacidadRestante -= pesoTomado;
        valorTotal += valorTomado;
    }

    std::cout << "Valor total obtenido: " << valorTotal << "\n";
}

void resolverCoberturaAntenas() {
    const int cantidad = leerNumero<int>("Cantidad de casas: ", 0);
    std::vector<long long> casas;

    for (int i = 0; i < cantidad; i++) {
        casas.push_back(leerNumero<long long>("Posicion de la casa " + std::to_string(i + 1) + ": ", 0));
    }

    const long long rango = leerNumero<long long>("Rango de cobertura R: ", 0);
    std::sort(casas.begin(), casas.end());

    std::vector<long long> antenas;
    int indice = 0;

    while (indice < cantidad) {
        const long long posicionAntena = casas[indice] + rango;
        const long long limiteCobertura = posicionAntena + rango;
        antenas.push_back(posicionAntena);

        while (indice < cantidad && casas[indice] <= limiteCobertura) {
            indice++;
        }
    }

    std::cout << "\nAntenas instaladas en las posiciones:\n";
    if (antenas.empty()) {
        std::cout << "No se ingresaron casas.\n";
    } else {
        for (long long antena : antenas) {
            std::cout << "- " << antena << "\n";
        }
    }
    std::cout << "Cantidad total de antenas: " << antenas.size() << "\n";
}

int main() {
    int opcion;

    do {
        std::cout << "\nActividad 8 - Algoritmos Voraces\n";
        std::cout << "1. Resolver mochila fraccional\n";
        std::cout << "2. Resolver cobertura de antenas\n";
        std::cout << "3. Salir\n";
        opcion = leerNumero<int>("Seleccione una opcion: ", 1);

        if (opcion == 1) {
            resolverMochilaFraccional();
        } else if (opcion == 2) {
            resolverCoberturaAntenas();
        } else if (opcion != 3) {
            std::cout << "Ingrese una opcion entre 1 y 3.\n";
        }
    } while (opcion != 3);

    std::cout << "Programa finalizado.\n";
    return 0;
}
