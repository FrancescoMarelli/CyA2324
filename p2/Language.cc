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

#include "Language.h"

/**
 * @brief 
 * 
 * @param os 
 * @param language 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Language &language) {
    os << "{";
    for (const String &string : language.getLanguage()) {
        os << string << " ,";
    }
    os << "}";
    return os;
}



