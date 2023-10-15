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

const std::string kFinal = "1";  // NOLINT
const std::string kNotFinal = "0";  // NOLINT


/**
 * @brief Construct a new Automaton:: Automaton object
 * 
 * @param file 
 */
Automaton::Automaton(std::ifstream& file) {
    howManyStates_ = 0;
    buildAutomaton(file);
}


/**
 * @brief 
 * 
 * @param file 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Automaton::getLines(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        lines.push_back(line);
    return lines;
}


/**
 * @brief Builds the Automaton object
 * 
 * @param file 
 */
void Automaton::buildAutomaton(std::ifstream& file) {
    std::vector<std::string> lines = getLines(file);
    readAlphabet(lines[0]);
    readStatesCount(lines[1]);
    readStartingState(lines[2]);

    for (int i = 3; i < lines.size(); i++)
        readTransition(lines[i]);

    // check if the automaton transitions are correct
    for (auto transition : transition_) {
        std::cout << transition.getSymbol().getSymbol() << " " << transition.getStateOrigin().getLabel()
        << " " << transition.getStateDestiny().getLabel() << std::endl;
    }
}


/**
 * @brief Reads the alphabet from the file
 * 
 * @param line 
 */
void Automaton::readAlphabet(std::string line) {
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    for (int i = 0; i < line.size(); i++) {
        std::string symbol(1, line[i]);
        alphabet_.addSymbol(Symbol(symbol));
    }
}


/**
 * @brief reads the number of states from the file
 * 
 * @param line 
 */
void Automaton::readStatesCount(std::string line) {
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line.empty()) {
        std::cout << "EMPTY_ERROR: el numero de estados no puede estar vacio, comprueba input.fa" << std::endl;
        return;
    }
    if (!isdigit(line[0])) {
        std::cout << "STATES_COUNT_ERROR: el numero de estados debe ser un numero, comprueba input.fa" << std::endl;
        return;
    }
    howManyStates_ = std::stoi(line);
}


/**
 * @brief Reads the starting state from the file
 * 
 * @param line 
 */
void Automaton::readStartingState(std::string line) {
    // Check that the line contains at most one non-digit character
    int numNonDigits = std::count_if(line.begin(), line.end(), [](char c) { return !std::isdigit(c); });
    if (numNonDigits > 1) {
        std::cout << "STARTING_STATE_ERROR: La linea puede tener solo un estado de arranque (numerico)" << std::endl;
        return;
    }
    // Remove any whitespace characters from the line
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    startingState_ = State(line,  kNotFinal);
}


/**
 * @brief Reads the transitions from the file
 * 
 * @param line 
 */
void Automaton::readTransition(std::string line) {
    line.erase(std::remove_if(line.end() - 1, line.end(), ::isspace), line.end());
    std::istringstream iss(line);
    std::string stateLabel;
    std::string isFinal;
    int  numTransitions;
    iss >> stateLabel >> isFinal >> numTransitions;
    State state(stateLabel, isFinal);
    addStates(state);
    for (int j = 0; j < numTransitions; j++) {
        std::string symbol;
        std::string destLabel;
        iss >> symbol >> destLabel;
        if (alphabetOk(Symbol(symbol))) {
            Transition transition(Symbol(symbol), state, State(destLabel, isFinal));
            addTransition(transition);
        } else {
            std::cout << "TRANSITION_ERROR: el simbolo " << symbol << " o no pertenece al alfabeto "
                      << "o no hay transiciones suficiente  declaradas, comprueba input.fa" << std::endl;
            return;
        }
    }
}


/**
 * @brief 
 * 
 * @param state 
 */
void Automaton::addStates(State state) {
    if ((stateSet_.size() > howManyStates_)) {
        std::cout << "STATE_ERROR: el numero de estados definidos no coincide, comprueba input.fa" << std::endl;
        return;
    }
    stateSet_.insert(state);
}


/**
 * @brief 
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Automaton::alphabetOk(Symbol symbol) {
    std::set<Symbol> alphabet = alphabet_.getAlphabet();
    return alphabet.find(symbol) != alphabet.end() || symbol.getSymbol() == kEpsilon;
}


/**
 * @brief 
 * 
 * @param state 
 */
void Automaton::setStartingState(std::string state) {
    if (state.length() > 1) {
        std::cout << state.length() << std::endl;
        std::cout << "STARTING_STATE_ERROR: el estado inicial" <<
                     "debe ser un solo caracter, comprueba input.fa" << std::endl;
        return;
    }
    startingState_ = State(state, kNotFinal);
}

