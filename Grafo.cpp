//
// Created by roxan on 5 dic. 2021.
//


#include "Grafo.h"

Grafo::Grafo(Vertice *head, Vertice *tail, int tam) : head(head), tail(tail), tam(tam) {}

Grafo::~Grafo() {

}

Vertice *Grafo::getHead() const {
    return head;
}

void Grafo::setHead(Vertice *head) {
    Grafo::head = head;
}


Vertice *Grafo::getTail() const {
    return tail;
}

void Grafo::setTail(Vertice *tail) {
    Grafo::tail = tail;
}

int Grafo::getTam() const {
    return tam;
}

void Grafo::setTam(int tam) {
    Grafo::tam = tam;
}

bool Grafo::esListaVacia() const {
    return getHead() == nullptr;
}
/**
 * Metodo:              numVertices
 * Descripcion:         Metodo que permite establecer el número de vertices del grafo
 * @return              variable de tipo int que representa el número de vertices del grafo
 */
int Grafo::numVertices() const {
    return getTam();
}
/**
 * Metodo:              getVertice
 * Descripcion:         Metodo sobrecargado que permite obtener el nodo que contiene el nombre pasado
 * por parámetro
 * @param nombre        variable de tipo string que representa el nombre del nodo a buscar
 * @return              variable de tipo Vertice que contiene el nombre pasado por parámetro
 */
