#include <iostream>
#include "Gestor.h"
#include "Validar.h"

using namespace std;

Gestor gestor;
Validar validar;
void menu();
void insertMapa();
void obtenerUbicacion();
void procesarMenu(int &, bool &);
void listaAdyacencia();
void listaAdyacenciaXVertice();
void listaPredecesores();
void listaPredecesoresXVertice();
void numVertices();
void dijkstra();


int main() {
    insertMapa();
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenu \n\nElija una opcion\n" <<
             "1 buscar ubicacion\n" <<
             "2 Imprimir sucesores\n" <<
             "3 Imprimir sucesores por vertice\n" <<
             "4 Imprimir predecesores\n" <<
             "5 Imprimir predecesores por vertice\n" <<
             "6 Numero de vertices\n" <<
             "7 Ruta de menor costo (Dijkstra)\n" <<
             "8 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            obtenerUbicacion();
            break;
        case 2:
            listaAdyacencia();
            break;
        case 3:
            listaAdyacenciaXVertice();
            break;
        case 4:
            listaPredecesores();
            break;
        case 5:
            listaPredecesoresXVertice();
            break;
        case 6:
            numVertices();
            break;
        case 7:
            dijkstra();
            break;
        case 8:
            salir = true;
            break;
        default:
            cout << "Opcion inválida\n";
    }
}

void insertMapa(){
    // insercion de vertices
    string ubic[35] = {"san_jose", "volcan_arenal", "monteverde", "volcan_poas", "santa_rosa",
                       "golfo_papagayo", "conchal", "flamingo", "tamarindo", "montezuma",
                       "isla_tortuga",  "carara", "jaco", "manuel_antonio", "dominical",
                       "bahia_drake", "isla_del_cano", "corcovado", "golfito", "talamanca",
                       "sarapiqui", "braulio_carrillo", "volcan_irazu", "tortuguero", "siquirres",
                       "rio_pacuare", "cahuita", "punta_uva", "puerto_viejo", "manzanillo",
                       "puntarenas", "liberia", "puerto_jimenez", "limon", "san_isidro"};
    for (int i = 0; i < 35; ++i) {
        for (auto & c: ubic[i]) c = toupper(c);
        gestor.insertVertice( ubic[i]);
        gestor.addUbicaciones(ubic[i]);
    }
    // insercion de aristas
    gestor.insertaArista("SAN_JOSE", "VOLCAN_POAS", 48.8);
    gestor.insertaArista("SAN_JOSE", "BRAULIO_CARRILLO", 53.5);
    gestor.insertaArista("SAN_JOSE", "VOLCAN_IRAZU", 51);
    gestor.insertaArista("SAN_JOSE", "CARARA", 75.6);
    gestor.insertaArista("BRAULIO_CARRILLO", "SARAPIQUI", 44);
    gestor.insertaArista("BRAULIO_CARRILLO", "VOLCAN_POAS", 25.1);
    gestor.insertaArista("VOLCAN_POAS", "PUNTARENAS", 106);
    gestor.insertaArista("VOLCAN_POAS", "VOLCAN_ARENAL", 117);
    gestor.insertaArista("PUNTARENAS", "MONTEVERDE", 62.7);
    gestor.insertaArista("PUNTARENAS", "ISLA_TORTUGA", 59.6);
    gestor.insertaArista("PUNTARENAS", "TAMARINDO", 171);
    gestor.insertaArista("PUNTARENAS", "FLAMINGO", 187);
    gestor.insertaArista("PUNTARENAS", "CONCHAL", 188);
    gestor.insertaArista("PUNTARENAS", "GOLFO_PAPAGAYO", 162);
    gestor.insertaArista("PUNTARENAS", "MONTEZUMA", 87.4);
    gestor.insertaArista("PUNTARENAS", "LIBERIA", 125);
    gestor.insertaArista("MONTEZUMA", "TAMARINDO", 184);
    gestor.insertaArista("FLAMINGO", "TAMARINDO", 23.8);
    gestor.insertaArista("FLAMINGO", "CONCHAL", 6.2);
    gestor.insertaArista("GOLFO_PAPAGAYO", "CONCHAL", 57);
    gestor.insertaArista("LIBERIA", "GOLFO_PAPAGAYO", 42.1);
    gestor.insertaArista("LIBERIA", "SANTA_ROSA", 41.3);
    gestor.insertaArista("LIBERIA", "MONTEVERDE", 116);
    gestor.insertaArista("MONTEVERDE", "VOLCAN_ARENAL", 105);
    gestor.insertaArista("CARARA", "JACO", 23.8);
    gestor.insertaArista("CARARA", "PUNTARENAS", 39.2);
    gestor.insertaArista("JACO", "MANUEL_ANTONIO", 78.8);
    gestor.insertaArista("MANUEL_ANTONIO", "DOMINICAL", 49.8);
    gestor.insertaArista("DOMINICAL", "BAHIA_DRAKE", 165);
    gestor.insertaArista("BAHIA_DRAKE", "GOLFITO", 93.9);
    gestor.insertaArista("BAHIA_DRAKE", "ISLA_DEL_CANO", 30);
    gestor.insertaArista("CORCOVADO", "ISLA_DEL_CANO", 60);
    gestor.insertaArista("DOMINICAL", "SAN_ISIDRO", 35.4);
    gestor.insertaArista("SAN_ISIDRO", "SAN_JOSE", 137);
    gestor.insertaArista("PUERTO_JIMENEZ", "CORCOVADO", 43.5);
    gestor.insertaArista("BAHIA_DRAKE", "PUERTO_JIMENEZ", 57.1);
    gestor.insertaArista("SAN_ISIDRO", "TALAMANCA", 19.7);
    gestor.insertaArista("SARAPIQUI", "TORTUGUERO", 101);
    gestor.insertaArista("VOLCAN_IRAZU", "RIO_PACUARE", 113);
    gestor.insertaArista("RIO_PACUARE", "LIMON", 55.9);
    gestor.insertaArista("LIMON", "SIQUIRRES", 59.3);
    gestor.insertaArista("SIQUIRRES", "TORTUGUERO", 89.3);
    gestor.insertaArista("LIMON", "CAHUITA", 44.7);
    gestor.insertaArista("CAHUITA", "PUERTO_VIEJO", 16);
    gestor.insertaArista("PUERTO_VIEJO", "PUNTA_UVA", 8.8);
    gestor.insertaArista("PUNTA_UVA", "MANZANILLO", 4.4);
    cout << "La carga se realizo satisfactoriamente. Para ver reportes vuelva al menu principal\n";
}

