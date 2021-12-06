//
// Created by roxan on 5 dic. 2021.
//


#include "TablaHash.h"


TablaHash::TablaHash() {
    for (int i = 0; i < MAX; ++i) {
        vectorUbic[i] = nullptr;
    }
}

TablaHash::~TablaHash() {
    for (int i = 0; i < MAX; ++i) {
        if (vectorUbic[i] != nullptr){
            delete vectorUbic[i];
        }
    }
}

void TablaHash::addUbicacion(int indice, Ubicacion *ptr) {
    if (vectorUbic[indice] == nullptr){
        vectorUbic[indice] = ptr;
    } else {
        Ubicacion * aux = vectorUbic[indice];
        while (aux->getNext() != nullptr){
            aux = aux->getNext();
        }
        aux->setNext(ptr);
    }
}

Ubicacion *TablaHash::getUbicacion(int indice, long num) {
    Ubicacion * aux = vectorUbic[indice];
    while (aux != nullptr && aux->getNum() != num){
        aux = aux->getNext();
    }
    return aux;
}
