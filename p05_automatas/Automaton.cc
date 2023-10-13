// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Automatas
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include <string>
#include <sstream>

#include "Automaton.h"

const bool kFinal = true;

void Automaton::reader(std::ifstream& file) {
    std::string line;
    Alphabet alphabet;

    // read alphabet
    std::getline(file >> std::ws, line);
    std::istringstream iss(line);
    char c;
    while (iss >> c) {
        Symbol symbol(std::string(1, c));
        alphabet_.addSymbol(symbol);
    }

    // read number of states and starting state
    std::getline(file >> std::ws, line);
    setStatesCount(std::stoi(line));
    std::getline(file >> std::ws, line);
    setStartingState(State(line, !kFinal));

     // read transitions
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string stateLabel;
        bool isFinal = false;
        int numTransitions;
        iss >> stateLabel >> isFinal >> numTransitions;
        State state(stateLabel, isFinal);
        addStates(state);
        for (int i = 0; i < numTransitions; i++) {
            std::string symbol;
            std::string destLabel;
            iss >> symbol >> destLabel;
            Transition transition(Symbol(symbol), state, State(destLabel, isFinal));
            getTransition().insert(transition);
        }
    }
}
