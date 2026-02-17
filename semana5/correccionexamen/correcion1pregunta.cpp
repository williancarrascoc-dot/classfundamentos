#include <iostream>
using namespace std;
struct Polinomio {
    int grado;
    double* coeficientes; 
};
void mostrar(Polinomio p) {
    for (int i = 0; i <= p.grado; i++) {
        int exp = p.grado - i;
        if (p.coeficientes[i] != 0) {
            if (i != 0 && p.coeficientes[i] > 0) cout << " + ";
            cout << p.coeficientes[i];
            if (exp == 1) cout << "x";
            else if (exp > 1) cout << "x^" << exp;
        }
    }
    cout << endl;
}
void liberar(Polinomio& p) {
    delete[] p.coeficientes;
}
Polinomio sumar(Polinomio a, Polinomio b, Polinomio c) {
    int gradoMax = a.grado;
    if (b.grado > gradoMax) gradoMax = b.grado;
    if (c.grado > gradoMax) gradoMax = c.grado;
    Polinomio resultado;
    resultado.grado = gradoMax;
    resultado.coeficientes = new double[gradoMax + 1];
    for (int i = 0; i <= gradoMax; i++)
        resultado.coeficientes[i] = 0;
    for (int i = 0; i <= a.grado; i++)
        resultado.coeficientes[gradoMax - (a.grado - i)] += a.coeficientes[i];
    for (int i = 0; i <= b.grado; i++)
        resultado.coeficientes[gradoMax - (b.grado - i)] += b.coeficientes[i];
    for (int i = 0; i <= c.grado; i++)
        resultado.coeficientes[gradoMax - (c.grado - i)] += c.coeficientes[i];
    return resultado;
}
Polinomio multiplicarDos(Polinomio a, Polinomio b) {
    int gradoRes = a.grado + b.grado;
    Polinomio resultado;
    resultado.grado = gradoRes;
    resultado.coeficientes = new double[gradoRes + 1];
    for (int i = 0; i <= gradoRes; i++)
        resultado.coeficientes[i] = 0;
    for (int i = 0; i <= a.grado; i++) {
        for (int j = 0; j <= b.grado; j++) {
            resultado.coeficientes[i + j] += a.coeficientes[i] * b.coeficientes[j];
        }
    }
    return resultado;
}
Polinomio multiplicar(Polinomio a, Polinomio b, Polinomio c) {
    Polinomio temp = multiplicarDos(a, b);
    Polinomio resultado = multiplicarDos(temp, c);
    liberar(temp);
    return resultado;
}
int main() {
    Polinomio p1;
    p1.grado = 2;
    p1.coeficientes = new double[3]{1, 0, 3};
    Polinomio p2;
    p2.grado = 1;
    p2.coeficientes = new double[2]{-4, 5};
    Polinomio p3;
    p3.grado = 2;
    p3.coeficientes = new double[3]{3, -0, 1};
    cout << "Polinomios: " << endl;
    cout << "P1: "; mostrar(p1);
    cout << "P2: "; mostrar(p2);
    cout << "P3: "; mostrar(p3);
    cout << "\nSUMA" << endl;
    Polinomio suma = sumar(p1, p2, p3);
    cout << "Resultado: "; mostrar(suma);
    cout << "\nMULTIPLICACION" << endl;
    Polinomio producto = multiplicar(p1, p2, p3);
    cout << "Resultado: "; mostrar(producto);
    liberar(p1);
    liberar(p2);
    liberar(p3);
    liberar(suma);
    liberar(producto);
    return 0;
}