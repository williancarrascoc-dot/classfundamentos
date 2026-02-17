#include<iostream>
#include<cstring>
using namespace std;
struct curso{
    string nombre;
    int cantidad;
    float* notas;
};
void leer(curso &a){
    cout<<"escriba el nombre del curso: ";getline(cin,a.nombre);
    cout<<"cuantos notas tendra el curso?: ";cin>>a.cantidad;
    a.notas=new float[a.cantidad];
    cout<<"escribe las notas: "<<endl;
    for(int i=0;i<a.cantidad;i++){
        cin>>a.notas[i];
    }
}
void promedio(curso a){
    float promedio=0;
    for(int i=0;i<a.cantidad;i++){
        promedio=promedio+a.notas[i];
    }
    promedio=promedio/a.cantidad;
    cout<<"el promedio es: "<<promedio<<endl;
}
void min(curso a){
    float min=a.notas[0];
    for(int i=0;i<a.cantidad;i++){
        if(a.notas[i]<min){
            min=a.notas[i];
        }
    }
    cout<<"la nota minima es: "<<min<<endl;
}
void max(curso a){
    float max=a.notas[0];
    for(int i=0;i<a.cantidad;i++){
        if(a.notas[i]>max){
            max=a.notas[i];
        }
    }
    cout<<"la nota maxima es: "<<max;
}


int main(){
    curso a;
    leer(a);
    promedio(a);
    min(a);
    max(a);
    delete[] a.notas;
    a.notas=nullptr;
    return 0;
}