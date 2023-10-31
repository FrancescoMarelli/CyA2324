// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/2023
#include "Alphabet.h"

const std::string kEpsilon = "&";  // NOLINT


/**
 * @brief Write overloaded operator
 * 
 * @param os 
 */
void Alphabet::write(std::ostream &os) const {
    if (alphabet_.size() == 0) {
        os << "";
        return;
    }

    for (auto symbol : alphabet_) {
        os << symbol;
    }
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


/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
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
    } else {
        alphabet_.insert(Symbol(""));
    }
}


/**
 * @brief 
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Alphabet::belongsToAlphabet(Symbol symbol) {
    return alphabet_.find(symbol) != alphabet_.end() || symbol.getSymbol() == kEpsilon;
}


/**
 * @brief 
 * 
 * @return std::vector<Symbol> 
 */
std::vector<Symbol> Alphabet::getAlphabetVector() const {
    std::vector<Symbol> alphabetVector;
    for (auto it = alphabet_.begin(); it != alphabet_.end(); it++) {
        alphabetVector.push_back(*it);
    }
    return alphabetVector;
}





