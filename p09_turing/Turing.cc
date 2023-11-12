// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulador de máquina de Turing
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 11/11/2023
#include "Turing.h"
#include "State.h"
#include <cctype>
#include <sstream>

/**
 * @brief 
 * 
 * @param file 
 */
void Turing::tmFileReader(std::ifstream& file) {
    std::vector<std::string> lines = linesReader(file);
    setStates(lines);
    setTransitions(lines);
}


/**
 * @brief 
 * 
 * @param file 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Turing::linesReader(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    if (lines.empty()) {
        std::cerr << "EMPTY_FILE: The configuration turing machine file is empty" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        return lines;
    }
}

/**
 * @brief 
 * 
 * @param line 
 */
void Turing::setStates(std::vector<std::string>& lines) {
    lines[0].erase(std::remove_if(lines[0].begin(), lines[0].end(), ::isspace), lines[0].end());
    if (lines[0].empty()) {
        std::cout << "LINE 1 EMPTY: Check the .tm file" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!isdigit(lines[0][0])) {
        std::cout << "NONDIGIT: Check the .tm file in Line 0, number of states must be a digit" << std::endl;  // NOLINT Check if the line is a digit
        exit(EXIT_FAILURE);
    }
    // Set nStates
    std::string nStates = lines[0].substr(0, lines[0].find(" "));
    nStates_ = std::stoi(nStates);
    // Set start State
    lines[1].erase(std::remove_if(lines[1].begin(), lines[1].end(), ::isspace), lines[1].end());

    // Format checks
    if (lines[1].empty()) {
        std::cout << "LINE 2 EMPTY: Check the .tm file" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!isdigit(lines[1][0])) {
        std::cout << "NONDIGIT: Check the .tm file in Line 1 starting state must be a digit" << std::endl;  // NOLINT Check if the line is a digit
        exit(EXIT_FAILURE);
    }
    std::string startState = lines[1].substr(0, lines[1].find(" "));
    initialState_.setLabel(startState);

    // Set final States
    std::istringstream iss(lines[2]);
    std::string finalState;
    if (lines[2].empty()) {
        std::cout << "LINE 3 EMPTY: Check the .tm file" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!isdigit(lines[2][0])) {
        std::cout << "NONDIGIT: Check the .tm file in Line 2 final states must be a digit" << std::endl;  // NOLINT Check if the line is a digit
        exit(EXIT_FAILURE);
    }

    while (iss >> finalState) {
        State state(finalState, kFinal);
        finalStates_.insert(state);
    }
}

/**
 * @brief  Reading Transitions from file
 * 
 */
void Turing::setTransitions(std::vector<std::string>& lines) {
    if (lines[3].empty()) {
        std::cout << "LINE 4 EMPTY: Check the .tm file" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!isdigit(lines[3][0])) {
        std::cout << "NONDIGIT: Check the .tm file in Line 3 number of transitions must be a digit" << std::endl;  // NOLINT Check if the line is a digit
        exit(EXIT_FAILURE);
    }

    std::string auxTrans = lines[3];
    // Set nStates
    auxTrans.erase(std::remove_if(auxTrans.begin(), auxTrans.end(), ::isspace), auxTrans.end());
    std::string nTransitions = auxTrans.substr(0, auxTrans.find(" "));
    nTransitions_ = std::stoi(nTransitions);

    for (int i = 0; i < nTransitions_; ++i) {
        std::string transitionStr =  lines[4+i];
        std::istringstream iss(transitionStr);
        std::string originState, toReadSymbol, destinyState, toWriteSymbol, direction;
        transitionStr.erase(std::remove_if(transitionStr.begin(), transitionStr.end(), ::isspace), transitionStr.end());

        iss >> originState >> toReadSymbol >> toWriteSymbol >> direction >> destinyState;

        // Format checks
        if (transitionStr.size() > 5) {
            std::cout << "EXTRA FIELD: Check the .tm file in Line " << 5+i << std::endl;
            exit(EXIT_FAILURE);
        }
        if (originState.empty() || toReadSymbol.empty() || toWriteSymbol.empty() || direction.empty() || destinyState.empty()) {  // NOLINT
            std::cout << "EMPTY FIELD: Check the .tm file in Line " << 5+i << std::endl;
            exit(EXIT_FAILURE);
        }
        if (!isdigit(originState[0]) || !isdigit(destinyState[0])) {
            std::cout << "NONDIGIT: Check the .tm file in Line " << 5+i << " origin and destiny states must be a digit" << std::endl;  // NOLINT Check if the line is a digit
            exit(EXIT_FAILURE);
        }
        if (toReadSymbol != kBlank && toWriteSymbol != kBlank) {
            if (!std::all_of(toReadSymbol.begin(), toReadSymbol.end(), ::isalnum) ||
                !std::all_of(toWriteSymbol.begin(), toWriteSymbol.end(), ::isalnum)) {
                std::cout << "NONALNUM: Check the .tm file in Line " << 5+i << " to read and to write symbols must be alphanumeric" << std::endl;  //  NOLINT
                exit(EXIT_FAILURE);
            }
        }

        State origin(originState);
        Symbol toRead(toReadSymbol);
        State destiny(destinyState);
        Symbol toWrite(toWriteSymbol);
        std::string directionString(direction);

        Transition transition(origin, toRead, destiny, toWrite, directionString);
        transitions_.insert(transition);
    }
}


