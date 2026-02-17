#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

// a) Estructura Proceso (nodo de la lista enlazada)
struct Proceso {
    int id;
    char nombre[50];
    int consumoMemoria;  // en MB
    Proceso *siguiente;
};

// b) Estructura ListaProcesos
struct ListaProcesos {
    Proceso *cabeza;
};

// 1. Inicializar la lista vacía
void inicializarLista(ListaProcesos &lista) {
    lista.cabeza = NULL;
}

// 2. Insertar al inicio de la lista
void insertarAlInicio(ListaProcesos &lista, int id, const char *nombre, int memoria) {
    Proceso *nuevo = new Proceso;
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->consumoMemoria = memoria;
    nuevo->siguiente = lista.cabeza;
    lista.cabeza = nuevo;
    
    cout << "Proceso insertado al inicio: " << nombre << endl;
}

// 3. Insertar al final de la lista
void insertarAlFinal(ListaProcesos &lista, int id, const char *nombre, int memoria) {
    Proceso *nuevo = new Proceso;
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->consumoMemoria = memoria;
    nuevo->siguiente = NULL;
    
    if(lista.cabeza == NULL) {
        lista.cabeza = nuevo;
    } else {
        Proceso *actual = lista.cabeza;
        while(actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    
    cout << "Proceso insertado al final: " << nombre << endl;
}

// 4. Mostrar todos los procesos
void mostrarProcesos(ListaProcesos &lista) {
    if(lista.cabeza == NULL) {
        cout << "\nLa lista esta vacia.\n";
        return;
    }
    
    cout << "\n=== LISTA DE PROCESOS ===\n";
    cout << "ID\tNombre\t\t\tMemoria (MB)\n";
    cout << "------------------------------------------------\n";
    
    Proceso *actual = lista.cabeza;
    while(actual != NULL) {
        cout << actual->id << "\t" 
             << actual->nombre << "\t\t\t" 
             << actual->consumoMemoria << " MB\n";
        actual = actual->siguiente;
    }
    cout << endl;
}

// 5. Buscar un proceso por ID
int buscarPorID(ListaProcesos &lista, int id) {
    Proceso *actual = lista.cabeza;
    
    while(actual != NULL) {
        if(actual->id == id) {
            cout << "\nProceso encontrado:\n";
            cout << "ID: " << actual->id << endl;
            cout << "Nombre: " << actual->nombre << endl;
            cout << "Memoria: " << actual->consumoMemoria << " MB\n";
            return 1;  // Encontrado
        }
        actual = actual->siguiente;
    }
    
    cout << "\nProceso con ID " << id << " no encontrado.\n";
    return 0;  // No encontrado
}

// 6. Eliminar un proceso por ID
void eliminarPorID(ListaProcesos &lista, int id) {
    if(lista.cabeza == NULL) {
        cout << "\nLa lista esta vacia. No se puede eliminar.\n";
        return;
    }
    
    Proceso *actual = lista.cabeza;
    Proceso *anterior = NULL;
    
    // Caso 1: Eliminar la cabeza
    if(actual->id == id) {
        lista.cabeza = actual->siguiente;
        cout << "\nProceso '" << actual->nombre << "' eliminado (cabeza).\n";
        delete actual;
        return;
    }
    
    // Caso 2 y 3: Eliminar en posición intermedia o al final
    while(actual != NULL && actual->id != id) {
        anterior = actual;
        actual = actual->siguiente;
    }
    
    // Caso 4: Proceso no existe
    if(actual == NULL) {
        cout << "\nProceso con ID " << id << " no existe.\n";
        return;
    }
    
    // Eliminar el nodo
    anterior->siguiente = actual->siguiente;
    cout << "\nProceso '" << actual->nombre << "' eliminado.\n";
    delete actual;
}

// 7. Contar procesos
int contarProcesos(ListaProcesos &lista) {
    int contador = 0;
    Proceso *actual = lista.cabeza;
    
    while(actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }
    
    return contador;
}

// 8. Insertar ordenado por consumo de memoria (ascendente)
void insertarOrdenado(ListaProcesos &lista, int id, const char *nombre, int memoria) {
    Proceso *nuevo = new Proceso;
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->consumoMemoria = memoria;
    
    // Caso 1: Lista vacía o insertar al inicio
    if(lista.cabeza == NULL || lista.cabeza->consumoMemoria >= memoria) {
        nuevo->siguiente = lista.cabeza;
        lista.cabeza = nuevo;
        cout << "Proceso insertado ordenadamente: " << nombre << endl;
        return;
    }
    
    // Caso 2: Insertar en posición intermedia o al final
    Proceso *actual = lista.cabeza;
    while(actual->siguiente != NULL && actual->siguiente->consumoMemoria < memoria) {
        actual = actual->siguiente;
    }
    
    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
    cout << "Proceso insertado ordenadamente: " << nombre << endl;
}

// 9. Liberar toda la memoria
void liberarMemoria(ListaProcesos &lista) {
    Proceso *actual = lista.cabeza;
    
    while(actual != NULL) {
        Proceso *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    
    lista.cabeza = NULL;
    cout << "\nMemoria liberada correctamente.\n";
}

// Función auxiliar para mostrar el menú
void mostrarMenu() {
    cout << "\n=== MENU DE OPCIONES ===\n";
    cout << "1. Insertar proceso al inicio\n";
    cout << "2. Insertar proceso al final\n";
    cout << "3. Mostrar todos los procesos\n";
    cout << "4. Buscar proceso por ID\n";
    cout << "5. Eliminar proceso por ID\n";
    cout << "6. Contar procesos\n";
    cout << "7. Insertar proceso ordenado por memoria\n";
    cout << "8. Salir\n";
    cout << "Opcion: ";
}

int main() {
    ListaProcesos lista;
    
    // 1. Inicializar lista
    inicializarLista(lista);
    cout << "Lista de procesos inicializada.\n\n";
    
    // 2. Insertar 3 elementos al inicio
    cout << "=== Insertando 3 procesos al inicio ===\n";
    insertarAlInicio(lista, 101, "Chrome", 512);
    insertarAlInicio(lista, 102, "Firefox", 320);
    insertarAlInicio(lista, 103, "VSCode", 256);
    
    // 3. Insertar 2 elementos al final
    cout << "\n=== Insertando 2 procesos al final ===\n";
    insertarAlFinal(lista, 104, "Spotify", 128);
    insertarAlFinal(lista, 105, "Discord", 200);
    
    // 4. Mostrar procesos
    mostrarProcesos(lista);
    
    // 5. Buscar proceso
    cout << "\n=== Buscando procesos ===";
    buscarPorID(lista, 102);
    buscarPorID(lista, 999);  // No existe
    
    // 7. Contar procesos
    cout << "\n=== Contando procesos ===\n";
    int total = contarProcesos(lista);
    cout << "Numero total de procesos: " << total << endl;
    
    // 6. Eliminar procesos
    cout << "\n=== Eliminando procesos ===";
    eliminarPorID(lista, 103);  // Eliminar cabeza
    eliminarPorID(lista, 104);  // Eliminar intermedio
    eliminarPorID(lista, 105);  // Eliminar final
    eliminarPorID(lista, 999);  // No existe
    
    mostrarProcesos(lista);
    
    // 8. Insertar ordenado
    cout << "=== Insertando procesos ordenados por memoria ===\n";
    insertarOrdenado(lista, 106, "Notepad", 64);
    insertarOrdenado(lista, 107, "Excel", 400);
    insertarOrdenado(lista, 108, "Teams", 180);
    
    mostrarProcesos(lista);
    
    // Menú interactivo (opcional)
    int opcion;
    int id, memoria;
    char nombre[50];
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Memoria (MB): "; cin >> memoria;
                insertarAlInicio(lista, id, nombre, memoria);
                break;
            case 2:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Memoria (MB): "; cin >> memoria;
                insertarAlFinal(lista, id, nombre, memoria);
                break;
            case 3:
                mostrarProcesos(lista);
                break;
            case 4:
                cout << "Ingrese ID a buscar: "; cin >> id;
                buscarPorID(lista, id);
                break;
            case 5:
                cout << "Ingrese ID a eliminar: "; cin >> id;
                eliminarPorID(lista, id);
                break;
            case 6:
                cout << "Numero de procesos: " << contarProcesos(lista) << endl;
                break;
            case 7:
                cout << "ID: "; cin >> id;
                cout << "Nombre: "; cin >> nombre;
                cout << "Memoria (MB): "; cin >> memoria;
                insertarOrdenado(lista, id, nombre, memoria);
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida.\n";
        }
    } while(opcion != 8);
    
    // 9. Liberar memoria
    liberarMemoria(lista);
    
    return 0;
}
