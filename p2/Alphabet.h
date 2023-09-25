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

#pragma once

#include <iostream>
#include <set>
#include <algorithm>

#include "Symbol.h"

class Alphabet {
    private:
     std::set<Symbol> alphabet_;

    public:
     Alphabet(std::set<Symbol> alphabet) { setAlphabet(alphabet); }
     Alphabet() {}
     ~Alphabet(){}

     void setAlphabet(std::set<Symbol> alphabet) { alphabet_ = alphabet; }
     std::set<Symbol> getAlphabet() const { return alphabet_; }
     void addSymbol(Symbol symbol) { alphabet_.insert(symbol); }

     bool operator=(const Alphabet& other) const;
    
     void write(std::ostream &os) const;
};