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

#include "Grammar.h"


/**
 * @brief 
 * 
 * @param file 
 */
void Grammar::fileReader(std::ifstream& file) {
    // Alphabet size
    std::string line;
    std::getline(file, line);
    int alphabetSize = std::stoi(line);
    for (int i = 0; i < alphabetSize; i++) {
        if (std::getline(file, line)) {
            alphabet_.addSymbol(Symbol(line));
        }
    }
}