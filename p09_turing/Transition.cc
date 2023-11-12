// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulador de máquina de Turing
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 11/11/2023

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
Transition::Transition(State stateOrigin, Symbol symbol, State stateDestiny, Symbol toWrite, std::string direction) {
  setTransition(stateOrigin, symbol, stateDestiny, toWrite, direction);
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
    if (toRead_ < other.toRead_) {
      return true;
    } else if (toRead_ == other.toRead_) {
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
Symbol Transition::getToRead() const {
  return toRead_;
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
 * @return Symbol 
 */
Symbol Transition::getToWrite() const {
  return toWrite_;
}


/**
 * @brief 
 * 
 * @return std::string 
 */
std::string Transition::getDirection() const {
  return direction_;
}


/**
 * @brief 
 * 
 * @param os 
 * @param transition 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Transition& transition) {
  os << transition.getStateOrigin() << " " << transition.getToRead() << " " << transition.getToWrite()
     << " " << transition.getDirection() << " " << transition.getStateDestiny();
  return os;
}


/**
 * @brief 
 * 
 * @param stateDestiny 
 * @param symbol 
 */
void Transition::setTransition(State stateOrigin, Symbol symbol, State stateDestiny, Symbol toWrite, std::string direction) {   // NOLINT
  origin_ = stateOrigin;
  destiny_ = stateDestiny;
  toRead_ = symbol;
  toWrite_ = toWrite;
  if (direction == "R") {
    direction_ = "R";
  } else if (direction == "L") {
    direction_ = "L";
  } else if (direction == "S") {
    direction_ = "S";
  } else {
    std::cout << "Error: Invalid direction" << std::endl;
  }
}
