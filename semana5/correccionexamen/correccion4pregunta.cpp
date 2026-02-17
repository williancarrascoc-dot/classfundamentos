#include <iostream>
#include <cstring>
using namespace std;
struct Item {
    char* descripcion;
    int cantidad;
    double precioUnitario;
};
struct Pedido {
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};
Item crearItem(const char* descripcion, int cantidad, double precio) {
    Item it;
    it.cantidad = cantidad;
    it.precioUnitario = precio;
    it.descripcion = new char[strlen(descripcion) + 1];
    strcpy(it.descripcion, descripcion);
    return it;
}
Pedido* crearPedido(int numero, const char* cliente, int cantidadItems) {
    Pedido* p = new Pedido;
    p->numeroPedido  = numero;
    p->cantidadItems = cantidadItems;
    p->nombreCliente = new char[strlen(cliente) + 1];
    strcpy(p->nombreCliente, cliente);
    p->items = new Item[cantidadItems];
    p->items[0] = crearItem("Laptop \"",    1, 100);
    p->items[1] = crearItem("Mouse ",   2,  200);
    p->items[2] = crearItem("Teclado ",    3, 300);
    return p;
}
double calcularTotal(const Pedido* p) {
    double total = 0;
    for (int i = 0; i < p->cantidadItems; i++)
        total += p->items[i].cantidad * p->items[i].precioUnitario;
    return total;
}
Item* itemMasCaro(Pedido* p) {
    Item* masCaro = &p->items[0];
    for (int i = 1; i < p->cantidadItems; i++) {
        if (p->items[i].precioUnitario > masCaro->precioUnitario)
            masCaro = &p->items[i];
    }
    return masCaro;
}
void liberarPedido(Pedido* p) {
    for (int i = 0; i < p->cantidadItems; i++)
        delete[] p->items[i].descripcion;
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}
int main() {
    Pedido* pedido = crearPedido(101, "Carlos Perez", 3);
    cout << " DETALLE DEL PEDIDO " << endl;
    cout << "Pedido N°  : " << pedido->numeroPedido  << endl;
    cout << "Cliente    : " << pedido->nombreCliente  << endl;
    cout << "Items      : " << pedido->cantidadItems  << endl;
    cout << "\n--- Items ---" << endl;
    for (int i = 0; i < pedido->cantidadItems; i++) {
        cout << "\n[" << i + 1 << "] " << pedido->items[i].descripcion << endl;
        cout << "    Cantidad      : " << pedido->items[i].cantidad       << endl;
        cout << "    Precio unit.  : $" << pedido->items[i].precioUnitario << endl;
        cout << "    Subtotal      : $" << pedido->items[i].cantidad * pedido->items[i].precioUnitario << endl;
    }
    cout << "\n TOTAL DEL PEDIDO " << endl;
    cout << "Total: $" << calcularTotal(pedido) << endl;
    cout << "\n ITEM MAS CARO " << endl;
    Item* caro = itemMasCaro(pedido);
    cout << "Descripcion  : " << caro->descripcion    << endl;
    cout << "Precio unit. : $" << caro->precioUnitario << endl;
    liberarPedido(pedido);
    cout << "\nMemoria liberada correctamente." << endl;
    return 0;
}