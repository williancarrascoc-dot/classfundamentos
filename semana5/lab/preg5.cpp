#include <iostream>
#include <string> // Necesaria para el tipo de dato string

using namespace std;

// a) Estructura Proceso (Nodo)
struct Proceso {
    int id;
    string nombre;
    float memoria;
    Proceso* siguiente;
};

// b) Estructura ListaProcesos (Encapsulador)
struct ListaProcesos {
    Proceso* cabeza;
};

// c) Operaciones

void inicializar(ListaProcesos &lista) {
    lista.cabeza = nullptr;
}

void insertarInicio(ListaProcesos &lista, int id, string nombre, float memoria) {
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->memoria = memoria;
    
    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
}

void insertarFinal(ListaProcesos &lista, int id, string nombre, float memoria) {
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->memoria = memoria;
    nuevo->siguiente = nullptr;

    if (lista.cabeza == nullptr) {
        lista.cabeza = nuevo;
    } else {
        Proceso* actual = lista.cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void mostrar(ListaProcesos lista) {
    Proceso* actual = lista.cabeza;
    if (actual == nullptr) {
        cout << "La lista esta vacia." << endl;
    } else {
        cout << "\n--- LISTA DE PROCESOS ---" << endl;
        while (actual != nullptr) {
            cout << "[ID: " << actual->id << " | " << actual->nombre 
                 << " | " << actual->memoria << " MB]" << endl;
            actual = actual->siguiente;
        }
    }
}

void buscar(ListaProcesos lista, int id) {
    Proceso* actual = lista.cabeza;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->id == id) {
            cout << "Proceso " << id << " ENCONTRADO: " << actual->nombre << endl;
            encontrado = true;
            break; // Salimos del bucle si ya lo hallamos
        }
        actual = actual->siguiente;
    }

    if (encontrado == false) {
        cout << "Proceso " << id << " NO encontrado." << endl;
    }
}

void eliminar(ListaProcesos &lista, int id) {
    if (lista.cabeza == nullptr) {
        return;
    }

    Proceso* actual = lista.cabeza;
    Proceso* anterior = nullptr;

    // Buscar el nodo y mantener el rastro del anterior
    while (actual != nullptr && actual->id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "No se pudo eliminar: ID " << id << " no existe." << endl;
    } else {
        // Si el anterior es null, significa que eliminamos la cabeza
        if (anterior == nullptr) {
            lista.cabeza = actual->siguiente;
        } else {
            // Si no es la cabeza, puenteamos el nodo actual
            anterior->siguiente = actual->siguiente;
        }
        delete actual; // Liberamos la memoria del nodo
        cout << "Proceso " << id << " eliminado correctamente." << endl;
    }
}

int contar(ListaProcesos lista) {
    int contador = 0;
    Proceso* actual = lista.cabeza;
    while (actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }
    return contador;
}

// 8. Inserción Ordenada (Aquí es donde quité el ternario)
void insertarOrdenado(ListaProcesos &lista, int id, string nombre, float memoria) {
    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->memoria = memoria;

    // Caso 1: Lista vacía o el nuevo es menor que la cabeza
    if (lista.cabeza == nullptr || lista.cabeza->memoria >= memoria) {
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
    } else {
        // Caso 2: Buscar la posición correcta
        Proceso* actual = lista.cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->memoria < memoria) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
}

void liberarMemoria(ListaProcesos &lista) {
    while (lista.cabeza != nullptr) {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->siguiente;
        delete temp;
    }
    cout << "Memoria liberada exitosamente." << endl;
}

int main() {
    ListaProcesos misProcesos;
    inicializar(misProcesos);

    // Cumpliendo con los requisitos del laboratorio
    insertarInicio(misProcesos, 101, "Kernel", 45.5);
    insertarInicio(misProcesos, 102, "Driver", 12.8);
    insertarInicio(misProcesos, 103, "Shell", 30.2);

    insertarFinal(misProcesos, 104, "Browser", 150.0);
    insertarFinal(misProcesos, 105, "Python", 85.3);

    mostrar(misProcesos);

    cout << "\nTotal de procesos: " << contar(misProcesos) << endl;

    buscar(misProcesos, 102);
    
    eliminar(misProcesos, 103); // Cabeza
    eliminar(misProcesos, 105); // Final
    
    mostrar(misProcesos);

    cout << "\nInsertando proceso ordenado (50.0 MB)..." << endl;
    insertarOrdenado(misProcesos, 106, "Database", 50.0);
    
    mostrar(misProcesos);

    liberarMemoria(misProcesos);

    return 0;
}