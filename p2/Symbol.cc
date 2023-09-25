// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Alfabetos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/09/2023
#include "Symbol.h"

/**
 * @brief 
 * 
 * @param os 
 * @param symbol 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Symbol &symbol) {
    os << symbol.symbol_ << " ,";
    return os;
}

/**
 * @brief 
 * 
 * @param is 
 * @param symbol 
 * @return std::istream& 
 */
std::istream &operator>>(std::istream &is, const Symbol &symbol) {
    is >> symbol.symbol_;
    return is;
}

/**
 * @brief 
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Symbol::operator==(const Symbol& symbol) const {
    return this->getSymbol() == symbol.getSymbol();
}

bool Symbol::operator!=(const Symbol& symbol) const {
    return this->getSymbol() != symbol.getSymbol();
}

bool Symbol::operator<(const Symbol& other) const {
    return getSymbol() < other.getSymbol();
}