/**
 * @brief 
 * 
 * @param os 
 * @param turing 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Turing& turing) {
    os << turing.nStates_ << std::endl;
    os << turing.initialState_ << std::endl;
    for (auto& state : turing.finalStates_) {
        os << state << " ";
    }
    os << std::endl;
    os << turing.nTransitions_ << std::endl;
    for (auto& transition : turing.transitions_) {
        os << transition << std::endl;
    }
    return os;
}


/**
 * @brief Initializing tape
 * 
 * @param string 
 */
void Turing::tapeReader(std::ifstream& tapeFile) {
    std::string line;
    bool firstLineRead = false;
    if (std::getline(tapeFile, line)) {
        // Add a blank symbol at the beginning
        tape_.push_back(blankSymbol_);
        // Add symbols from the line
        for (auto& symbol : line) {
            std::string auxStr(1, symbol);
            Symbol auxSym(auxStr);
            tape_.push_back(auxSym);
        }
        // Add a blank symbol at the end
        tape_.push_back(blankSymbol_);
        firstLineRead = true;
    } else {
        // If the line is empty, add a blank symbol
        tape_.push_back(blankSymbol_);
        tape_.push_back(blankSymbol_);
    }
    // Check if more than one line has been read
    if (std::getline(tapeFile, line) && firstLineRead) {
        // Error: More than one line in the input file
        std::cerr << "TAPE_FILE_ERROR: More than one line in the .tape file." << std::endl;
        exit(EXIT_FAILURE);
    }
}


/**
 * @brief 
 * 
 * @param string 
 * @return true 
 * @return false 
 */
bool Turing::acceptString(std::vector<Symbol> const &inputString) {
    State currentState = initialState_;
    int head = 1;

    // Print initial tape
    printTape(currentState, head);

    while (true) {
        bool transitionFound = false;
        for (auto &transition : transitions_) {
            if (head >= 0 && head < tape_.size() &&  // Check if the head is in the tape and the transition is valid
                             transition.getStateOrigin() == currentState && transition.getToRead() == tape_[head]) {
                tape_[head] = transition.getToWrite();  // Overwrite the tape and move or stay
                if (transition.getDirection() == "R") {
                    head++;
                    if (head == tape_.size()) {
                        tape_.push_back(blankSymbol_);
                    }
                } else if (transition.getDirection() == "L") {
                    if (head == 0) {
                        tape_.insert(tape_.begin(), blankSymbol_);
                    } else {
                        head--;
                    }
                }
                currentState = transition.getStateDestiny();  // Update the state
                printTape(currentState, head);  // Print the tape
                transitionFound = true;
                break;
            }
        }

        // If no transition is found or the current state is final, stop
        if (!transitionFound || finalStates_.find(currentState) != finalStates_.end()) {
            break;
        }
    }
    // Check if the final state is in the set of final states
    return finalStates_.find(currentState) != finalStates_.end();
}


/**
 * @brief 
 * 
 * @param currentState 
 * @param head 
 */
void Turing::printTape(State& currentState, int head) {
    // Fill the tape with blank symbols
    for (int i = 0; i < 10; i++)
        std::cout << "\033[2m" << blankSymbol_ << "\033[0m";
    for (int i = 0; i < tape_.size(); i++) {
        if (i == head) {
            std::cout << "\033[1;32m q" << currentState << "\033[0m" << " ";
            if (tape_[i] != blankSymbol_) {
                std::cout << tape_[i];
            } else {
                std::cout << "\033[2m" << tape_[i] << "\033[0m";
            }
        } else {
            if (tape_[i] != blankSymbol_) {
                std::cout << tape_[i];
            } else {
                std::cout << "\033[2m" << tape_[i] << "\033[0m";
            }
        }
    }
    // Fill the tape with blank symbols
    for (int i = 0; i < 10; i++)
        std::cout << "\033[2m" << blankSymbol_ << "\033[0m";
    std::cout << std::endl;
}






/**
 * @brief 
 * 
 */
void Turing::processString() {
    std::cout << "Turing Machine Trace" << std::endl;
    if (acceptString(getTape()))
        std::cout << "\033[1;32m ACCEPTED string\033[0m\n";
    else
        std::cout << "\033[1;31m REJECTED string\033[0m\n";
}


