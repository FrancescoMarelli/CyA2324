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
 * @param isStarting 
 */
State::State(std::string& label, bool& isFinal, bool& isStarting) {
  label_ = label;
  isFinal_ = isFinal;
  isStarting_ = isStarting;
}

