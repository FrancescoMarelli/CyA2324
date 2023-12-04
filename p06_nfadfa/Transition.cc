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

#include <string>
#include <utility>

#include "Transition.h"

/**
 * @brief Construct a new Transition:: Transition object
 * 
 * @param symbol 
 * @param stateOrigin 
 * @param stateDestiny 
 */
Transition::Transition(State stateOrigin, Symbol symbol, State stateDestiny) {
  setTransition(stateOrigin, symbol, stateDestiny);
}



/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Transition::operator<(const Transition& other) const {
  if (origin_ < other.origin_) {
    return true;
  } else if (origin_ == other.origin_) {
    if (symbol_ < other.symbol_) {
      return true;
    } else if (symbol_ == other.symbol_) {
      if (destiny_ < other.destiny_) {
        return true;
      }
    }
  }
  return false;
}


/**
 * @brief 
 * 
 * @param origin 
 * @param symbol 
 * @return State 
 */
State Transition::getStateDestiny() const {
  return destiny_;
}


/**
 * @brief 
 * 
 * @return Symbol 
 */
Symbol Transition::getSymbol() const {
  return symbol_;
}


/**
 * @brief 
 * 
 * @return State 
 */
State Transition::getStateOrigin() const {
  return origin_;
}

/**
 * @brief 
 * 
 * @param os 
 * @param transition 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << transition.getStateOrigin() << transition.getStateDestiny() << " " << transition.getSymbol();
  return os;
}


/**
 * @brief 
 * 
 * @param stateDestiny 
 * @param symbol 
 */
void Transition::setTransition(State stateOrigin, Symbol symbol, State stateDestiny) {
  origin_ = stateOrigin;
  destiny_ = stateDestiny;
  symbol_ = symbol;
}
