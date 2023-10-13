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
#include <istream>

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
    int howManyStates_;
    std::set<Transition> transition_;

 public:
    Automaton() {}
    ~Automaton() {}
    void setAlphabet(Alphabet alphabet) { alphabet_ = alphabet; }
    Alphabet getAlphabet() { return alphabet_; }
    void setStatesCount(int howManyStates) { howManyStates_ = howManyStates; }
    void addStates(State state) { stateSet_.insert(state); }
    void setStartingState(State starting) { starting_ = starting; }
    void reader(std::ifstream&);
    void setFinalState(std::set<State> finalState) { finalState_ = finalState; }
    void addTransition(Transition transition) { transition_.insert(transition); }
    std::set<Transition> getTransition() { return transition_; }

};
