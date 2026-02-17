#include<iostream>
using namespace std;
/*
struct producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};
producto crearproducto(int codigo, char* nombre, double precio, int stock){
    producto a1;
    nombre=new char[100];
    cout<<"escrie el nombre del producto: "; cin.getline(a1.nombre,100);
    return a1;
}
producto* crearinventario(int n){
    producto* a1;
    a1=new producto[n];
    crearproducto(a1->codigo,a1->nombre,a1->precio,a1->stock);
}
producto* buscarproducto(producto* inventario, int n, int codigobuscado){
    
}
void liberarinventario(producto* inventario,int n){

}
*/ 

int main(){
    //colocar funciones 
    //crearinventario(n);

    //forma de imprimir
    int n;
    cout<<"escribe cuanto productos va a ver: "<<endl;
    cin>>n;
    cout<<"INVENTARIO"<<endl;
    for(int i=0;i<n;i++){
    cout<<"codigo: "<<" "<<"| nombre: "<<" "<<"| precio: "<<" "<<"| stock: "<<" "<<endl;
    }


    return 0;
}