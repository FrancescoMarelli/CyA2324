// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Automatons
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include <iostream>
#include <vector>
#include <set>
#include <map>

#include "Alphabet.h"
#include "State.h"
#include "Language.h"
#include "Transition.h"

#pragma once

class Automaton {
 private:
    Alphabet alphabet_;
    std::set<State> stateSet_;
    std::set<State> finalState_;
    State starting_;
    std::set<Transition> transition_;

 public:
    Automaton() {}
    ~Automaton() {}

    Language operate();
};
