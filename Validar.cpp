//
// Created by Jazmin Roxana Arias Salazar on 5 dic. 2021.
//


#include "Validar.h"

int Validar::ingresarInt(string pValor) {
    try {
        return stoi(pValor);
    } catch (exception e) {
//        cout << e.what();
        return -1;
    }
}
/**
 * Método:              nPrimoMenorQue
 * Descripción:         Método que permite obtener el número primo menor al indice
 * pasado por argumento
 * @param pValor        variable de tipo int que representa el indice base para
 * calcular el indice primo menor que este.
 * @return              variable de tipo int que representa el indice del número
 * primo menor que el indice ingresado
 */
int Validar::nPrimoMenorQue(int pValor) {
    if (pValor < 0){
        return 0;
    } else {
        int i = 0;
        while (!esPrimo(pValor)) {
            i++;
            pValor -= 1;
        }
        return pValor;
    }
}
/**
 * Método:              esPrimo
 * Descripción:         Método que permite verificar si un número es primo
 * @param pValor        variable de tipo int que representa el número a verificar
 * @return              variabla de tipo bool, true si es primo y false caso contrario.
 */
bool Validar::esPrimo(int pValor) {
    int i = 2, j = 0;
    while (j < 2 && i <= pValor){
        if (pValor % i == 0){
            j += 1;
        }
        i ++;
    }
    if (j == 1){
        return true;
    } else {
        return false;
    }
}

int Validar::stringASCII(string & texto) {
    int val, acum = 0;
    unsigned char letra;
    for (int i = 0; i < texto.length(); ++i) {
        letra = texto[i];
        val = letra;
        acum += val;
    }
    return acum;
}

int Validar::hashing(long num, long maximo) {
    int valor = sqrt(num);
    return valor%maximo;
}

