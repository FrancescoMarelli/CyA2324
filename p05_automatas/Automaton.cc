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
#include <string>
#include <sstream>

#include "Automaton.h"

void Automaton::reader(std::ifstream& file) {
    std::string line;
    Alphabet alphabet;

    // read alphabet
    std::getline(file >> std::ws, line);
    std::istringstream iss(line);
    char c;
    while (iss >> c) {
        Symbol symbol(std::string(1, c));
        alphabet.addSymbol(symbol);
    }
}
