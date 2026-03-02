#include <iostream>
#include <fstream> // para minipular archivos
#include <iomanip> // para formatear la salida
#include <string>
using namespace std;
int main(){
    ifstream f("baseUNI.txt");
    if (!f) {
        cout << "Error al abrir el archivo";
        return 1;
    }
    string linea, apellidos, nombre, nombreMax, apellidoMax;
    int numero;
    float nota1, nota2, promedio, promMax = -1;
    cout << "Num\t" << "Apellidos\t" << "Nombre\t" << "Nota1\t" << "Nota2\t" << "Promedio" <<endl;    
    while (getline(f,linea,'.')) {
        numero = stoi(linea);
        getline(f,apellidos,',');
        getline(f,nombre,'-');
        getline(f,linea,'-');
        nota1 = stof(linea);
        getline(f, linea);
        nota2 = stof(linea); 
        promedio = (nota1 + nota2)/2;
        if (promMax < promedio) {
            promMax = promedio;
            nombreMax = nombre;
            apellidoMax = apellidos;
        }
        cout << numero <<"\t" << apellidos << "\t" << nombre << "\t"
             << nota1 << "\t" << nota2 << "\t" << promedio <<endl;
    }
    cout << "El promedio maximo: " << promMax <<endl;
    cout << "Alumno: " << apellidoMax << " " << nombreMax <<endl;
    return 0;
}