//
// Created by roxan on 5 dic. 2021.
//

#include "Vertice.h"


Vertice::Vertice(int indice, const string &nombre, Vertice *next, Arista *ady,
                 Arista *precedente) : indice(indice),nombre(nombre),next(next),ady(ady),precedente(precedente) {
    setIndice(indice);
    setNombre(nombre);
}

Vertice::~Vertice() {

}

const string &Vertice::getNombre() const {
    return nombre;
}

void Vertice::setNombre(const string &nombre) {
    Vertice::nombre = nombre;
}

Vertice *Vertice::getNext() const {
    return next;
}

void Vertice::setNext(Vertice *next) {
    Vertice::next = next;
}

Arista *Vertice::getAdy() const {
    return ady;
}

void Vertice::setAdy(Arista *ady) {
    Vertice::ady = ady;
}

int Vertice::getIndice() const {
    return indice;
}

void Vertice::setIndice(int indice) {
    Vertice::indice = indice;
}

Arista *Vertice::getPrecedente() const {
    return precedente;
}

void Vertice::setPrecedente(Arista *precedente) {
    Vertice::precedente = precedente;
}

