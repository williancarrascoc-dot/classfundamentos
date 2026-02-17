#include<iostream>
using namespace std;
struct polinomio2{
    int exp5;
    int exp4;
    int exp3;
    int exp2;
    int exp1;
    int exp0;
};
struct polinomio{
    int exp2;
    int exp1;
    int exp0;
};
void sumar(polinomio*a){
    a[3].exp0=a[0].exp0+a[1].exp0+a[2].exp0;
    a[3].exp1=a[0].exp1+a[1].exp1+a[2].exp1;
    a[3].exp2=a[0].exp2+a[1].exp2+a[2].exp2;
    cout<<"polinomio 1: "<<a[0].exp2<<"x^2 + "<<a[0].exp0<<endl;
    cout<<"polinomio 2: "<<a[1].exp1<<"x^1 +"<<a[1].exp0<<endl;
    cout<<"polinomio 3: "<<a[2].exp2<<"x^2 + "<<a[2].exp0<<endl;
    cout<<"suma de los tres polinomios: ";
    cout<<a[3].exp2<<"x^2 + "<<a[3].exp1<<"x^1 +"<<a[3].exp0<<endl;
}
void producto(polinomio* a){
    polinomio2 a1;
    a1.exp5=0;
    a1.exp4=0;
    a1.exp3=a[0].exp2*a[1].exp1;
    a1.exp2=a[0].exp2*a[1].exp0;
    a1.exp1=a[0].exp0*a[1].exp1;
    a1.exp0=a[0].exp0*a[1].exp0;

    polinomio2 a2;
    a2.exp5=a1.exp3*a[2].exp2;
    a2.exp4=a1.exp2*a[2].exp2;
    a2.exp3=a1.exp1*a[2].exp2+a1.exp3*a[2].exp0;
    a2.exp2=a1.exp0*a[2].exp2+a1.exp2*a[2].exp0;
    a2.exp1=a1.exp1*a[2].exp0;
    a2.exp0=a1.exp0*a[2].exp0;
    
    cout<<"producto de los tres polinomios: ";
    cout<<a2.exp5<<"x^5 + "<<a2.exp4<<"x^4 +"<<a2.exp3<<"x^3 +"<<a2.exp2<<"x^2 + "<<a2.exp1<<"x^1 +"<<a2.exp0<<endl;
}

int main(){
    polinomio* a;
    a=new polinomio[4];
    a[0]={1,0,3};
    a[1]={0,-4,5};
    a[2]={3,0,1};
    a[3]={0,0,0};
    sumar(a);
    producto(a);


    delete[] a;
    a=nullptr;
    return 0;
}
