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

void Transition::setTransition(Symbol symbol, State stateOrigin, State stateDestiny) {
  symbol_ = symbol;
  stateOrigin_ = stateOrigin;
  stateDestiny_ = stateDestiny;
}
