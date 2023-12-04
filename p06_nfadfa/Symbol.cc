// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/10/2023
#include "Symbol.h"

/**
 * @brief 
 * 
 * @param os 
 * @param symbol 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Symbol &symbol) {
    os << symbol.symbol_;
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
    is >> symbol;
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


/**
 * @brief 
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Symbol::operator!=(const Symbol& symbol) const {
    return this->getSymbol() != symbol.getSymbol();
}


/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Symbol::operator<(const Symbol& other) const {
    return getSymbol() < other.getSymbol();
}
