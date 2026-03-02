#include<iostream>
#include<fstream>
#include<map>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main(){
    // ── leer archivo binario ──────────────────────────
    ifstream entrada("ventas.dat", ios::binary);
    if(!entrada){
        cerr << "no se pudo abrir ventas.dat" << endl;
        return 1;
    }

    int totalRegistros;
    entrada.read(reinterpret_cast<char*>(&totalRegistros), sizeof(int));

    Venta* ventas = new Venta[totalRegistros];
    entrada.read(reinterpret_cast<char*>(ventas), sizeof(Venta) * totalRegistros);
    entrada.close();

    // ── calculos ──────────────────────────────────────
    double montoTotal = 0;
    map<int, double> totalVendedor;   // idVendedor → total recaudado
    map<int, int>    totalProducto;   // idProducto → total unidades

    for(int i = 0; i < totalRegistros; i++){
        double monto = ventas[i].cantidad * ventas[i].precioUnitario;
        montoTotal += monto;
        totalVendedor[ventas[i].idVendedor] += monto;
        totalProducto[ventas[i].idProducto] += ventas[i].cantidad;
    }

    // vendedor con mayor recaudacion
    int    idVendedorMax = -1;
    double maxVendedor   = -1;
    for(auto& par : totalVendedor){
        if(par.second > maxVendedor){
            maxVendedor   = par.second;
            idVendedorMax = par.first;
        }
    }

    // producto mas vendido
    int idProductoMax  = -1;
    int maxUnidades    = -1;
    for(auto& par : totalProducto){
        if(par.second > maxUnidades){
            maxUnidades  = par.second;
            idProductoMax = par.first;
        }
    }

    // ── mostrar en pantalla ───────────────────────────
    cout << "--- REPORTE GENERAL DE VENTAS ---" << endl;
    cout << "\nTotal de registros: " << totalRegistros << endl;

    cout << "\nMONTO TOTAL VENDIDO:" << endl;
    cout << "S/. " << montoTotal << endl;

    cout << "\n---------------------------------------" << endl;
    cout << "VENDEDOR CON MAYOR RECAUDACION:" << endl;
    cout << "ID Vendedor: " << idVendedorMax << endl;
    cout << "Total vendido: S/. " << maxVendedor << endl;

    cout << "\n---------------------------------------" << endl;
    cout << "PRODUCTO MAS VENDIDO:" << endl;
    cout << "ID Producto: " << idProductoMax << endl;
    cout << "Total unidades: " << maxUnidades << endl;

    cout << "\n---------------------------------------" << endl;
    cout << "VENTAS SOSPECHOSAS (cantidad > 100):" << endl;
    for(int i = 0; i < totalRegistros; i++){
        if(ventas[i].cantidad > 100){
            cout << "ID Venta: "   << ventas[i].idVenta
                 << " | Vendedor: " << ventas[i].idVendedor
                 << " | Producto: " << ventas[i].idProducto
                 << " | Cantidad: " << ventas[i].cantidad << endl;
        }
    }

    // ── generar reporte.txt ───────────────────────────
    ofstream salida("reporte.txt");
    if(!salida){
        cerr << "no se pudo crear reporte.txt" << endl;
        delete[] ventas;
        return 1;
    }

    salida << "--- REPORTE GENERAL DE VENTAS ---" << endl;
    salida << "\nTotal de registros: " << totalRegistros << endl;

    salida << "\nMONTO TOTAL VENDIDO:" << endl;
    salida << "S/. " << montoTotal << endl;

    salida << "\n---------------------------------------" << endl;
    salida << "VENDEDOR CON MAYOR RECAUDACION:" << endl;
    salida << "ID Vendedor: " << idVendedorMax << endl;
    salida << "Total vendido: S/. " << maxVendedor << endl;

    salida << "\n---------------------------------------" << endl;
    salida << "PRODUCTO MAS VENDIDO:" << endl;
    salida << "ID Producto: " << idProductoMax << endl;
    salida << "Total unidades: " << maxUnidades << endl;

    salida << "\n---------------------------------------" << endl;
    salida << "VENTAS SOSPECHOSAS (cantidad > 100):" << endl;
    for(int i = 0; i < totalRegistros; i++){
        if(ventas[i].cantidad > 100){
            salida << "ID Venta: "    << ventas[i].idVenta
                   << " | Vendedor: " << ventas[i].idVendedor
                   << " | Producto: " << ventas[i].idProducto
                   << " | Cantidad: " << ventas[i].cantidad << endl;
        }
    }

    salida.close();
    delete[] ventas;

    cout << "\nreporte.txt generado correctamente" << endl;
    return 0;
}