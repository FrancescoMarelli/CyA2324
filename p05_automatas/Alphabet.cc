// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Automatas
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include "Alphabet.h"

const std::string kEpsilon = "&";  // NOLINT


void Alphabet::write(std::ostream &os) const {
    if (alphabet_.size() == 0) {
        os << "";
        return;
    }
    if (alphabet_.size() > 1) {
    os << "{";
        for (auto it = alphabet_.begin(); it != alphabet_.end(); it++) {
            if (it != alphabet_.begin() && it != alphabet_.end()) {
                os << ", ";
            }
           os << *it;
        }
    }
    os << "}" << std::endl;
}


/**
 * @brief 
 * 
 * @param os 
 * @param alphabet 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Alphabet &alphabet) {
    alphabet.write(os);
    return os;
}


bool Alphabet::operator=(const Alphabet& other) const {
    if (alphabet_.size() != other.getAlphabet().size()) {
        return false;
    }
    for (auto it = alphabet_.begin(); it != alphabet_.end(); it++) {
        if (other.getAlphabet().find(*it) == other.getAlphabet().end()) {
            return false;
        }
    }
    return true;
}


/**
 * @brief 
 * 
 * @param symbol 
 */
void Alphabet::addSymbol(Symbol symbol) {
    if (symbol.getSymbol() != kEpsilon) {
        alphabet_.insert(symbol);
    } else if (symbol.getSymbol() == kEpsilon) {
        alphabet_.insert(Symbol(""));
    }
}





