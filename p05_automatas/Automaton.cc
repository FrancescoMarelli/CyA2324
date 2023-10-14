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
#include <iterator>

#include "Automaton.h"

const bool kFinal = true;


std::vector<std::string> Automaton::getLines(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    return lines;
}

void Automaton::reader(std::ifstream& file) {
    Alphabet alphabet;
    std::vector<std::string> lines = getLines(file);

    readAlphabet(lines[0], alphabet);
    readStatesCount(lines[1]);
    readStartingState(std::string(1, lines[2][0]));

    for (int i = 3; i < lines.size(); i++)
        readTransition(lines[i]);

    // check if the automaton transitions are correct
    for (auto transition : transition_) {
        std::cout << transition.getSymbol().getSymbol() << " " << transition.getStateOrigin().getLabel()
        << " " << transition.getStateDestiny().getLabel() << std::endl;
    }
}

void Automaton::readAlphabet(std::string line, Alphabet& alphabet) {
    for (int i = 0; i < line.size(); i++) {
        std::string symbol(1, line[i]);
        if (alphabetOk(Symbol(symbol)))
            alphabet.addSymbol(Symbol(symbol));
    }
}

void Automaton::readStatesCount(std::string line) {
    if (line.empty()) {
        std::cout << "Error: el numero de estados no puede estar vacio, comprueba input.fa" << std::endl;
        return;
    }
    if (!isdigit(line[0])) {
        std::cout << "Error: el numero de estados debe ser un numero, comprueba input.fa" << std::endl;
        return;
    }
    howManyStates_ = std::stoi(line);
}

void Automaton::readStartingState(std::string line) {
    if (line.length() > 1) {
        std::cout << line.length() << std::endl;
        std::cout << "Error: el estado inicial debe ser un solo caracter, comprueba input.fa" << std::endl;
        return;
    }
    startingState_ = State(line, !kFinal);
}

void Automaton::readTransition(std::string line) {
    std::istringstream iss(line);
    std::string stateLabel;
    bool isFinal;
    int  numTransitions;
    iss >> stateLabel >> isFinal >> numTransitions;
    State state(stateLabel, isFinal);
    addStates(state);
    for (int j = 0; j < numTransitions; j++) {
        std::string symbol;
        std::string destLabel;
        iss >> symbol >> destLabel;
        Transition transition(Symbol(symbol), state, State(destLabel, isFinal));
        addTransition(transition);
    }
}


// Falta definir bien esto. 
void Automaton::addStates(State state) {
    if (stateSet_.size() > howManyStates_) {
        std::cout << "stateSet_.size() = " << stateSet_.size() << "and howManyStates_= " << howManyStates_ <<std::endl;
        std::cout << "Error: el numero de estados definidos no coincide, comprueba input.fa" << std::endl;
        return;
    }
    if (isState(state)) stateSet_.insert(state);
}


bool Automaton::isState(State state) {
    return false;
}

bool Automaton::alphabetOk(Symbol symbol) {
    bool result = (alphabet_.getAlphabet().find(symbol) != alphabet_.getAlphabet().end());
    return result;
}


/**
 * @brief 
 * 
 * @param state 
 */
void Automaton::setStartingState(std::string state) {
        if (state.length() > 1) {
            std::cout << state.length() << std::endl;
            std::cout << "Error: el estado inicial debe ser un solo caracter, comprueba input.fa" << std::endl;
            return;
        }
        startingState_ = State(state, !kFinal);
}

