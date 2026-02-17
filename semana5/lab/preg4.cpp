#include<iostream>
using namespace std;
struct Polinomio {
    int n; // Grado
    int *coeficiente; 
};
void Rellenar(Polinomio *P1) {
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            cout << "Ingrese el grado del primer polinomio: ";
        } else {
            cout << "Ingrese el grado del segundo polinomio: ";
        }
        cin >> P1[i].n;

        P1[i].coeficiente = new int[P1[i].n + 1]; // En el puntero coeficiente se guarda memoria para P1[i].n + 1 elementos ya que si el grado es 3 hay 4 elementos como maximo.

        for (int j = 0; j <= P1[i].n; j++) {
            cout << "Ingrese el coeficiente de x^" << P1[i].n - j << ": ";
            cin >> P1[i].coeficiente[j];
        }
        cout << endl;
    }
}

void Mostrar(Polinomio *P1) {
    cout << "Primer polinomio: ";
    for (int j = 0; j <= P1[0].n; j++) {
        cout << P1[0].coeficiente[j] << "x^" << P1[0].n - j;
        if (j < P1[0].n) {
            cout << " + ";
        }
    }
    cout << "\nSegundo polinomio: ";
    for (int j = 0; j <= P1[1].n; j++) {
        cout << P1[1].coeficiente[j] << "x^" << P1[1].n - j;
        if (j < P1[1].n) {
            cout << " + ";
        }
    }
    cout << endl;
}

void Sumar(Polinomio *P1) {
    int gradoMax;
    if (P1[0].n > P1[1].n) {
        gradoMax = P1[0].n;
    } else {
        gradoMax = P1[1].n;
    }

    int *resultado = new int[gradoMax + 1];
    
    // Inicializamos el arreglo en 0 manualmente
    for(int i = 0; i <= gradoMax; i++) {
        resultado[i] = 0;
    }

    // Sumamos alineando desde el exponente 0 (el final de los arreglos)
    for (int i = 0; i <= gradoMax; i++) {
        int c1 = 0;
        int c2 = 0;

        if (i <= P1[0].n) {
            c1 = P1[0].coeficiente[P1[0].n - i];
        }
        if (i <= P1[1].n) {
            c2 = P1[1].coeficiente[P1[1].n - i];
        }
        
        resultado[gradoMax - i] = c1 + c2;
    }

    cout << "La suma de los polinomios es: ";
    for (int j = 0; j <= gradoMax; j++) {
        cout << resultado[j] << "x^" << gradoMax - j;
        if (j < gradoMax) {
            cout << " + ";
        }
    }
    cout << endl;
    delete[] resultado; // Liberamos memoria temporal
}

void Multiplicar(Polinomio *P1) {
    int gradoRes = P1[0].n + P1[1].n;
    int *resultado = new int[gradoRes + 1];
    
    // Inicializar en 0
    for(int i = 0; i <= gradoRes; i++) {
        resultado[i] = 0;
    }

    // Multiplicacion distributiva
    for (int i = 0; i <= P1[0].n; i++) {
        for (int j = 0; j <= P1[1].n; j++) {
            resultado[i + j] = resultado[i + j] + (P1[0].coeficiente[i] * P1[1].coeficiente[j]);
        }
    }

    cout << "El producto de los polinomios es: ";
    for (int k = 0; k <= gradoRes; k++) {
        cout << resultado[k] << "x^" << gradoRes - k;
        if (k < gradoRes) {
            cout << " + ";
        }
    }
    cout << endl;
    delete[] resultado;
}

void Evaluar(Polinomio *P1) {
    int x;
    long long sumaTotal = 0;
    cout << "\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin >> x;

    for (int i = 0; i <= P1[0].n; i++) {
        long long potencia = 1;
        int exponente = P1[0].n - i;
        for(int p = 0; p < exponente; p++) {
            potencia = potencia * x;
        }
        sumaTotal = sumaTotal + (P1[0].coeficiente[i] * potencia);
    }
    cout << "El primer polinomio evaluado en x = " << x << " es: " << sumaTotal << endl;
}

int main() {
    Polinomio *P1 = new Polinomio[2];

    Rellenar(P1);
    Mostrar(P1);
    Sumar(P1);
    Multiplicar(P1);
    Evaluar(P1);

    delete[] P1[0].coeficiente;
    delete[] P1[1].coeficiente;
    delete[] P1;

    return 0;
}