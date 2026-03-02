#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Empleado {
    int id;
    char nombre[30];
    double salario;
};

int main() {
    int idBuscado;

    cout << "Ingrese ID de empleado: ";
    cin >> idBuscado;

    fstream archivo("empleados.dat", ios::in | ios::out | ios::binary);
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir empleados.dat" << endl;
        return 1;
    }

    long long offset = (long long)(idBuscado - 1) * sizeof(Empleado);

    archivo.seekg(0, ios::end);
    long long tamArchivo = archivo.tellg();

    if (offset + (long long)sizeof(Empleado) > tamArchivo) {
        cout << "Error: El ID " << idBuscado << " no existe en el archivo." << endl;
        archivo.close();
        return 1;
    }

    archivo.seekg(offset, ios::beg);

    Empleado emp;
    archivo.read(reinterpret_cast<char*>(&emp), sizeof(Empleado));

    if (emp.id != idBuscado) {
        cout << "Error: El registro encontrado no coincide con el ID buscado." << endl;
        archivo.close();
        return 1;
    }

    cout << endl;
    cout << "DATOS DEL EMPLEADO:" << endl;
    cout << "ID     : " << emp.id << endl;
    cout << "Nombre : " << emp.nombre << endl;
    cout << "Salario: " << fixed << setprecision(2) << emp.salario << endl;

    double nuevoSalario;
    cout << endl;
    cout << "Ingrese nuevo salario: ";
    cin >> nuevoSalario;

    emp.salario = nuevoSalario;

    archivo.seekp(offset, ios::beg);
    archivo.write(reinterpret_cast<char*>(&emp), sizeof(Empleado));

    if (archivo.good()) {
        cout << "Salario actualizado correctamente." << endl;
    } else {
        cerr << "Error al escribir en el archivo." << endl;
    }

    archivo.close();
    return 0;
}