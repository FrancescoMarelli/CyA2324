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
    State startingState_;
    int howManyStates_;
    std::set<Transition> transition_;

 public:
    Automaton() {}
    ~Automaton() {}
    void setAlphabet(Alphabet alphabet) { alphabet_ = alphabet; }
    Alphabet getAlphabet() { return alphabet_; }
    void setStatesCount(std::string howManyStates);
    void addStates(State state);
    void setStartingState(std::string state);
    
    
    void addTransition(Transition transition) { transition_.insert(transition); }
    std::set<Transition> getTransition() { return transition_; }

    bool isState(State);
    bool alphabetOk(Symbol);
    
    void reader(std::ifstream&);
    std::vector<std::string> getLines(std::ifstream&);
    void readAlphabet(std::string, Alphabet&);
    void readStatesCount(std::string);
    void readStartingState(std::string);
    void readTransition(std::string);
   
};
