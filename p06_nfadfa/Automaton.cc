// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include <string>
#include <sstream>
#include <iterator>
#include <stack>

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

Automaton::Automaton() {
    howManyStates_ = 0;
    alphabet_ = Alphabet();
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
    startingState_ = State(line);
}


/**
 * @brief read the states from the file
 * 
 * @param lines 
 */
void Automaton::statesReader(std::vector<std::string> lines) {
    startingState_.setType(std::string(1, lines[3][2]));
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
        State destState(getState(destLabel));
        if (getAlphabet().belongsToAlphabet(Symbol(symbol))) {
            Transition transition(state, Symbol(symbol), destState);
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
 * @param transition 
 */
void Automaton::addTransition(Transition transition) {
    transition_.insert(transition);
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
    if (stateSet_.size() != getSize()) {
        std::cout << "STATE_ERROR: el numero de estados definidos no coincide, comprueba input.fa" << std::endl;
        exit(1);
    }
    stateSet_.insert(state);
    howManyStates_ = getSize();
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
                    nextStatesSet.insert(transition.getStateDestiny());
                    std::set<State> transitionStates = eClosure(transition.getStateDestiny());
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


/**
 * @brief Creates a newState searching in the DFA map if already is in the dfa state
 * 
 * @param states 
 * @param dfaStates 
 * @param unprocessedStates 
 * @return State 
 */
State Automaton::createDFAState(const std::set<State>& states, std::map<std::set<State>, State>& dfaStates, std::queue<std::set<State>>& unprocessedStates) {  // NOLINT
    State newState;
    bool stateExists = false;
    for (const auto& dfaState : dfaStates) {
        if (dfaState.first == states) {
            newState = dfaState.second;
            stateExists = true;
            break;
        }
    }
    if (!stateExists) {
        std::string label;
        char letter = 'A' + dfaStates.size()-1;
        label = std::string(1, letter);
        newState = State(label);
        dfaStates[states] = newState;
        unprocessedStates.push(states);
    }
    return newState;
}


/**
 * @brief SubSet Construction method conevrt a NFA a DFA
 * 
 * @return Automaton 
 */
Automaton Automaton::SubSetConstruction() {
    Automaton dfa;
    std::set<State> initialStates = eClosure(startingState_);
    std::queue<std::set<State>> unprocessedStates;
    std::map<std::set<State>, State> dfaStates;  //  map to relate NFAStatesSet to DFAStates
    dfaStates[initialStates] = State(startingState_);
    unprocessedStates.push(initialStates);

    while (!unprocessedStates.empty()) {  // Loop until unprocessed states aint over
        std::set<State> currentStates = unprocessedStates.front();
        unprocessedStates.pop();
        State currentState = createDFAState(currentStates, dfaStates, unprocessedStates);  //  Creatint DFA States with condition  // NOLINT

        for (auto symbol : alphabet_.getAlphabet()) {
            std::set<State> nextStates;
            for (auto state : currentStates) {  //  For each State find where can go
                std::set<State> transitionStates = move(state, symbol);
                nextStates.insert(transitionStates.begin(), transitionStates.end());
            }

            if (!nextStates.empty()) {  //  if can go
                std::set<State> eClosureStates;
                for (auto nextState : nextStates) {
                    std::set<State> nextStateClosure = eClosure(nextState);  //  find eClosure
                    eClosureStates.insert(nextStateClosure.begin(), nextStateClosure.end());
                }
                State nextState = createDFAState(eClosureStates, dfaStates, unprocessedStates);  //  and create state
                Transition newTransition(currentState, symbol, nextState);
                dfa.addTransition(newTransition);  // and trans
            } else {  // if not do  -> deathstate
                std::string strD = "D";
                State deadState(strD);
                State nextState = createDFAState({deadState}, dfaStates, unprocessedStates);
                Transition newTransition(currentState, symbol, nextState);
                dfa.addTransition(newTransition);
            }
        }
    }

    // Seteo DFA
    dfa.setDFAProperties(dfaStates, initialStates, getAlphabet());
    return dfa;
}


/**
 * @brief 
 * 
 * @param dfaStates 
 * @param initialStates 
 * @param alphabet 
 */
void Automaton::setDFAProperties(std::map<std::set<State>, State>& dfaStates, const std::set<State>& initialStates, Alphabet alpha) {
    setDFAFinals(dfaStates);
    startingState_ = dfaStates[initialStates];
    this->setAlphabet(alpha);
    howManyStates_ = getSize();
}


/**
 * @brief 
 * 
 * @param dfaStates 
 */
void Automaton::setDFAFinals(const std::map<std::set<State>, State>& dfaStates) {
    for (const auto& dfaState : dfaStates) {
        State state = dfaState.second;
        bool isFinal = false;
        for (auto nfaState : dfaState.first) {
            if (nfaState.getType() == kFinal) {
                isFinal = true;
                break;
            }
        }
        if (isFinal) {
            state.setType(kFinal);
        } else {
            state.setType(kNotFinal);
        }
        addState(state);
    }
}


/**
 * @brief output method in default format 
 * 
 * @param file 
 */
void Automaton::outputDFA(std::ofstream& file) {
    file << alphabet_ << std::endl;
    file << howManyStates_ << std::endl;
    file << startingState_.getLabel() << std::endl;
    for (auto state : stateSet_) {
        file << state.getLabel() << " " << state.getType() << " ";
        int numTransitions = 0;
        for (auto transition : transition_) {
            if (transition.getStateOrigin() == state) {
                numTransitions++;
            }
        }
        file << numTransitions << " ";
        for (auto transition : transition_) {
            if (transition.getStateOrigin() == state) {
                file << transition.getSymbol().getSymbol() << " " << transition.getStateDestiny().getLabel() << " ";
            }
        }
        file << std::endl;
    }
}


/**
 * @brief 
 * 
 * @param state 
 * @return std::set<State> 
 */
std::set<State> Automaton::eClosure(const State& state) {
    std::set<State> closure;
    std::stack<State> stack;
    stack.push(state);
    while (!stack.empty()) {
        State current = stack.top();
        stack.pop();
        if (closure.count(current) > 0) {  // If the state is already in the closure, skip it.
            continue;
        }
        closure.insert(current);  // Add the state to the closure.
        for (auto transition : transition_) {
            State origin = transition.getStateOrigin();
            Symbol symb = transition.getSymbol();
            if (origin == current && symb.getSymbol() == kEpsilon) {
                stack.push(transition.getStateDestiny());
            }
        }
    }
    return closure;
}


/**
 * @brief 
 * 
 * @param state 
 * @param symbol 
 * @return std::set<State> 
 */
std::set<State> Automaton::move(const State& state, const Symbol& symbol) {
    std::set<State> nextStates;
    for (auto transition : transition_) {
        State origin = transition.getStateOrigin();
        Symbol symb = transition.getSymbol();
        State destiny = transition.getStateDestiny();
        if (origin.getLabel() == state.getLabel() && symb == symbol) {
            nextStates.insert(destiny);
        }
    }
    return nextStates;
}





