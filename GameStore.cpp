//
// Created by ng573 on 29/08/2025.
//
#include "GameStore.h"
#include <iostream>
#include <iomanip>
#include <string>

// --- Catálogo fijo de juegos ---
const int NUM_JUEGOS = 6;

const int CODIGOS[NUM_JUEGOS]     = {101, 102, 103, 104, 105, 106};
const std::string NOMBRES[NUM_JUEGOS]    = {"FIFA 25", "Zelda TOTK", "GTA V", "Rise Of Empires", "Need For Speed", "Mario Kart 8"};
const double PRECIOS[NUM_JUEGOS]  = {60.0, 70.0, 50.0, 55.0, 62.0, 48.0};
const std::string PLATAFORMAS[NUM_JUEGOS]= {"PS5", "Switch", "Xbox", "PC", "PS5", "Switch"};
const std::string CATEGORIAS[NUM_JUEGOS] = {"Deportes", "Aventura", "Accion", "Estrategia", "Carreras", "Carreras"};

// --- Función auxiliar: busca índice de un código ---
int indicePorCodigo(int codigo) {
    for (int i = 0; i < NUM_JUEGOS; i++) {
        if (CODIGOS[i] == codigo) return i;
    }
    return -1; // no existe
}

// --- Mostrar catálogo ---
void mostrarCatalogoJuegos() {
    std::cout << "\n=== Catalogo de Juegos ===\n";
    for (int i = 0; i < NUM_JUEGOS; i++) {
        std::cout << CODIGOS[i] << " - " << NOMBRES[i]
                  << " (" << PLATAFORMAS[i] << ", " << CATEGORIAS[i] << ") "
                  << "$" << std::fixed << std::setprecision(2) << PRECIOS[i]
                  << "\n";
    }
}

// --- Lecturas de usuario ---
int leerCodigoJuego() {
    int c;
    std::cout << "Codigo del juego: ";
    std::cin >> c;
    return c;
}

int leerCantidadJuegos() {
    int q;
    std::cout << "Cantidad: ";
    std::cin >> q;
    if (q < 1) q = 1; // validación mínima
    return q;
}

// --- Obtener información ---
std::string obtenerNombreJuego(int codigo) {
    int k = indicePorCodigo(codigo);
    return (k == -1) ? "DESCONOCIDO" : NOMBRES[k];
}

double obtenerPrecioJuego(int codigo) {
    int k = indicePorCodigo(codigo);
    return (k == -1) ? 0.0 : PRECIOS[k];
}

std::string obtenerPlataforma(int codigo) {
    int k = indicePorCodigo(codigo);
    return (k == -1) ? "N/A" : PLATAFORMAS[k];
}

std::string obtenerCategoria(int codigo) {
    int k = indicePorCodigo(codigo);
    return (k == -1) ? "N/A" : CATEGORIAS[k];
}

// --- Carrito ---
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int &n) {
    int codigo = leerCodigoJuego();
    int idx = indicePorCodigo(codigo);
    if (idx == -1) {
        std::cout << "Codigo invalido.\n";
        return;
    }
    int cantidad = leerCantidadJuegos();

    // si ya existe en el carrito, acumula
    for (int i = 0; i < n; i++) {
        if (codigos[i] == codigo) {
            cantidades[i] += cantidad;
            std::cout << "Actualizado: " << obtenerNombreJuego(codigo)
                      << " x" << cantidades[i] << "\n";
            return;
        }
    }

    // si no existe, agregar nuevo
    codigos[n] = codigo;
    cantidades[n] = cantidad;
    n++;
    std::cout << "Agregado: " << obtenerNombreJuego(codigo)
              << " x" << cantidad << "\n";
}

// --- Calcular subtotal ---
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int n) {
    double subtotal = 0;
    for (int i = 0; i < n; i++) {
        subtotal += obtenerPrecioJuego(codigos[i]) * cantidades[i];
    }
    return subtotal;
}

// --- Tipos de cliente ---
int leerTipoCliente() {
    std::cout << "\nTipo de cliente:\n";
    std::cout << "1) Oro (15%)\n2) Plata (8%)\n3) Regular (0%)\nSeleccione: ";
    int t; std::cin >> t;
    if (t < 1 || t > 3) t = 3;
    return t;
}

double obtenerPorcentajeDescuento(int tipoCliente) {
    if (tipoCliente == 1) return 0.15;
    if (tipoCliente == 2) return 0.08;
    return 0.0;
}

// --- Descuentos adicionales ---
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int n) {
    double desc = 0;
    for (int i = 0; i < n; i++) {
        int k = indicePorCodigo(codigos[i]);
        if (k == -1) continue;

        if (PLATAFORMAS[k] == "Switch")   desc += 3.0 * cantidades[i];
        if (CATEGORIAS[k]  == "Carreras") desc += 2.0 * cantidades[i];
    }
    return desc;
}

// --- Total ---
double calcularTotalFinal(double subtotal, double pdesc, double descExtra) {
    double total = subtotal * (1.0 - pdesc) - descExtra;
    if (total < 0) total = 0;
    return total;
}

// --- Mostrar resumen ---
void mostrarResumenCompra(const int codigos[], const int cantidades[], int n, double pdesc) {
    if (n == 0) {
        std::cout << "Carrito vacio.\n";
        return;
    }

    std::cout << "\n=== Resumen del Carrito ===\n";
    for (int i = 0; i < n; i++) {
        int c = codigos[i], q = cantidades[i];
        double p = obtenerPrecioJuego(c);
        std::cout << obtenerNombreJuego(c) << " (" << c << ") - "
                  << q << " x $" << p
                  << " = $" << (p * q) << "\n";
    }
    std::cout << "Descuento por cliente: " << (pdesc * 100) << "%\n";
}

// --- Compra demo ---
void cargarCompraDemo(int codigos[], int cantidades[], int &n) {
    n = 0;
    codigos[n] = 101; cantidades[n++] = 1;
    codigos[n] = 106; cantidades[n++] = 2;
    codigos[n] = 104; cantidades[n++] = 1;
    std::cout << "Compra DEMO cargada.\n";
}
