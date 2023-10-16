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
 * @brief Read Lines from the file
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
    const int kTransitionStart = 3;  // NOLINT
    std::vector<std::string> lines = getLines(file);
    readAlphabet(lines[0]);
    readStatesCount(lines[1]);
    readStartingState(lines[2]);
    readStates(lines);

    for (int i = kTransitionStart; i < lines.size(); i++)
        readTransition(lines[i]);
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
    startingState_ = State(line, kNotFinal);
}


/**
 * @brief read the states from the file
 * 
 * @param lines 
 */
void Automaton::readStates(std::vector<std::string> lines) {
    for (int i = 3; i < lines.size(); ++i) {
        if (lines[i] != "") {
            State state;
            state.setLabel(std::string(1, lines[i][0]));
            state.setType(std::string(1, lines[i][2]));
            stateSet_.insert(state);
        }
    }
}

/**
 * @brief Read the transitions from the file by line since column 3
 *         - The first column is the symbol
 *        - The second column is the destiny state
 * 
 * @param line 
 */
void Automaton::readTransition(std::string line) {
    line.erase(std::remove_if(line.end() - 1, line.end(), ::isspace), line.end());
    std::istringstream iss(line);
    std::string stateLabel;
    std::string type;
    int  numTransitions;
    iss >> stateLabel >> type >> numTransitions;
    State state(stateLabel, type);
    addStates(state);
    for (int j = 0; j < numTransitions; j++) {
        std::string symbol;
        std::string destLabel;
        iss >> symbol >> destLabel;
        State destState(getState(destLabel));
        if (alphabetOk(Symbol(symbol))) {
            Transition transition(Symbol(symbol), state, destState);
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
 * @param label 
 * @return State 
 */
State Automaton::getState(std::string label) {
    for (auto state : stateSet_) {
        if (state.getLabel() == label)
            return state;
    }
    return State();
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
 * @brief Iterate over the alphabet and check if the symbol belongs to it
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


/**
 * @brief 
 * 
 * @param fileStrings 
 */
void Automaton::elaborateStrings(std::ifstream& fileStrings) {
    std::vector<std::string> strings_stl = getLines(fileStrings);
    std::vector<String> string_vector = readStrings(strings_stl);
    checkStrings(string_vector);
}


/**
 * @brief 
 * 
 * @param string_vector 
 */
void Automaton::checkStrings(std::vector<String>& string_vector) {
    for (int i = 0; i < string_vector.size(); i++) {
        if (AutomatonCheck(string_vector[i])) {
            for (auto string : string_vector[i].getSymbol()) {
                std::cout << string;
            }
            std::cout << " --- Aceptada" << std::endl;
        } else {
            for (auto string : string_vector[i].getSymbol()) {
                std::cout << string;
            }
            std::cout << " --- Rechazada" << std::endl;
        }
    }
}


/**
 * @brief 
 * 
 * @param lines 
 * @return std::vector<String> 
 */
std::vector<String> Automaton::readStrings(std::vector<std::string>& lines) {
    std::vector<String> strings;
    const int kNumStrings = lines.size();
    for (int i = 0; i < kNumStrings; i++) {
        String str(lines[i]);
        strings.push_back(str);
    }
    return strings;
}


/**
 * @brief Non-deterministic finite automaton
 *        Checks if the string belongs to the language of the automaton
 *         - The string belongs to the language if the automaton accepts it
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool Automaton::AutomatonCheck(String& string) {
    if (!string.belongsToAlphabet(alphabet_)) {
        return false;
    }
    currentState_ = startingState_;
    std::set<State> current_set;
    current_set.insert(currentState_);

    for (auto symbol : string.getSymbol()) {
        std::set<State> next_states;
        for (auto state : current_set) {
            for (auto transition : transition_) {
                if (transition.getStateOrigin() == state && transition.getSymbol() == symbol) {
                    next_states.insert(transition.getStateDestiny());
                }
            }
        }
        current_set = next_states;
    }
    return isAccepted(current_set);
}


/**
 * @brief 
 * 
 * @param current_set 
 * @return true 
 * @return false 
 */
bool Automaton::isAccepted(std::set<State> current_set) {
    for (auto state : current_set) {
        if (state.getType() == kFinal) {
            return true;
        }
    }
    return false;
}




