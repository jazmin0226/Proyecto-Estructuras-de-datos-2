//
// Created by Jazmin Roxana Arias Salazar on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_GESTOR_H
#define PROYECTOEDMAPA_GESTOR_H

#include "Grafo.h"
#include "Validar.h"
#include "TablaHash.h"

class Gestor {
public:
    Gestor();

    Grafo *getGrafo() const;

    void setGrafo(Grafo *grafo);

    void insertVertice(string nombre);

    string insertaArista(string salida, string llegada, float peso);

    string listaAdyacencia();

    string listaAdyacenciaXVertice(string vertice);

    string listaPredecesores();

    string listaPredecesoresXVertice(string vertice);

    string eliminarArista(string salida, string llegada);

    string eliminarVertice(string vertice);

    void eliminarGrafo();

    int numVertices();

    bool vacio() const;

    string recorridoAnchura(string pOrigen);

    string recorridoProfundidad(string pOrigen);

    string primeroAnchura(string pOrigen, string pDestino);

    string primeroProfundidad(string pOrigen, string pDestino);

    string dijkstra(string pOrigen, string pDestino);

    /*
     * Tabla Hash
     */
    void addUbicaciones(string ubic);

    string obtenerUbicacion(string ubic);

private:
    Grafo *grafo;
    TablaHash *tablaHash;
};


#endif //PROYECTOEDMAPA_GESTOR_H