Vertice *Grafo::getVertice(string &nombre) {
    Vertice * aux = getHead();
    while (aux != nullptr){
        if (aux->getNombre().compare(nombre) == 0) {
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;
}

/**
 * Metodo:              getVertice
 * Descripcion:         Metodo sobrecargado que permite obtener el nodo que contiene el índice pasado
 * por parámetro
 * @param indice        variable de tipo int que representa el índice del nodo a buscar
 * @return              variable de tipo Vertice que contiene el nombre pasado por parámetro
 */
Vertice *Grafo::getVertice(int indice) {
    Vertice * aux = getHead();
    while (aux != nullptr) {
        if (aux->getIndice() == indice){
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;
}

/**
 * Metodo:              insertVertice
 * Descripcion:         Metodo que permite insertar un vertice de forma ordenada
 * @param indice        variable de tipo int que representa el índice del vertice
 * @param nombre        varibale de tipo string que representa el nombre del vertice a insertar
 */
void Grafo::insertVertice(int indice, string &nombre) {
    if(esListaVacia()){
        setHead(new Vertice(indice, nombre));
        setTail(getHead());
        setTam(getTam() + 1);
    } else {
        if (getHead()->getIndice() >= indice) {
            insertarAlIincio(indice, nombre);
        } else if(getTail()->getIndice() <= indice) { // insertar al final
            insertarAlFinal(indice, nombre);
        } else {
            Vertice *aux = getHead();
            do {
                if (aux->getIndice() <= indice && aux->getNext()->getIndice() >= indice){
                    Vertice *nuevo = new Vertice(indice, nombre);
                    nuevo->setNext(aux->getNext());
                    aux->setNext(nuevo);
                    setTam(getTam() + 1);
                    break;
                }
                aux =aux->getNext();
            } while (aux->getNext() != nullptr);
        }
    }
}
/**
 * Metodo:              insertarAlIincio
 * Descripcion:         Metodo privado que permite insertar un vertice a la lista de vertices al inicio
 * @param indice
 * @param nombre
 */
void Grafo::insertarAlIincio(int indice, string &nombre) {
    Vertice *nuevo = new Vertice(indice, nombre);
    nuevo->setNext(getHead());
    setHead(nuevo);
    setTam(getTam() + 1);
}
/**
 * Metodo:              insertarAlFinal
 * Descripcion:         Metodo privado que permite insertar un vertice a la lista de vertices al final
 * @param indice
 * @param nombre
 */
void Grafo::insertarAlFinal(int indice, string &nombre) {
    Vertice *nuevo = new Vertice(indice, nombre);
    getTail()->setNext(nuevo);
    setTail(nuevo);
    setTam(getTam() + 1);
}


/**
 * Metodo:              insertaArista
 * Descripcion:         Metodo que permite insertar una arista o arco entre dos vertices
 * @param salida        variable de tipo vertice que representa el vertice de salida
 * @param llegada       variable de tipo vertice que representa el vertice de llegada
 * @param peso          variable de tipo int que representa el peso del arco
 */
string Grafo::insertaArista(string &salida, string &llegada, float peso) {
    string res = "";
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
    if (origen != nullptr && destino != nullptr){
        // Aristas adyacentes
        Arista *nueva = new  Arista(peso, llegada,destino);
        Arista *aux = origen->getAdy();
        Vertice *anterior = origen;
        if (aux == nullptr){
            origen->setAdy(nueva);
            origen->getAdy()->setPrev(origen);
            nueva->setAdy(destino);
        } else {
            /** recorre las aristas hasta llegar a la última para insertar la nueva arista y
             * conectarla con el vertice destino.
             */
            while (aux->getSig() != nullptr){
                aux = aux->getSig();
            }
            aux->setSig(nueva);
            nueva->setPrev(origen);
            nueva->setAdy(destino);
        }
//         Aristas adyacentes
        Arista *nuevo = new Arista(peso, salida, origen);
        Arista * aux2 = destino->getPrecedente();
        if (aux2 == nullptr){
            destino->setPrecedente(nuevo);
            nuevo->setPrev(origen);
        } else {
            while (aux2->getAnt() != nullptr){
                aux2 = aux2->getAnt();
            }
            aux2->setAnt(nuevo);
            nuevo->setPrev(origen);
        }
        res = "La arista se creo satisfactoriamente\n";
    } else {
        res = "Uno de los vertices no existe\n";
    }
    return res;
}

/**
 * Metodo:              listaSucesores
 * Descripcion:         Metodo que permite imprimir la lista de adyacencia o sucesores
 * @return              variable de tipo string que representa la lista de sucesores.
 */
string Grafo::listaSucesores() {
    string lista = "";
    int i;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        lista = "Lista de vertices y adyacencias:\n";
        Vertice *vertAux = getHead();
        Arista * arisAux;
        while (vertAux != nullptr){
            lista += vertAux->getNombre() + ": ";
            arisAux = vertAux->getAdy();
            i = 0;
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getAdy()->getNombre();
                } else {
                    lista += ", " + arisAux->getAdy()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getSig();
            }
            vertAux = vertAux->getNext();
            lista += "\n";
        }
    }
    return lista;
}

/**
 * Metodo:              listaSucesoresXVertice
 * Descripcion:         Metodo que permite imprimir la lista de adyacencia de un vertice específico
 * @param indice        variable de tipo int que representa el índice del vertice
 * @return              variable de tipo string que representa la lista de adyacencia.
 */
string Grafo::listaSucesoresXVertice(int indice) {
    string lista = "";
    int i = 0;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        Vertice *vertAux = getHead();
        Arista * arisAux = nullptr;
        while (vertAux != nullptr && vertAux->getIndice() <= indice){
            if (vertAux->getIndice() == indice){
                arisAux = vertAux->getAdy();
                if (arisAux == nullptr){
                    lista = "El vertice " + vertAux->getNombre() + " no tiene adyacencias\n";
                } else {
                    lista = "Lista de adyacencias del vertice " + vertAux->getNombre() + ": ";
                }
                break;
            }
            vertAux = vertAux->getNext();
        }
        if (arisAux != nullptr){
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getAdy()->getNombre();
                } else {
                    lista += ", " + arisAux->getAdy()->getNombre();
                }
                arisAux = arisAux->getSig();
                i += 1;
            }
        }
    }
    return lista;
}
/**
 * Metodo:              listaPredecesores
 * Descripcion:         Metodo que permite imprimir la lista de sucesores
 * @return              variable de tipo string que representa la lista de adyacencia.
 */
string Grafo::listaPredecesores() {
    string lista = "";
    int i;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        lista = "Lista de vertices y predecesores:\n";
        Vertice *vertAux = getHead();
        Arista * arisAux;
        while (vertAux != nullptr){
            lista += vertAux->getNombre() + ": ";
            arisAux = vertAux->getPrecedente();
            i = 0;
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getPrev()->getNombre();
                } else {
                    lista += ", " + arisAux->getPrev()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getAnt();
            }
            vertAux = vertAux->getNext();
            lista += "\n";
        }
    }
    return lista;
}
/**
 * Metodo:              listaPredecesoresXVertice
 * Descripcion:         Metodo que permite imprimir la lista de predecesores de un vertice específico
 * @param indice        variable de tipo int que representa el índice del vertice
 * @return              variable de tipo string que representa la lista de predecesores.
 */
