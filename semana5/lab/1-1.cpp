#include<iostream>
using namespace std;
struct alumno{
    string nombre;
    int cantidadnotas;
    int* notas;
};
struct curso{
    string nombre;
    int cantidad;
    alumno* alum;
};
int main(){
    curso a;
    cout<<"Escribe el nombre del curso: ";
    getline(cin,a.nombre);
    cout<<"Cuantos alumnos hay: ";
    cin>>a.cantidad;
    cin.ignore();
    a.alum = new alumno[a.cantidad];
    for(int i=0;i<a.cantidad;i++){
        cout<<"Alumno "<<i+1<<endl;
        cout<<"Nombre: ";
        getline(cin,a.alum[i].nombre);
        cout<<"Cantidad de notas: ";
        cin>>a.alum[i].cantidadnotas;
        a.alum[i].notas = new int[a.alum[i].cantidadnotas];
        cout<<"Ingrese las notas:"<<endl;
        for(int j=0;j<a.alum[i].cantidadnotas;j++){
            cin>>a.alum[i].notas[j];
        }
        cin.ignore();
    }
   for(int i=0;i<a.cantidad;i++){
        delete[] a.alum[i].notas;
    }
    delete[] a.alum;
    return 0;
}
