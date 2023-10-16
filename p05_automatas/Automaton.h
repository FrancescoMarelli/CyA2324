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
#include <string>

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
    State currentState_;

 public:
    explicit Automaton(std::ifstream&);
    ~Automaton() {}


    //  Setters and getters
    void setAlphabet(Alphabet alphabet) { alphabet_ = alphabet; }
    Alphabet getAlphabet() { return alphabet_; }
    void setStatesCount(std::string howManyStates);
    State getState(std::string);
    void setStartingState(std::string state);
    std::set<Transition> getTransition() { return transition_; }


    //  Adders
    void addTransition(Transition transition) { transition_.insert(transition); }
    void addStates(State state);


    // Automaton operations
    bool alphabetOk(Symbol);
    bool isAccepted(std::set<State>);
    void buildAutomaton(std::ifstream&);
    void checkStrings(std::vector<String>&);
    bool AutomatonCheck(String&);

    //  Readers
    std::vector<std::string> getLines(std::ifstream&);
    void readAlphabet(std::string);
    void readStatesCount(std::string);
    void readStartingState(std::string);
    void readStates(std::vector<std::string>);
    void readTransition(std::string);
    std::vector<String> readStrings(std::vector<std::string>&);
};


