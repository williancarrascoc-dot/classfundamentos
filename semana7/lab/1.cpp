#include <iostream>
#include <fstream> // para manipular archivos
using namespace std;
void mezclaArchivos();
int main(){
    ifstream file1, file2; // creamos 2 objetos para lectura
    ofstream file3("output/mezcla.txt"); // creamos un objeto para escritura
    file1.open("entradas/archivo1.txt"); // abrimos los archivos
    file2.open("entradas/archivo2.txt");
    if (!file1) {
        cout << "Error al abrir archivo1";
        return 1;
    }
    if (!file2) {
        cout << "Error al abrir archivo2";
        return 1;
    }
    if (!file3) {
        cout << "Error al abrir el archivo mezcla";
        return 1;
    }
    // Implementacion de merge
    int dato1, dato2;
    file1 >> dato1;
    file2 >> dato2;
    while(dato1 != -1 && dato2 != -1) {
        if (dato1 < dato2) {
            file3 << dato1 << endl; // Escribimos en el archivo mezcla.txt y saltamos de linea
            file1 >> dato1;
        } else {
            file3 << dato2 << endl;
            file2 >> dato2;
        }

    }

    while (dato1 != -1) {
        file3 << dato1 <<endl;
        file1 >> dato1;
    }


    while (dato2 != -1) {
        file3 << dato2 <<endl;
        file2 >> dato2;
    }



    return 0;
}