#include<iostream>
#include<ctime>
#include<cstring>
#include<cctype>
#include<cstdlib>
using namespace std;
struct selecciones{
    string nombre;
    int ganados;
    int empatados;
    int perdidos;
    int golfavor=0;
    int golcontra=0;
    int total;
    float rendimiento;
};

void leer(selecciones* &a,const int n){
    cout<<"escribe el nombre de la seleccion: "<<endl;
    for(int i=0;i<n;i++){
        getline(cin,a[i].nombre);
    }
}
void partidos(selecciones* a,int n){
    srand(time(0));
    for(int i=0;i<n;i++){
        a[i].ganados=0+rand()%100;
        a[i].empatados=0+rand()%(100-a[i].ganados);
        a[i].perdidos=(100-a[i].ganados-a[i].empatados);
    }
}
void goles(selecciones* &a,int n){
    for(int i=0;i<n;i++){
        int w=0;
        int z=0;
        int e=0;
        int p=0;
        int x=0;
        for(int j=0;j<a[i].ganados;j++){
            w=(0+rand()%5);
            z=(0+rand()%5);
            if(w<z){
                swap(w,z);
            }
        a[i].golfavor=a[i].golfavor+w;
        a[i].golcontra=a[i].golcontra+z;
        }
        for(int k=0;k<a[i].empatados;k++){
            e=(0+rand()%5);
        a[i].golfavor=a[i].golfavor+e;
        a[i].golcontra=a[i].golcontra+e;
        }
        for(int l=0;l<a[i].perdidos;l++){
            p=(0+rand()%5);
            x=(0+rand()%5);
            if(p>x){
                swap(p,x);
            }
        a[i].golfavor=a[i].golfavor+p;
        a[i].golcontra=a[i].golcontra+x;
        }
    }
}
void total(selecciones* &a,int n){
    for(int i=0;i<n;i++){
        a[i].total=(a[i].ganados*3)+(a[i].empatados);
    }
    for(int i=0;i<n;i++){
        a[i].rendimiento=(a[i].total/3.0);
    }
}
void mostrar(selecciones* a,int n){
    cout<<"Seleccion \t PG \t PE \t PP \t GF \t GC \t DG \t Pts \t Rend(%)"<<endl;
    for(int i=0;i<n-1;i++){
       for(int j=0;j<n-i-1;j++){
            if(a[j].total<a[j+1].total){
                swap(a[j],a[j+1]);
            }
    }
}
    for(int i=0;i<n;i++){
        cout<<a[i].nombre<<" \t\t "<<a[i].ganados<<" \t "<<a[i].empatados<<" \t "<<a[i].perdidos<<" \t "<<a[i].golfavor<<" \t "<<a[i].golcontra<<" \t "<<(a[i].golfavor-a[i].golcontra)<<" \t "<<a[i].total<<" \t "<<a[i].rendimiento<<endl;
    }
    cout<<"CAMPEON: "<<a[0].nombre<<" | Puntaje: "<<a[0].total<<" | DG: "<<(a[0].golfavor-a[0].golcontra)<<" | Rendimiento: "<<a[0].rendimiento<<"%";
}




int main(){
    selecciones* a;
    const int n=5;
    a=new selecciones[n];
    leer(a,n);
    partidos(a,n);
    goles(a,n);
    total(a,n);
    mostrar(a,n);

    delete[] a;
    a=nullptr;

    return 0;
}

