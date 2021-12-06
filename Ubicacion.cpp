//
// Created by roxan on 5 dic. 2021.
//

#include "Ubicacion.h"

Ubicacion::Ubicacion(long num, const string &nombre, Ubicacion *next) : num(num), nombre(nombre), next(next) {
    setNum(num);
    setNombre(nombre);
}

Ubicacion::~Ubicacion() {
    if (getNext() == nullptr) delete next;
}

long Ubicacion::getNum() const {
    return num;
}

void Ubicacion::setNum(long num) {
    Ubicacion::num = num;
}

const string &Ubicacion::getNombre() const {
    return nombre;
}

void Ubicacion::setNombre(const string &nombre) {
    Ubicacion::nombre = nombre;
}

Ubicacion *Ubicacion::getNext() const {
    return next;
}

void Ubicacion::setNext(Ubicacion *next) {
    Ubicacion::next = next;
}
