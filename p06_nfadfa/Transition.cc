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
#include <utility>

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
  auto it1 = transition_.begin();
  auto it2 = other.transition_.begin();

  while (it1 != transition_.end() && it2 != other.transition_.end()) {
    if (it1->first < it2->first) {
      return true;
    } else if (it2->first < it1->first) {
      return false;
    } else if (it1->second < it2->second) {
      return true;
    } else if (it2->second < it1->second) {
      return false;
    }

    ++it1;
    ++it2;
  }

  return (it1 == transition_.end() && it2 != other.transition_.end());
}


/**
 * @brief 
 * 
 * @param origin 
 * @param symbol 
 * @return State 
 */
State Transition::getStateDestiny(const State& origin, const Symbol& symbol) const {
  auto it = transition_.find(std::make_pair(origin, symbol));
  if (it != transition_.end()) {
    return it->second;
  } else {
    return State();
  }
}


/**
 * @brief 
 * 
 * @return State 
 */
State Transition::getStateOrigin() const {
  auto it = transition_.begin();
  return it->first.first;
}


/**
 * @brief 
 * 
 * @return Symbol 
 */
Symbol Transition::getSymbol() const {
  auto it = transition_.begin();
  return it->first.second;
}


/**
 * @brief 
 * 
 * @param symbol 
 * @param stateOrigin 
 * @param stateDestiny 
 */
void Transition::setTransition(Symbol symbol, State stateOrigin, State stateDestiny) {  // NOLINT
  transition_[std::make_pair(stateOrigin, symbol)] = stateDestiny;
}


/**
 * @brief 
 * 
 * @param os 
 * @param transition 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  for (auto it = transition.transition_.begin(); it != transition.transition_.end(); ++it) {
    os << it->first.first << " -- " << it->first.second << " --> " << it->second << std::endl;
  }
  return os;
}
