// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un Automata finito
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023

#include <string>

#include "Transition.h"

/**
 * @brief Construct a new Transition:: Transition object
 * 
 * @param symbol 
 * @param stateOrigin 
 * @param stateDestiny 
 */
Transition::Transition(Symbol symbol, State stateOrigin, State stateDestiny) {
  setTransition(symbol, stateOrigin, stateDestiny);
}

/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Transition::operator<(const Transition& other) const {
  if (stateOrigin_ == other.getStateOrigin()) {
    if (symbol_ == other.getSymbol()) {
      return stateDestiny_ < other.getStateDestiny();
    } else {
      return symbol_ < other.getSymbol();
    }
  } else {
    return stateOrigin_ < other.getStateOrigin();
  }
}


/**
 * @brief 
 * 
 * @param symbol 
 * @param stateOrigin 
 * @param stateDestiny 
 */
void Transition::setTransition(Symbol symbol, State stateOrigin, State stateDestiny) {  // NOLINT
  symbol_ = symbol;
  stateOrigin_ = stateOrigin;
  stateDestiny_ = stateDestiny;
}


/**
 * @brief 
 * 
 * @param os 
 * @param transition 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Transition &transition) {
  os << transition.getStateOrigin().getLabel() << " "
     << transition.getSymbol().getSymbol() << " " << transition.getStateDestiny().getLabel();
  return os;
}
