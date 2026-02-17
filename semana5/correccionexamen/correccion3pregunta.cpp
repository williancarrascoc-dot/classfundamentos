#include <iostream>
#include <cstring>
using namespace std;
struct Producto {
    int codigo;
    char* nombre;
    double precio;
    int stock;
};
Producto crearProducto(int codigo, const char* nombre, double precio, int stock) {
    Producto p;
    p.codigo = codigo;
    p.precio = precio;
    p.stock = stock;
    p.nombre = new char[strlen(nombre) + 1];
    strcpy(p.nombre, nombre);
    return p;
}
Producto* crearInventario(int n) {
    Producto* inventario = new Producto[n];
    inventario[0] = crearProducto(101, "Teclado",      10.5, 5);
    inventario[1] = crearProducto(102, "Mouse",  21,  10);
    inventario[2] = crearProducto(103, "Monitor",      31.5, 15);
    inventario[3] = crearProducto(104, "Laptop",     42,  20);
    inventario[4] = crearProducto(105, "Impresora",  52.5,  25);
    return inventario;
}
Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado) {
    for (int i = 0; i < n; i++) {
        if (inventario[i].codigo == codigoBuscado)
            return &inventario[i];
    }
    return nullptr;
}
void liberarInventario(Producto* inventario, int n) {
    for (int i = 0; i < n; i++)
        delete[] inventario[i].nombre;
    delete[] inventario;
}
void mostrarProducto(Producto* p) {
    cout << "  Codigo : " << p->codigo  << endl;
    cout << "  Nombre : " << p->nombre  << endl;
    cout << "  Precio : $" << p->precio << endl;
    cout << "  Stock  : " << p->stock   << endl;
}
int main() {
    int n = 5;
    cout << "INVENTARIO:" << endl;
    Producto* inventario = crearInventario(n);
    for (int i = 0; i < n; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;
        mostrarProducto(&inventario[i]);
    }
    cout << "\n=== BUSCAR CODIGO 103 ===" << endl;
    Producto* encontrado = buscarProducto(inventario, n, 103);
    if (encontrado != nullptr) {
        cout << "Producto encontrado:" << endl;
        mostrarProducto(encontrado);
    } else {
        cout << "Producto no encontrado." << endl;
    }
    cout << "\n=== BUSCAR CODIGO 999 ===" << endl;
    Producto* noEncontrado = buscarProducto(inventario, n, 999);
    if (noEncontrado != nullptr) {
        mostrarProducto(noEncontrado);
    } else {
        cout << "Producto no encontrado." << endl;
    }
    liberarInventario(inventario, n);
    cout << "\nMemoria liberada correctamente." << endl;
    return 0;
}