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

#include "State.h"

/**
 * @brief Construct a new State:: State object
 * 
 * @param label 
 * @param isFinal 
 */
State::State(std::string& label, const bool& isFinal) {
  label_ = label;
  isFinal_ = isFinal;
}

/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool State::operator==(const State& other) const {
  return label_ == other.getLabel() && isFinal_ == other.getIsFinal();
}

/**
 * @brief 
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool State::operator<(const State& other) const {
  return label_ < other.getLabel();
}

/**
 * @brief 
 * 
 * @param is 
 * @param state 
 * @return std::istream& 
 */
std::istream &operator>>(std::istream &is, State &state) {
  std::string label;
  is >> label;
  state.setLabel(label);
  return is;
}