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

#include <string>

/**
 * @brief Construct a new Language:: Language object
 * 
 * @param language 
 */
Language::Language(std::set<String> language) {
    language_.insert(String(kEpsilon));
    for (const String &string : language) {
        language_.insert(string);
    }
}

/**
 * @brief Formatted Extraction operator for Language
 * 
 * @param os 
 * @param language 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Language &language) {
    for (const String &string : language.getLanguage()) {
        os << string;
    }
    return os;
}


/**
 * @brief Formatted Write method for Language
 * 
 * @param os 
 */
void Language::write(std::ostream& os) const {
    os << "{";
    for (auto it = language_.begin(); it != language_.end(); it++) {
        if (it != language_.begin() && it != language_.end()) {
            os << ", ";
        }
        os << *it;
    }
    os << "}" << std::endl;
}



