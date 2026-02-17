#include <iostream>
#include <cstdlib>
using namespace std;

// Estructura para representar un polinomio
struct Polinomio {
    int grado;
    double *coeficientes;  // Array dinámico para los coeficientes
};

// Función para reservar memoria dinámica para un polinomio
void crearPolinomio(Polinomio &p, int grado) {
    p.grado = grado;
    p.coeficientes = new double[grado + 1];
}

// Función para liberar memoria dinámica
void liberarPolinomio(Polinomio &p) {
    delete[] p.coeficientes;
    p.coeficientes = NULL;
}

// Función para leer un polinomio
void leerPolinomio(Polinomio &p) {
    cout << "Ingrese el grado del polinomio: ";
    cin >> p.grado;
    
    crearPolinomio(p, p.grado);
    
    // Leer coeficientes en orden decreciente (desde x^grado hasta x^0)
    for(int i = p.grado; i >= 0; i--) {
        cout << "Ingrese el coeficiente de x^" << i << ": ";
        cin >> *(p.coeficientes + i);
    }
}

// Función para mostrar un polinomio
void mostrarPolinomio(Polinomio &p) {
    bool primero = true;
    
    for(int i = p.grado; i >= 0; i--) {
        double coef = *(p.coeficientes + i);
        
        if(coef != 0) {
            // Mostrar el signo
            if(!primero) {
                if(coef > 0) cout << " + ";
                else cout << " - ";
                coef = (coef < 0) ? -coef : coef;
            } else {
                if(coef < 0) {
                    cout << "-";
                    coef = -coef;
                }
                primero = false;
            }
            
            // Mostrar el coeficiente
            if(i == 0 || coef != 1) {
                cout << coef;
            }
            
            // Mostrar la variable x
            if(i > 0) {
                cout << "x";
                if(i > 1) {
                    cout << "^" << i;
                }
            }
        }
    }
    
    if(primero) cout << "0";  // Polinomio cero
    cout << endl;
}

// Función para sumar dos polinomios
Polinomio sumarPolinomios(Polinomio &p1, Polinomio &p2) {
    Polinomio resultado;
    
    // El grado del resultado es el máximo de los dos grados
    int gradoMax = (p1.grado > p2.grado) ? p1.grado : p2.grado;
    crearPolinomio(resultado, gradoMax);
    
    // Sumar los coeficientes
    for(int i = 0; i <= gradoMax; i++) {
        double coef1 = (i <= p1.grado) ? *(p1.coeficientes + i) : 0;
        double coef2 = (i <= p2.grado) ? *(p2.coeficientes + i) : 0;
        *(resultado.coeficientes + i) = coef1 + coef2;
    }
    
    return resultado;
}

// Función para multiplicar dos polinomios
Polinomio multiplicarPolinomios(Polinomio &p1, Polinomio &p2) {
    Polinomio resultado;
    
    // El grado del resultado es la suma de los grados
    int gradoResultado = p1.grado + p2.grado;
    crearPolinomio(resultado, gradoResultado);
    
    // Inicializar coeficientes en 0
    for(int i = 0; i <= gradoResultado; i++) {
        *(resultado.coeficientes + i) = 0;
    }
    
    // Multiplicar término a término
    for(int i = 0; i <= p1.grado; i++) {
        for(int j = 0; j <= p2.grado; j++) {
            *(resultado.coeficientes + i + j) += 
                (*(p1.coeficientes + i)) * (*(p2.coeficientes + j));
        }
    }
    
    return resultado;
}

// Función para evaluar un polinomio en un valor dado
double evaluarPolinomio(Polinomio &p, double x) {
    double resultado = 0;
    double potencia = 1;  // x^0 = 1
    
    for(int i = 0; i <= p.grado; i++) {
        resultado += (*(p.coeficientes + i)) * potencia;
        potencia *= x;  // Calcular siguiente potencia de x
    }
    
    return resultado;
}

int main() {
    Polinomio p1, p2;
    
    // Leer primer polinomio
    cout << "Ingrese el primer polinomio:\n";
    leerPolinomio(p1);
    
    // Leer segundo polinomio
    cout << "\nIngrese el segundo polinomio:\n";
    leerPolinomio(p2);
    
    // Mostrar polinomios
    cout << "\nPrimer polinomio: ";
    mostrarPolinomio(p1);
    
    cout << "Segundo polinomio: ";
    mostrarPolinomio(p2);
    
    // Sumar polinomios
    Polinomio suma = sumarPolinomios(p1, p2);
    cout << "La suma de los polinomios es: ";
    mostrarPolinomio(suma);
    
    // Multiplicar polinomios
    Polinomio producto = multiplicarPolinomios(p1, p2);
    cout << "El producto de los polinomios es: ";
    mostrarPolinomio(producto);
    
    // Evaluar primer polinomio
    double x;
    cout << "\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin >> x;
    double valorEvaluado = evaluarPolinomio(p1, x);
    cout << "El primer polinomio evaluado en x = " << x << " es: " << valorEvaluado << endl;
    
    // Liberar memoria
    liberarPolinomio(p1);
    liberarPolinomio(p2);
    liberarPolinomio(suma);
    liberarPolinomio(producto);
    
    return 0;
}