// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/2023
#include "Production.h"

/**
 * @brief 
 * 
 * @param os 
 * @param production 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Production& production) {
    os << production.left_ << " " << production.right_;
    return os;
}
