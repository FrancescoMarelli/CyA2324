// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/10/2023
#include <iostream>
#include <vector>
#include <set>
#include <istream>
#include <string>
#include <map>
#include <utility>
#include <queue>

#include "Alphabet.h"
#include "State.h"
#include "String.h"
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
    Automaton();
    ~Automaton() {}


    //  Setters and getters
    void setAlphabet(const Alphabet& alphabet) { alphabet_.setAlphabet(alphabet.getAlphabet()); }
    Alphabet getAlphabet() { return alphabet_; }
    void setStatesCount(std::string howManyStates);
    State getState(std::string);
    void setStartingState(std::string state);
    std::set<Transition> getTransition() { return transition_; }
    int getSize() { return stateSet_.size(); }


    //  Adders
    void addTransition(Transition transition);
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
    Automaton SubSetConstruction();
    State createDFAState(const std::set<State>&, std::map<std::set<State>, State>&, std::queue<std::set<State>>&);
    std::set<State> eClosure(const State& state);
    std::set<State> move(const State&, const Symbol&);
    void setDFAFinals(const std::map<std::set<State>, State>&);
    void setDFAProperties(std::map<std::set<State>, State>& , const std::set<State>&, Alphabet);
    bool isDFA();

    //  Printers
    void outputDFA(std::ofstream&);
};

