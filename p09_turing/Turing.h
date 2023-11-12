// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulador de máquina de Turing
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 11/11/2023

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <algorithm>

#include "Alphabet.h"
#include "State.h"
#include "Transition.h"
#include "Symbol.h"
#include "String.h"

const std::string kFinal = "1";  // NOLINT
const std::string kBlank = "$";  // NOLINT

#pragma once

class Turing {
 private:
    std::set<State> states_;  //  Enteros
    State initialState_;
    std::set<State> finalStates_;
    int nStates_;
    int nTransitions_;
    std::set<Transition> transitions_;
    Symbol blankSymbol_;
    std::vector<Symbol> tape_;

 public:
    Turing() : nStates_(0), nTransitions_(0), blankSymbol_(kBlank) {}
    ~Turing() {}

    std::set<State> getFinalStates() { return finalStates_; }

    void fileReader(std::ifstream&);
    std::vector<std::string> linesReader(std::ifstream&);
    void setStates(std::vector<std::string>&);
    void setTransitions(std::vector<std::string>&);
    void setTape(std::ifstream&);
    std::vector<Symbol> getTape() { return tape_;}
    friend std::ostream& operator<<(std::ostream&, const Turing&);
    void printTape(State&, int);

    bool acceptString(std::vector<Symbol> const&);
};
