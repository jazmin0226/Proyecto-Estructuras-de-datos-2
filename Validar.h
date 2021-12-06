//
// Created by roxan on 5 dic. 2021.
//

#ifndef PROYECTOEDMAPA_VALIDAR_H
#define PROYECTOEDMAPA_VALIDAR_H

#include <iostream>
#include <math.h>
using namespace std;

class Validar {
public:
    int ingresarInt(string);

    int nPrimoMenorQue(int); // retorna el número primo menor al indice pasado por argumento

    bool esPrimo(int); // Analiza si un número es primo

    static int stringASCII(string &);

    static int hashing(long num, long maximo);
};



#endif //PROYECTOEDMAPA_VALIDAR_H