string Grafo::listaPredecesoresXVertice(int indice) {
    string lista = "";
    int i = 0;
    if(esListaVacia()) {
        lista = "La lista está vacía\n";
    } else {
        Vertice *vertAux = getHead();
        Arista * arisAux = nullptr;
        while (vertAux != nullptr && vertAux->getIndice() <= indice){
            if (vertAux->getIndice() == indice){
                arisAux = vertAux->getPrecedente();
                if (arisAux == nullptr){
                    lista = "El vertice " + vertAux->getNombre() + " no tiene predecesores\n";
                } else {
                    lista = "Lista de predecesores del vertice " + vertAux->getNombre() + ": ";
                }
                break;
            }
            vertAux = vertAux->getNext();
        }
        if (arisAux != nullptr){
            while (arisAux != nullptr){
                if (i == 0){
                    lista += arisAux->getPrev()->getNombre();
                } else {
                    lista += ", " + arisAux->getPrev()->getNombre();
                }
                i += 1;
                arisAux = arisAux->getAnt();
            }
        }
    }
    return lista;
}



/**
 * Metodo:              eliminarArista
 * Descripcion:         Metodo público que permite eliminar un arco o arista entre dos vertices,
 * este metodo recibe dos parametros de tipo string
 * @param salida        variable de tipo string que representa el vertice de salida
 * @param llegada       variable de tipo string que representa el vertice de llegada
 */
string Grafo::eliminarArista(string &salida, string &llegada) {
    Vertice *origen = getVertice(salida);
    Vertice *destino = getVertice(llegada);
    return eliminarArista(origen, destino);
}
/**
 * Metodo:              eliminarArista
 * Descripcion:         Metodo privado que permite eliminar un arco o arista entre dos vertices,
 * este metodo recibe dos parámetros de tipo Vertice
 * @param salida        variable de tipo vertice que representa el vertice de salida
 * @param llegada       variable de tipo vertice que representa el vertice de llegada
 */
string Grafo::eliminarArista(Vertice * origen, Vertice * destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen\n";
    } else {
        int band = 0;
        Arista *actual, *anterior;
        actual = origen->getAdy();
        if (actual == nullptr){ // no existe arista
            res = "El vertice origen no tiene aristas\n";
        } else if(actual->getAdy() == destino){ // la primera arista
            origen->setAdy(actual->getSig());
            delete actual;
            res = "El vertice entre " + origen->getNombre() + " y " + destino->getNombre() + " fue eliminado\n";
        } else { // cualquier otra arista
            while (actual->getAdy() != nullptr){
                if (actual->getAdy() == destino){
                    band = 1;
                    anterior->setSig(actual->getSig());
                    delete actual;
                    res = "El vertice entre " + origen->getNombre() + " y " + destino->getNombre() + " fue eliminado\n";
                    break;
                }
                anterior = actual;
                actual = actual->getSig();
            }
            if (band == 0){
                res = "Esos dos vertices no están conectados\n";
            }

        }
    }
    return res;
}
/**
 * Metodo:              eliminarGrafo
 * Descripcion:         Metodo que permite eliminar el grafo
 */
void Grafo::eliminarGrafo() {
    Vertice *aux;
    while (getHead() != nullptr){
        aux = getHead();
        setHead(getHead()->getNext());
        aux = nullptr;
        delete aux;
    }
    setTail(nullptr);
    setTam(0);
}
/**
 * Metodo:              eliminarVertice
 * Descripcion:         Metodo público que permite eliminar un vertice
 * @param pEliminar     variable de tipo string que representa el nombre del vertice
 * @return              variable de tipo bool, true si se elimino, false y no existe
 */
string Grafo::eliminarVertice(string &pEliminar) {
    Vertice *vert = getVertice(pEliminar);
    return eliminarVertice(vert);
}
/**
 * Metodo:              eliminarVertice
 * Descripcion:         Metodo privado que permite eliminar un vertice
 * @param vert          variable de tipo vertice que representa el vertice a eliminar
 * @return              variable de tipo bool, true si se elimino, false y no existe
 */
