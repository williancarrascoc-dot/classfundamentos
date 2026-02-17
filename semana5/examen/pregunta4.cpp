#include<iostream>
using namespace std;
/*
struct item{
    char* descripcion;
    int cantidad;
    double preciounitario;
};
struct pedido{
    int numeropedido;
    char* nombrecliente;
    item* items;
    int cantidaditems;
}
pedido* crearpedido(int numero, const char* cliente, int cantidaditems){

}
double calculartotal(const pedido* p){

}
item* itemmascaro(pedido* p){

}
void liberarpedido(pedido* p){
    
}

*/
int main(){
    //forma de imprimir
    int n=123;
    cout<<"Pedido N°: "<<n<<endl;
    cout<<"cliente: "<<endl;
    cout<<"items: "<<endl;
    for(int i=0;i<3;i++){
        cout<<"item "<<i<<"| "<<"cant: "<<i<<"| precio: "<<i<<endl;
    }

    return 0;
}