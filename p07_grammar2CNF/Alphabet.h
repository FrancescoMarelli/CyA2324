// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/202323

#pragma once

#include <iostream>
#include <set>
#include <algorithm>
#include <string>


#include "Symbol.h"


class Alphabet {
 private:
    std::set<Symbol> alphabet_;

 public:
    explicit Alphabet(std::set<Symbol> alphabet) { setAlphabet(alphabet); }
    Alphabet(const Alphabet& other) { alphabet_ = other.getAlphabet(); }
    Alphabet() {}
    ~Alphabet() {}

    void setAlphabet(std::set<Symbol> alphabet) { alphabet_ = alphabet; }
    std::set<Symbol> getAlphabet() const { return alphabet_; }
    void addSymbol(Symbol symbol);
    bool belongsToAlphabet(Symbol);

    bool operator=(const Alphabet& other) const;
    void write(std::ostream &os) const;
    friend std::ostream &operator<<(std::ostream &os, const Alphabet &alphabet);
};