string Grafo::eliminarVertice(Vertice *vert) {
    string res = "";
    if (vert == nullptr){
        res = "El vertice ingresado no existe\n";
    } else {
        Vertice *actual, *anterior;
        Arista *aux;
        actual = getHead();
        while (actual != nullptr){ // se eliminan las aristas que tenga
            aux = actual->getAdy();
            while (aux != nullptr){
                if (aux->getAdy() == vert){
                    eliminarArista(actual, aux->getAdy());
                    break;
                }
                aux = aux->getSig();
            }
            actual = actual->getNext();
        }
        actual = getHead();
        if (getHead() == vert){
            setHead(getHead()->getNext());
            delete actual;
        } else {
            while (actual != vert){
                anterior = actual;
                actual = actual->getNext();
            }
            anterior->setNext(actual->getNext());
            delete actual;
        }
        res = "El vertice fue eliminado\n";
    }
    return res;
}
/**
 * Metodo:              recorridoAnchura
 * Descripcion:         Metodo público que permite hacer un recorrido por anchura del grafo
 * @param pOrigen       variable de tipo string que representa el nombre de vertice de origen
 */
string Grafo::recorridoAnchura(string &pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    return recorridoAnchura(origen);
}
/**
 * Metodo:              recorridoAnchura
 * Descripcion:         Metodo privado que permite hacer un recorrido por anchura del grafo
 * @param origen        variable de tipo vertice que representa el nombre de vertice de origen
 */
