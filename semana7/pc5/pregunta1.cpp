#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Alumno {
    char codigo[10];
    char nombre[30];
    int notas[3];
    double promedio;
    char condicion[40];
};

int main() {
    ifstream archivo("notas.txt");
    if (!archivo.is_open()) {
        cerr << "Error: No se pudo abrir notas.txt" << endl;
        return 1;
    }

    Alumno alumnos[100];
    int total = 0;

    while (archivo >> alumnos[total].codigo >> alumnos[total].nombre
                   >> alumnos[total].notas[0]
                   >> alumnos[total].notas[1]
                   >> alumnos[total].notas[2]) {

        Alumno& a = alumnos[total];

        a.promedio = (a.notas[0] + a.notas[1] + a.notas[2]) / 3.0;

        bool regla = (a.notas[0] < 5 || a.notas[1] < 5 || a.notas[2] < 5);

        if (regla)
            strcpy(a.condicion, "DESAPROBADO POR REGLA ACADEMICA");
        else if (a.promedio >= 10)
            strcpy(a.condicion, "APROBADO");
        else
            strcpy(a.condicion, "DESAPROBADO");

        total++;
    }
    archivo.close();

    double sumaTotal = 0;
    int indiceMayor = 0, indiceMenor = 0;

    for (int i = 0; i < total; i++) {
        sumaTotal += alumnos[i].promedio;
        if (alumnos[i].promedio > alumnos[indiceMayor].promedio) indiceMayor = i;
        if (alumnos[i].promedio < alumnos[indiceMenor].promedio) indiceMenor = i;
    }

    double promedioGeneral = sumaTotal / total;



    ofstream reporte("reportealumno.txt");
    if (!reporte.is_open()) {
        cerr << "Error: No se pudo crear reportealumno.txt" << endl;
        return 1;
    }

    reporte << "REPORTE DE ALUMNOS:"<< endl;
    reporte << left
            << setw(8)  << "CODIGO"
            << setw(12) << "NOMBRE"
            << setw(10) << "PROMEDIO"
            << "CONDICION"                                                         << endl;

    for (int i = 0; i < total; i++) {
        reporte << left
                << setw(8)  << alumnos[i].codigo
                << setw(12) << alumnos[i].nombre
                << setw(10) << fixed << setprecision(2) << alumnos[i].promedio
                << alumnos[i].condicion                                            << endl;
    }

    reporte << endl;
    reporte << "TOTAL DE ESTUDIANTES   : " << total                                << endl;
    reporte << "PROMEDIO GENERAL       : " << fixed << setprecision(2)
                                           << promedioGeneral                      << endl;
    reporte << "MAYOR PROMEDIO         : " << alumnos[indiceMayor].nombre
            << " (" << alumnos[indiceMayor].promedio << ")"                        << endl;
    reporte << "MENOR PROMEDIO         : " << alumnos[indiceMenor].nombre
            << " (" << alumnos[indiceMenor].promedio << ")"                        << endl;

    reporte.close();
    cout<<"se hizo el reporte correctamente"<<endl;
    return 0;
}