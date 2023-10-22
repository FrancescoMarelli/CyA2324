// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un Automata finito
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
    void addState(State state);


    //  Auxiliars
    bool isAccepted(std::set<State>);

    // Automaton operations
    void buildAutomaton(std::ifstream&);
    void elaborateStrings(std::ifstream&);
    void checkStrings(std::vector<String>&);
    bool AutomatonStringsCheck(String&);

    //  Readers
    std::vector<std::string> linesReader(std::ifstream&);
    void alphabetReader(std::string);
    void statesCounterReader(std::string);
    void startingStateReader(std::string);
    void statesReader(std::vector<std::string>);
    void transitionsReader(std::string);
    std::vector<String> stringsReader(std::vector<std::string>&);

    // Convert to DFA
    //void SubSetConstruction();
    //std::set<State> eClosure(const State& state);
};

