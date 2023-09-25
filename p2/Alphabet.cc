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

#include "Alphabet.h"

void Alphabet::write(std::ostream &os) const {
  os << "{";
  for (const Symbol &symbol : alphabet_) {
    os << symbol;
  }
  os << "}";
}




