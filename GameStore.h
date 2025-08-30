//
// Created by ng573 on 29/08/2025.
//

#ifndef INC_4_CAL_TIENDA_VIDEOJ_NICKGOM03_GAMESTORE_H
#define INC_4_CAL_TIENDA_VIDEOJ_NICKGOM03_GAMESTORE_H

#include <string>

void mostrarCatalogoJuegos();
int leerCodigoJuego();
int leerCantidadJuegos();
string obtenerNombreJuego(int codigoJuego);
int obtenerPrecioJuego(int codigoJuego);
string obtenerPlataforma(int codigoJuego);
string obtenerCategoria(int codigoJuego);
void agregarJuegoAlCarrito(int codigos[], int cantidades[], int &cantidadJuegosRegistrados);
double calcularSubtotalCarrito(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
int leerTipoCliente();
double obtenerPorcentajeDescuento(int tipoCliente);
double calcularDescuentosAdicionales(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados);
double calcularTotalFinal(double subtotal, double porcentajeDescuento, double descuentosAdicionales);
void mostrarResumenCompra(const int codigos[], const int cantidades[], int cantidadJuegosRegistrados, double porcentajeDescuento);
void cargarCompraDemo(int codigos[], int cantidades[], int &cantidadJuegosRegistrados);

#endif //INC_4_CAL_TIENDA_VIDEOJ_NICKGOM03_GAMESTORE_H
