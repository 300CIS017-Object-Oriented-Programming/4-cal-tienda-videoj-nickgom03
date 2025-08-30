//
// Created by ng573 on 29/08/2025.
//
#include <iostream>
#include <iomanip>
#include "GameStore.h"

int main() {
    // Carrito (arreglos paralelos)
    const int MAX_JUEGOS = 100;
    int  codigos[MAX_JUEGOS]    = {0};
    int  cantidades[MAX_JUEGOS] = {0};
    int  cantidadJuegosRegistrados = 0;

    int opcion = 0;
    do {
        std::cout << "\n===== GameStore =====\n";
        std::cout << "1. Ver catalogo\n";
        std::cout << "2. Agregar juego al carrito\n";
        std::cout << "3. Ver resumen del carrito\n";
        std::cout << "4. Cargar compra DEMO\n";
        std::cout << "5. Finalizar y pagar\n";
        std::cout << "-1. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1: {
            mostrarCatalogoJuegos();
            break;
        }
        case 2: {
            agregarJuegoAlCarrito(codigos, cantidades, cantidadJuegosRegistrados);
            break;
        }
        case 3: {
            double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "\nSubtotal actual: $" << subtotal << "\n";
            mostrarResumenCompra(codigos, cantidades, cantidadJuegosRegistrados, /*porcentaje*/0.0);
            break;
        }
        case 4: {
            cargarCompraDemo(codigos, cantidades, cantidadJuegosRegistrados);
            break;
        }
        case 5: {
            if (cantidadJuegosRegistrados == 0) {
                std::cout << "No hay juegos en el carrito.\n";
                break;
            }
            const double subtotal = calcularSubtotalCarrito(codigos, cantidades, cantidadJuegosRegistrados);
            const int tipo = leerTipoCliente();
            const double pdesc = obtenerPorcentajeDescuento(tipo);
            const double descAdic = calcularDescuentosAdicionales(codigos, cantidades, cantidadJuegosRegistrados);
            const double total = calcularTotalFinal(subtotal, pdesc, descAdic);

            mostrarResumenCompra(codigos, cantidades, cantidadJuegosRegistrados, pdesc);
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Subtotal: $" << subtotal << "\n";
            std::cout << "Descuentos adicionales: -$" << descAdic << "\n";
            std::cout << "Total a pagar: $" << total << "\n\n";
            break;
        }
        case -1:
            std::cout << "Saliendo... gracias por comprar en GameStore!\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != -1);

    return 0;
}
