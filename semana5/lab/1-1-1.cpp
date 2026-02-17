#include<iostream>
using namespace std;
struct alumno{
    int nota;
};

void leer(alumno* &a,int n){
    cout<<"escribe las nota de los alumnos: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"alumno "<<i+1<<": ";cin>>a[i].nota;
    }
}
void max(alumno* a,int n){
    int max=0;
    for(int i=0;i<n;i++){
        if(a[i].nota>max){
            max=a[i].nota;
        }
    }
    cout<<"la nota mas es: "<<max<<endl;
}
void promedio(alumno* a,int n){
    int promedio=0;
    for(int i=0;i<n;i++){
        promedio+=a[i].nota;
    }
    promedio=promedio/n;
    cout<<"el promedio es: "<<promedio;
}
int main(){
    int n;
    alumno* a;
    cout<<"escribe la cantidad de estudiantes: "<<endl; cin>>n;
    a=new alumno[n];
    leer(a,n);
    max(a,n);
    promedio(a,n);
    delete[] a;
    a=nullptr;

    return 0;
}