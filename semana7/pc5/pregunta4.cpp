#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Venta {
    int idventa;
    int idvendedor;
    int idproducto;
    int cantidad;
    double preciounitario;
};

struct TotalVendedor {
    int idvendedor;
    double total;
};

struct TotalProducto {
    int idproducto;
    int cantidadTotal;
};

struct VentaSospechosa {
    int idventa;
    int idvendedor;
    int idproducto;
    int cantidad;
};

int main() {
    ifstream archivo("ventas.dat", ios::in | ios::binary);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir ventas.dat" << endl;
        return 1;
    }

    Venta ventas[1000];
    TotalVendedor vendedores[500];
    TotalProducto productos[500];
    VentaSospechosa sospechosas[1000];

    int totalRegistros   = 0;
    int totalVendedores  = 0;
    int totalProductos   = 0;
    int totalSospechosas = 0;
    double montoTotal    = 0.0;

    Venta v;
    while (archivo.read(reinterpret_cast<char*>(&v), sizeof(Venta))) {
        ventas[totalRegistros++] = v;

        double monto = v.cantidad * v.preciounitario;
        montoTotal += monto;

        bool encontradoV = false;
        for (int i = 0; i < totalVendedores; i++) {
            if (vendedores[i].idvendedor == v.idvendedor) {
                vendedores[i].total += monto;
                encontradoV = true;
                break;
            }
        }
        if (!encontradoV) {
            vendedores[totalVendedores].idvendedor = v.idvendedor;
            vendedores[totalVendedores].total      = monto;
            totalVendedores++;
        }

        bool encontradoP = false;
        for (int i = 0; i < totalProductos; i++) {
            if (productos[i].idproducto == v.idproducto) {
                productos[i].cantidadTotal += v.cantidad;
                encontradoP = true;
                break;
            }
        }
        if (!encontradoP) {
            productos[totalProductos].idproducto    = v.idproducto;
            productos[totalProductos].cantidadTotal = v.cantidad;
            totalProductos++;
        }

        if (v.cantidad > 100) {
            sospechosas[totalSospechosas].idventa    = v.idventa;
            sospechosas[totalSospechosas].idvendedor = v.idvendedor;
            sospechosas[totalSospechosas].idproducto = v.idproducto;
            sospechosas[totalSospechosas].cantidad   = v.cantidad;
            totalSospechosas++;
        }
    }
    archivo.close();

    int indiceMayorVendedor = 0;
    for (int i = 1; i < totalVendedores; i++)
        if (vendedores[i].total > vendedores[indiceMayorVendedor].total)
            indiceMayorVendedor = i;

    int indiceMayorProducto = 0;
    for (int i = 1; i < totalProductos; i++)
        if (productos[i].cantidadTotal > productos[indiceMayorProducto].cantidadTotal)
            indiceMayorProducto = i;

    cout << fixed << setprecision(2);
    cout << "      REPORTE GENERAL DE VENTAS         " << endl;
    cout << "Total de registros   : " << totalRegistros << endl;
    cout << "Monto total vendido  : S/ " << montoTotal  << endl;
    cout << endl;
    cout << "VENDEDOR CON MAYOR RECAUDACION:"          << endl;
    cout << "  ID Vendedor : " << vendedores[indiceMayorVendedor].idvendedor << endl;
    cout << "  Total       : S/ " << vendedores[indiceMayorVendedor].total   << endl;
    cout << endl;
    cout << "PRODUCTO MAS VENDIDO:"                    << endl;
    cout << "  ID Producto    : " << productos[indiceMayorProducto].idproducto    << endl;
    cout << "  Total unidades : " << productos[indiceMayorProducto].cantidadTotal << endl;
    cout << endl;
    cout << "VENTAS SOSPECHOSAS (cantidad > 100): " << totalSospechosas << endl;
    for (int i = 0; i < totalSospechosas; i++) {
        cout << "  ID Venta: "    << sospechosas[i].idventa
             << " | Vendedor: "   << sospechosas[i].idvendedor
             << " | Producto: "   << sospechosas[i].idproducto
             << " | Cantidad: "   << sospechosas[i].cantidad << endl;
    }
    ofstream reporte("reporte.txt");
    if (!reporte.is_open()) {
        cerr << "Error: No se pudo crear reporte.txt" << endl;
        return 1;
    }

    reporte << fixed << setprecision(2);
    reporte << "-- REPORTE GENERAL DE VENTAS --"    << endl;
    reporte << "Total de registros: " << totalRegistros << endl;
    reporte << endl;
    reporte << "MONTO TOTAL VENDIDO:"               << endl;
    reporte << "S/ " << montoTotal                  << endl;
    reporte << endl;
    reporte << "--------------------"               << endl;
    reporte << "VENDEDOR CON MAYOR RECAUDACION:"    << endl;
    reporte << "ID vendedor: "   << vendedores[indiceMayorVendedor].idvendedor << endl;
    reporte << "Total vendido: S/ " << vendedores[indiceMayorVendedor].total   << endl;
    reporte << endl;
    reporte << "--------------------"               << endl;
    reporte << "PRODUCTO MAS VENDIDO:"              << endl;
    reporte << "ID producto: "    << productos[indiceMayorProducto].idproducto    << endl;
    reporte << "TOTAL UNIDADES: " << productos[indiceMayorProducto].cantidadTotal << endl;
    reporte << endl;
    reporte << "--------------------"               << endl;
    reporte << "VENTAS SOSPECHOSAS (CANTIDAD>100)"  << endl;
    reporte << endl;
    for (int i = 0; i < totalSospechosas; i++) {
        reporte << "ID venta: "    << sospechosas[i].idventa
                << " | vendedor: " << sospechosas[i].idvendedor
                << " | producto: " << sospechosas[i].idproducto
                << " | cantidad: " << sospechosas[i].cantidad << endl;
    }
    if (totalSospechosas == 0)
        reporte << "No se detectaron ventas sospechosas." << endl;

    reporte.close();
    cout << endl << "Reporte generado: reporte.txt" << endl;

    return 0;
}