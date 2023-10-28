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
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>

#include "Alphabet.h"
#include "Symbol.h"

class Grammar {
 private:
    Alphabet alphabet_;
    std::set<Symbol> nonTerminals_;
    Symbol startSymbol_;
    std::map<Symbol, std::set<std::string>> productions_;

 public:
    Grammar() {}
    ~Grammar() {}
    void fileReader(std::ifstream&);
    void setAlphabet(Alphabet alphabet) { alphabet_ = alphabet ; }
    Alphabet getAlphabet() const { return alphabet_; }
};