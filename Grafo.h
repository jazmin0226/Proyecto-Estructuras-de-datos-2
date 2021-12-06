//
// Created by roxan on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_GRAFO_H
#define PROYECTOEDMAPA_GRAFO_H


#include "Vertice.h"
#include <queue> // para la cola
#include <list> // para la lista
#include <stack> // para la pila

class Grafo {
public:
    Grafo(Vertice *head = nullptr, Vertice *tail = nullptr, int tam = 0);

    virtual ~Grafo();

    Vertice *getHead() const;

    void setHead(Vertice *head);

    Vertice *getTail() const;

    void setTail(Vertice *tail);

    int getTam() const;

    void setTam(int tam);

    bool esListaVacia() const;

    int numVertices() const;

    Vertice *getVertice(string &nombre);

    Vertice *getVertice(int indice);

    void insertVertice(int indice, string & nombre);

    string insertaArista(string &salida, string &llegada, float peso);

    string listaSucesores();

    string listaSucesoresXVertice(int indice);

    string listaPredecesores();

    string listaPredecesoresXVertice(int indice);

    string eliminarArista(string &salida, string &llegada);

    string eliminarVertice(string &pEliminar);

    void eliminarGrafo();

    string recorridoAnchura(string &pOrigen);

    string recorridoProfundidad(string &pOrigen);

    string primeroAnchura(string &pOrigen, string &pDestino);

    string primeroProfundidad(string &pOrigen, string &pDestino);

    string dijkstra(string &pOrigen, string &pDestino);
private:
    Vertice *head;
    Vertice *tail;
    int tam;

    void insertarAlIincio(int indice, string & nombre);

    void insertarAlFinal(int indice, string & nombre);

    string eliminarArista(Vertice * origen, Vertice * destino);

    string eliminarVertice(Vertice * vert);

    string recorridoAnchura(Vertice *origen);

    string recorridoProfundidad(Vertice *origen);

    string primeroAnchura(Vertice * origen, Vertice * destino);

    string primeroProfundidad(Vertice * origen, Vertice * destino);

    string dijkstra(Vertice * origen, Vertice * destino);

    static bool comparacion(pair<Vertice*, int> a, pair<Vertice*, int> b);
};


#endif //PROYECTOEDMAPA_GRAFO_H