string Grafo::recorridoAnchura(Vertice *origen) {
    string res = "";
    int k = 0;
    if (origen == nullptr){
        res = "No exite el vertice";
    } else {
        res = "El recorrido en anchura, a partir de: " + origen->getNombre() + " es:\n";
        int band, band2;
        stack<string> pilaRes; // pila que contiene las respuestas.
        Vertice *actual;
        queue<Vertice*> cola;
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // se coloca el vertice origen en una cola (el que pasan como parámetro
        while (!cola.empty()){ // mientras la cola no este vacía
            band = 0;
            actual = cola.front();
            cola.pop(); // desencolamos un vertice, será el vertice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0) { // si el vertice actual no ha sido visitado
                k += 1;
                if(k%5 == 0){
                    res += actual->getNombre() + ",\n"; // procesar el vertice actual
                } else {
                    res += actual->getNombre() + ", "; // procesar el vertice actual
                }
                lista.push_back(actual); // colocar el vertice en la lista de visitados
                Arista * aux = actual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) { // para cada vertice que el vertice actual tiene como destino, y que no ha sido visitado
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // encolar el vertice
                        cola.push(aux->getAdy());
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
    return res + "\n";
}
/**
 * Metodo:              recorridoProfundidad
 * Descripcion:         Metodo público que permite hacer un recorrido en profundidad del grafo
 * recibiendo como parámetro el nombre del vertice de origen
 * @param pOrigen       variable de tipo string que representa el nombre del vertice de origen
 */
string Grafo::recorridoProfundidad(string &pOrigen) {
    Vertice *origen = getVertice(pOrigen);
    return recorridoProfundidad(origen);
}
/**
 * Metodo:              recorridoProfundidad
 * Descripcion:         Metodo privado que permite hacer un recorrido en profundidad del grafo
 * recibiendo como parámetro el vertice de origen
 * @param origen        variable de tipo vertice que representa el nombre del vertice de origen
 */
string Grafo::recorridoProfundidad(Vertice *origen) {
    string res = "";
    int k = 0;
    if (origen == nullptr){
        res = "No exite el vertice";
    } else {
        res = "El recorrido en profundidad, a partir de: " + origen->getNombre() + " es:\n";
        int band, band2;
        Vertice *actual;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        list<Vertice*>::iterator i; // iterador para la lista
        pila.push(origen); // se coloca el vertice origen en una pila
        while (!pila.empty()){ // mientras la pila no este vacía:
            band = 0;
            actual = pila.top();
            pila.pop(); // desepilar el vertice, será el vertice actual
            for (i = lista.begin(); i != lista.end(); i++) { // si el vertice actual no ha sido visitado o está en la lista
                if (*i == actual){
                    band = 1;
                }
            }
            if (band == 0){ // si el vertice actual no ha sido visitado:
                k += 1;
                if(k%5 == 0){
                    res += actual->getNombre() + ",\n"; // se "procesa" el vertice actual
                } else {
                    res += actual->getNombre() + ", "; // se "procesa" el vertice actual
                }
                lista.push_back(actual); // se coloca el vertice actual en la lista de visitados
                Arista *aux = actual->getAdy(); // se va a ubicar en la primera arista del vertice actual
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++) {
                        if (*i == aux->getAdy()) {
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vertice que el vertice actual tiene como destino, y que no ha sido visitado.
                        pila.push(aux->getAdy()); // apilar el vertice
                    }
                    aux = aux->getSig();
                }
            }
        }
    }
    return res + "\n";
}
/**
 * Metodo:              primeroAnchura
 * Descripcion:         Metodo público que permite hacer un recorrido en anchura del grafo
 * recibiendo como parámetros dos string del nombre de los vertices de origen y destino
 * @param pOrigen       variable de tipo string que representa el nombre del vertice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vertice de destino
 */
string Grafo::primeroAnchura(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return primeroAnchura(origen, destino);
}
/**
 * Metodo:              primeroAnchura
 * Descripcion:         Metodo provado que permite hacer un recorrido en anchura del grafo
 * recibiendo como parámetros dos variable de tipo vertice que representan los vertices de origen y destino
 * @param origen        variable de tipo vertice que representa el vertice de origen
 * @param destino       variable de tipo vertice que representa el vertice de destino
 */
string Grafo::primeroAnchura(Vertice *origen, Vertice *destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        int band, band2, band3 = 0, k = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> VerticeVertice; // pila de parejas de vertices
        queue<Vertice*> cola;
        stack<VerticeVertice> pila; // inicializar una pila que almacene parejas de datos origen-destino
        stack<string> pilaRes; // pila que contiene las respuestas.
        list<Vertice*> lista;
        list<Vertice*>::iterator i;
        cola.push(origen); // colocar el vertice origen en una cola
        while (!cola.empty()){ // mientras la cola no este vacía
            band = 0;
            verticeActual = cola.front();
            cola.pop(); // desencolar un vertice, será el vertice actual
            for (i = lista.begin(); i != lista.end(); i++) {
                if (verticeActual == *i) {
                    band =1;
                }
            }
            if (band == 0){ //si el vertice actual no ha sido visitado:
                // mostrar la ruta encontrada
                if (verticeActual == destino){ // si el vertice actual es igual al vertice destino:
                    band3 = 1;
                    destinoActual = destino; // el vertice destino se convierte en destino actual
                    while (!pila.empty()){ // mientras la pila no este vacía
//                        res += destinoActual->getNombre() + "<-"; // imprimir el destino actual; al reves porque en la pila se saca al reves
                        pilaRes.push(destinoActual->getNombre());
                        while (!pila.empty() && pila.top().second != destinoActual){ // mientras la pila no este vacía y el vertice destino en el tope de la pila sea distinto del destino actual
                            pila.pop(); // desapilar
                        }
                        if (!pila.empty()){ // si la pila no está vacía
                            destinoActual = pila.top().first; // el vertice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
//                    break;  // terminar
                }
                lista.push_back(verticeActual); // colocar el vertice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vertice que el vertice actual tiene como destino, y que no ha sido visitado
                        cola.push(aux->getAdy());
                        pila.push(VerticeVertice(verticeActual, aux->getAdy())); // apilar la pareja: vertice actual y vertice destino
                    }
                    aux = aux->getSig(); // encolar el vertice
                }
            }
        }
        if (band3 == 0){ // si la cola se vacio sin encontrar el destino
            // no existe una ruta entre esos vertices
            res = "No hay ruta entre esos dos vertices";
        }
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}
/**
 * Metodo:              primeroProfundidad
 * Descripcion:         Metodo público que permite hacer un recorrido en profundidad
 * estableciendo la primera opcion.
 * @param pOrigen       variable de tipo string que representa el nombre del vertice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vertice de destino
 */
string Grafo::primeroProfundidad(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return primeroProfundidad(origen, destino);
}
/**
 * Metodo:              primeroProfundidad
 * Descripcion:         Metodo privado que permite hacer un recorrido en profundidad
 * estableciendo la primera opcion.
 * @param origen        variable de tipo vertice que representa el vertice de origen
 * @param destino       variable de tipo vertice que representa el vertice de destino
 */
string Grafo::primeroProfundidad(Vertice *origen, Vertice *destino) {
    string res = "";
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        int band, band2, band3 = 0, k = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, Vertice*> parVertices;
        stack<Vertice*> pila;
        list<Vertice*> lista;
        stack<string> pilaRes; // pila que contiene las respuestas.
        stack<parVertices> pilaPar; // inicializar una pila que almacene parejas de datos origen-destino
        list<Vertice*>::iterator i; // se declara un iterador para la lista
        pila.push(origen); // colocar el vertice origen en una pila
        while (!pila.empty()){ // mientras la pila no este vacía
            band = 0;
            verticeActual = pila.top(); // almacenamos el tope de la fila
            pila.pop(); // desapilar un vertice, seá el vertice actual
            for (i = lista.begin(); i != lista.end(); i++){
                if (verticeActual == *i){
                    band = 1;
                }
            }
            if (band == 0){ // si el vertice actual no ha sido visitado (no encontro ese vertice en la lista de visitados
                if (verticeActual == destino){ // si el vertice actual es igual al vertice destino
                    band3 = 1;
                    // mostrar la ruta encontrada
                    destinoActual = destino; // el vertice destino se convierte en destino actual
                    while (!pilaPar.empty()){ // mientras la pila no este vacía
//                        res += destinoActual->getNombre() + "<-"; // imprimir el destino actual
                        pilaRes.push(destinoActual->getNombre());
                        while (!pilaPar.empty() && pilaPar.top().second != destinoActual){ // mientras la pila no este vacía y el vertice destino en el tipo de la pila sea distinto del destino actual
                            pilaPar.pop(); // desapilar
                        }
                        if (!pilaPar.empty()){ // si la pila no está vacía
                            destinoActual = pilaPar.top().first; // el vertice origen en el tope de la pila se convierte en el destino actual
                        }
                    }
                    break; // terminar
                }
                lista.push_back(verticeActual); // colocar el vertice actual en la lista de visitados
                aux = verticeActual->getAdy();
                while (aux != nullptr){
                    band2 = 0;
                    for (i = lista.begin(); i != lista.end(); i++){
                        if (aux->getAdy() == *i){
                            band2 = 1;
                        }
                    }
                    if (band2 == 0){ // para cada vertice que el vertice actual tiene como destino, y que no ha sido visitado
                        pila.push(aux->getAdy()); // apilar el vertice
                        pilaPar.push(parVertices(verticeActual, aux->getAdy())); // apilar la pareja: vertice actual y vertice destino
                    }
                    aux = aux->getSig();
                }
            }
        }
        if (band3 == 0){ // si la pila se vacío sin encontrar el destino
            res = "No hay ruta entre esos dos vertices"; // no existe una ruta entre esos vertices.
        }
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}
/**
 * Metodo:              dijkstra
 * Descripcion:         Metodo público que permite generar la ruta de menor costo.
 * @param pOrigen       variable de tipo string que representa el nombre del vertice de origen
 * @param pDestino      variable de tipo string que representa el nombre del vertice de destino
 */
string Grafo::dijkstra(string &pOrigen, string &pDestino) {
    Vertice *origen = getVertice(pOrigen);
    Vertice *destino = getVertice(pDestino);
    return dijkstra(origen, destino);
}
/**
 * Metodo:              dijkstra
 * Descripcion:         Metodo privado que permite generar la ruta de menor costo.
 * @param origen        variable de tipo vertice que representa el vertice de origen
 * @param destino       variable de tipo vertice que representa el vertice de destino
 */
string Grafo::dijkstra(Vertice *origen, Vertice *destino) {
    string res = "";
    int k = 0;
    if (origen == nullptr || destino == nullptr){
        res = "El origen o destino no existen";
    } else {
        float costoActual = 0;
        int band, band2 = 0;
        Vertice *verticeActual, *destinoActual;
        Arista *aux;
        typedef pair<Vertice*, float> verticeCosto;
        typedef pair<Vertice*, Vertice*> verticeVertice;
        list<verticeCosto> listaCostos;
        list<verticeCosto> listaOrdenada;
        stack<verticeVertice> pila; // inicializar una pila que almacene parejas de datos origen-destino
        stack<string> pilaRes; // pila que contiene las respuestas.
        list<verticeCosto>::iterator i, j;
        listaCostos.emplace_back(origen, 0); // permite recibir solo dos argumentos, lo permite a partir de 11.
        listaOrdenada.emplace_back(origen,0);
        
        while (!listaOrdenada.empty()){ // mientras la lista ordenada no este vacía
            verticeActual = listaOrdenada.front().first; // obtener el primer vertice de la lista ordenada, será el vertice actual.
            costoActual = listaOrdenada.front().second; // el costo asociado a ese vertice será el costo actual
            listaOrdenada.pop_front(); // eliminar el primer vertice de la lista
            if (verticeActual == destino){ // si el vertice actual es igual al vertice destino
                res = "Costo: " + to_string(costoActual);
                band2 = 1;
                // mostar la ruta encontrada y terminar
                destinoActual = destino; // el vertice destino se convierte en destino actual
                while (!pila.empty()){ // mientras la pila no este vacía
//                    res += destinoActual->getNombre() + "<-"; // imprimir el destino actual
                    pilaRes.push(destinoActual->getNombre());
                    while (!pila.empty() && pila.top().second != destinoActual){ // mientras la pila no este vacía y el vertice destino en el tope de la pila sea distinto del destino actual
                        pila.pop(); // desapilar
                    }
                    if (!pila.empty()){ // si la pila no está vacía
                        destinoActual = pila.top().first; // el vertice origen en el tope de la pila se convierte en el destino actual
                    }
                }
                break;
            }
            aux = verticeActual->getAdy();
            while (aux != nullptr){ // para cada vertice que el vertice actual tiene como destino
                band = 0;
                costoActual += aux->getPeso(); // calcular el costo del vertice destino, sumando su costo al costo actual
                for (i = listaCostos.begin(); i != listaCostos.end(); i++){
                    if (aux->getAdy() == i->first){
                        band = 1;
                        if (costoActual < i->second){ // de lo contrario: si el nuevo costo es menor al costo que tiene asociado el vertice en la lista de costos
                            (*i).second = costoActual; // actualizar el costo del vertice en la lista de costos con el nuevo costo
                            for (j = listaOrdenada.begin(); j != listaOrdenada.end(); j++){
                                if (j->first == aux->getAdy()){
                                    (*j).second = costoActual;
                                }
                            }
                            listaOrdenada.sort(comparacion);
                            pila.push(verticeVertice(verticeActual, aux->getAdy())); // se apila la paraja: vertice actual y vertice destino
                            costoActual -= aux->getPeso(); // actualizar el costo del vertice en la lista ordenada con el nuevo costo
                        }
                    }
                }
                if (band == 0){ // si el vertice no se encuentra en la lista de costos
                    listaCostos.emplace_back(aux->getAdy(), costoActual); // permite recibir solo dos argumentos, lo permite a partir de 11.
                    listaOrdenada.emplace_back(aux->getAdy(), costoActual);
//                    listaCostos.push_back(verticeCosto(aux->getAdy(), costoActual)); // insertar el vertice en la lista de costos, asociando el nuevo costo
//                    listaOrdenada.push_back(verticeCosto(aux->getAdy(), costoActual)); // insertar el vertice en la lista ordenada, asociando el nuevo costo
                    listaOrdenada.sort(comparacion);
                    pila.push(verticeVertice(verticeActual, aux->getAdy())); // se apila la pareja: vertice actual y vertice destino
                    costoActual -= aux->getPeso();
                }
                aux = aux->getSig();
            }
        }
        if (band2 == 0){ // si la lista ordenada se vacio sin encontrar el destino: no existe una ruta entre esos vertice
            res = "No hay ruta entre esos dos vertices"; // no existe una ruta entre esos vertices.
        }
        res += "\n";
        while (!pilaRes.empty()){
            if (k > 0) {
                res += "->";
            }
            res += pilaRes.top();
            k += 1;
            pilaRes.pop();
        }
    }
    return res + "\n";
}


/**
 * Metodo:              comparacion
 * Descripcion:         Metodo que permite comparar costos
 * @param a             variable de tipo pair<Vertice, int>
 * @param b             variable de tipo pair<Vertice, int>
 * @return              variable de tipo bool, true si a es menor a b, y false caso contrario
 */
bool Grafo::comparacion(pair<Vertice *, int> a, pair<Vertice *, int> b) {
    return a.second < b.second;
}
