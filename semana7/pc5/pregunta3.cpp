#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    const int COLS  = 80;
    const int FILAS = 21;
    const double PI = 3.1416;

    char grilla[FILAS][COLS];
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLS; j++)
            grilla[i][j] = ' ';

    int filaEjeX = FILAS / 2;
    for (int j = 0; j < COLS; j++)
        grilla[filaEjeX][j] = '-';

    for (int i = 0; i < FILAS; i++)
        grilla[i][0] = '|';

    grilla[filaEjeX][0] = '+';

    for (int j = 0; j < COLS; j++) {
        double x = j * (2.0 * PI) / (COLS - 1);
        double y = sin(5.0 * x);

        int fila = (int)round((1.0 - y) / 2.0 * (FILAS - 1));
        if (fila < 0)      fila = 0;
        if (fila >= FILAS) fila = FILAS - 1;

        grilla[fila][j] = '*';
    }

    ofstream archivo("grafico.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo crear grafico.txt" << endl;
        return 1;
    }
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++)
            archivo << grilla[i][j];
        archivo << endl;
    }
    archivo.close();

    ifstream leer("grafico.txt");
    string linea;
    while (getline(leer, linea))
        cout << linea << endl;
    leer.close();
    return 0;
}