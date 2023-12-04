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
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <queue>

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
std::vector<std::string> Automaton::linesReader(std::ifstream& file) {
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
    std::vector<std::string> lines = linesReader(file);
    alphabetReader(lines[0]);
    statesCounterReader(lines[1]);
    startingStateReader(lines[2]);
    statesReader(lines);

    for (int i = kTransitionStart; i < lines.size(); i++)
        transitionsReader(lines[i]);
}


/**
 * @brief Reads the alphabet from the file
 * 
 * @param line 
 */
void Automaton::alphabetReader(std::string line) {
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
void Automaton::statesCounterReader(std::string line) {
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line.empty()) {
        std::cout << "EMPTY_ERROR: el numero de estados no puede estar vacio, comprueba input.fa" << std::endl;
        exit(1);
    }
    if (!isdigit(line[0])) {
        std::cout << "STATES_COUNT_ERROR: el numero de estados debe ser un numero, comprueba input.fa" << std::endl;
        exit(1);
    }
    howManyStates_ = std::stoi(line);
}


/**
 * @brief Reads the starting state from the file
 * 
 * @param line 
 */
void Automaton::startingStateReader(std::string line) {
    // Check that the line contains at most one non-digit character
    int numNonDigits = std::count_if(line.begin(), line.end(), [](char c) { return !std::isdigit(c); });
    if (numNonDigits > 1) {
        std::cout << "STARTING_STATE_ERROR: La linea puede tener solo un estado de arranque (numerico)" << std::endl;
        exit(1);
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
void Automaton::statesReader(std::vector<std::string> lines) {
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
void Automaton::transitionsReader(std::string line) {
    line.erase(std::remove_if(line.end() - 1, line.end(), ::isspace), line.end());
    std::istringstream iss(line);
    std::string stateLabel;
    std::string type;
    int  numTransitions;
    iss >> stateLabel >> type >> numTransitions;
    State state(stateLabel, type);
    addState(state);
    for (int j = 0; j < numTransitions; j++) {
        std::string symbol;
        std::string destLabel;
        iss >> symbol >> destLabel;
        if (!isdigit(destLabel[0])) {
            std::cout << "TRANSITION_ERROR: el estado destino debe ser un numero, comprueba input.fa" << std::endl;
            exit(1);
        }
        int destStateIndex = std::stoi(destLabel);
        if (destStateIndex > howManyStates_-1) {
            std::cout << "TRANSITION_ERROR: el estado destino no puede ser mayor que el numero de estados, comprueba input.fa" << std::endl;  // NOLINT
            exit(1);
        }


        //  Aqui se añaden las transiciones si es que el simbolo pertenece al alfabeto
        State destState(getState(destLabel));
        if (getAlphabet().belongsToAlphabet(Symbol(symbol))) {
            Transition transition(Symbol(symbol), state, destState);
            addTransition(transition);
        } else {
            std::cout << "TRANSITION_ERROR: el simbolo " << symbol << " o no pertenece al alfabeto "
                      << "o no hay transiciones suficiente  declaradas, comprueba input.fa" << std::endl;
            exit(1);
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
void Automaton::addState(State state) {
    if ((stateSet_.size() > howManyStates_)) {
        std::cout << "STATE_ERROR: el numero de estados definidos no coincide, comprueba input.fa" << std::endl;
        exit(1);
    }
    stateSet_.insert(state);
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
        exit(1);
    }
    startingState_ = State(state, kNotFinal);
}


/**
 * @brief  Method that elaborates the strings on inputfile
 * 
 * @param fileStrings 
 */
void Automaton::elaborateStrings(std::ifstream& fileStrings) {
    std::vector<std::string> stringsStl = linesReader(fileStrings);
    std::vector<String> myStringVector = stringsReader(stringsStl);
    checkStrings(myStringVector);
}


/**
 * @brief Checks If Strings in Input are recognize or note from the FA
 * 
 * @param myStringsVector 
 */
void Automaton::checkStrings(std::vector<String>& myStringsVector) {
    for (int i = 0; i < myStringsVector.size(); i++) {
        bool stringValid = AutomatonStringsCheck(myStringsVector[i]);
        if (stringValid) {
            for (auto string : myStringsVector[i].getSymbol()) {
                std::cout << string;
            }
            std::cout << " --- Aceptada" << std::endl;
        } else {
            for (auto string : myStringsVector[i].getSymbol()) {
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
std::vector<String> Automaton::stringsReader(std::vector<std::string>& lines) {
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
bool Automaton::AutomatonStringsCheck(String& string) {
    if (!string.belongsToAlphabet(alphabet_)) {
        return false;
    }
    currentState_ = startingState_;
    std::set<State> currentStatesSet;
    currentStatesSet.insert(currentState_);

    for (auto symbol : string.getSymbol()) {
        std::set<State> nextStatesSet;
        for (auto state : currentStatesSet) {
            for (auto transition : transition_) {
                if (transition.getStateOrigin() == state && transition.getSymbol() == symbol) {
                    nextStatesSet.insert(transition.getStateDestiny(state, symbol));
                } else if (transition.getStateOrigin() == state && transition.getSymbol().getSymbol() == kEpsilon) {
                    nextStatesSet.insert(transition.getStateDestiny(state, symbol));
                    currentStatesSet.insert(transition.getStateDestiny(state, symbol));
                }
            }
        }
        currentStatesSet = nextStatesSet;
    }
    return isAccepted(currentStatesSet);
}


/**
 * @brief If the current States set contains a final state, the string is accepted
 * 
 * @param currentStatesSet 
 * @return true 
 * @return false 
 */
bool Automaton::isAccepted(std::set<State> currentStatesSet) {
    for (auto state : currentStatesSet) {
        if (state.getType() == kFinal) {
            return true;
        }
    }
    return false;
}


/**void Automaton::SubSetConstruction() {
    // Create a new initial state for the DFA that is the epsilon closure of the initial state of the NFA.
    std::set<State> initialStates = eClosure(startingState_);

    // Create a new set of states for the DFA that contains the initial state.
    std::set<std::set<State>> dfaStates;
    dfaStates.insert(initialStates);

    // Create a map to keep track of the transitions in the DFA.
    std::map<std::pair<std::set<State>, Symbol>, std::set<State>> dfaTransitions;

    // Create a queue to keep track of the sets of states that need to be processed.
    std::queue<std::set<State>> unprocessedStates;
    unprocessedStates.push(initialStates);

    // Process each set of states in the DFA.
    while (!unprocessedStates.empty()) {
        std::set<State> currentStates = unprocessedStates.front();
        unprocessedStates.pop();

        // For each symbol in the alphabet, compute the set of states that can be reached from the current set of states via that symbol and the epsilon closure of those states.
        for (auto symbol : alphabet_.getAlphabet()) {
            std::set<State> nextStates;
            for (auto state : currentStates) {
                for (auto transition : transition_) {
                    if (transition.getStateOrigin() == state && transition.getSymbol() == symbol) {
                        std::set<State> transitionStates = eClosure(transition.getStateDestiny());
                        nextStates.insert(transitionStates.begin(), transitionStates.end());
                    }
                }
            }

            // If the set of states computed above is not already in the set of states for the DFA, add it to the set of states and mark it as unprocessed.
            if (nextStates.size() > 0 && dfaStates.count(nextStates) == 0) {
                dfaStates.insert(nextStates);
                unprocessedStates.push(nextStates);
            }

            // Add a transition from the current set of states to the set of states computed above for the current symbol.
            if (nextStates.size() > 0) {
                dfaTransitions[std::make_pair(currentStates, symbol)] = nextStates;
            }
        }
    }

    // Create a new set of states for the DFA that contains all accepting states in the NFA.
    std::set<std::set<State>> dfaAcceptingStates;
    for (auto state : stateSet_) {
        if (state.getType() == kFinal) {
            std::set<State> closure = eClosure(state);
            if (dfaStates.count(closure) > 0) {
                dfaAcceptingStates.insert(closure);
            }
        }
    }

    // Create a new DFA using the computed states and transitions.
    //Automaton dfa(alphabet, dfaStates, initialStates, dfaAcceptingStates, dfaTransitions);
    // *this = dfa;
}

std::set<State> Automaton::eClosure(const State& state) {
    std::set<State> closure;
    std::stack<State> stack;
    stack.push(state);

    while (!stack.empty()) {
        State current = stack.top();
        stack.pop();

        if (closure.count(current) > 0) {
            continue;
        }

        closure.insert(current);

        for (auto transition : transition_) {
            if (transition.getStateOrigin() == current && transition.getSymbol().getSymbol() == kEpsilon) {
                stack.push(transition.getStateDestiny());
            }
        }
    }

    return closure;
}
**/