//-------------------------------------------------------------------------//

void obtenerUbicacion(){
    string loc;
    cout << "Ingrese el nombre de la ubicacion a buscar\n";
    cin >> loc;
    for (auto & c: loc) c = toupper(c);
    cout << gestor.obtenerUbicacion(loc);
}
void listaAdyacencia(){
    cout << gestor.listaAdyacencia();
}
void listaAdyacenciaXVertice(){
    if (gestor.vacio()){
        cout << "Aun no se han ingresado vertices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vertice del cual desea mostrar sus adyacencias\n";
        cin >> vertice;
        for (auto & c: vertice) c = toupper(c);
        cout << gestor.listaAdyacenciaXVertice(vertice);
    }
}
void listaPredecesores(){
    cout << gestor.listaPredecesores();
}
void listaPredecesoresXVertice(){
    if (gestor.vacio()){
        cout << "Aun no se han ingresado vertices...\n";
    } else {
        string vertice;
        cout << "Ingrese el nombre del vertice del cual desea mostrar sus predecesores\n";
        cin >> vertice;
        for (auto & c: vertice) c = toupper(c);
        cout << gestor.listaPredecesoresXVertice(vertice);
    }
}
void numVertices(){
    if (gestor.vacio()){
        cout << "Aun no se han ingresado vertices...\n";
    } else {
        cout << "La matriz de adyacencia tiene " + to_string(gestor.numVertices()) + " vertices\n";
    }
}
void dijkstra(){
    if (gestor.vacio()){
        cout << "Aun no se han ingresado vertices...\n";
    } else {
        string origen, destino;
        cout << "Ingrese el nombre de la vertice de origen\n";
        cin >> origen;
        for (auto & c: origen) c = toupper(c);
        cout << "Ingrese el nombre de la vertice de destino\n";
        cin >> destino;
        for (auto & c: destino) c = toupper(c);
        cout << gestor.dijkstra(origen, destino);
    }
}
