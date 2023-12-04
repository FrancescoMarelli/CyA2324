// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulador de máquina de TM
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 11/11/2023
#include "TM.h"
#include "State.h"
#include <cctype>
#include <sstream>

const int kNBlanks = 20;  // blanks on each side to print
const int kprinters = 44;  // blanks + spaces


/**
 * @brief 
 * 
 * @param file 
 */
void TM::tmFileReader(std::ifstream& file) {
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
std::vector<std::string> TM::linesReader(std::ifstream& file) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    if (lines.empty()) {
        std::cerr << "EMPTY_FILE: The configuration TM machine file is empty" << std::endl;
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
void TM::setStates(std::vector<std::string>& lines) {
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
void TM::setTransitions(std::vector<std::string>& lines) {
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
        // Remove spaces
        transitionStr.erase(std::remove_if(transitionStr.begin(), transitionStr.end(), ::isspace), transitionStr.end());
        // Read the transition
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
        // Set the transition
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
 * @param TM 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const TM& TM) {
    os << TM.nStates_ << std::endl;  // 1 Line
    os << TM.initialState_ << std::endl;  // 2 Line
    for (auto& state : TM.finalStates_) {  // 3 Line
        os << state << " ";
    }
    os << std::endl;
    os << TM.nTransitions_ << std::endl;  // 4 Line
    for (auto& transition : TM.transitions_) {  // 5 to N lines
        os << transition << std::endl;
    }
    return os;
}


/**
 * @brief Initializing tape
 * 
 * @param string 
 */
void TM::tapeReader(std::ifstream& tapeFile) {
    std::string line;
    bool firstLineRead = false;
    if (std::getline(tapeFile, line)) {
        // Add a blank symbol at the beginning
        tape_.push_back(blankSymbol_);
        // Add symbols from the line
        for (auto& symbol : line) {
            Symbol auxSym(std::string(1, symbol));
            tape_.push_back(auxSym);
        }
        // Add a blank symbol at the end
        tape_.push_back(blankSymbol_);
        firstLineRead = true;
    } else {
        // If the line is empty, add a blank symbol
        tape_.insert(tape_.begin(), blankSymbol_);
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
 * @param inputString 
 * @param mode If mode is 0 then the printout will show the state
 *              If mode is 1 then the printout will show the head
 * @return true 
 * @return false 
 */
bool TM::acceptString(std::vector<Symbol> const &inputString) {
    State currentState = initialState_;
    int head = 1;

    // Print initial tape
    printTape(currentState, head);
    //  Iterate over the transitions until a final state is reached or no transition is found
    while (true) {
        bool transitionFound = false;
        for (auto &transition : transitions_) {
            if (head >= 0 && head < tape_.size() &&  // Check if the head is in the tape and the transition is valid
                             transition.getStateOrigin() == currentState && transition.getToRead() == tape_[head]) {  // If the transition is valid
                tape_[head] = transition.getToWrite();  // Overwrite the tape and move or stay
                if (transition.getDirection() == "R") {
                    head++;
                    if (head == tape_.size()) {
                        tape_.push_back(blankSymbol_);  // If the head is at the end of the tape, add a blank symbol
                    }
                } else if (transition.getDirection() == "L") {
                    if (head == 0) {
                        tape_.insert(tape_.begin(), blankSymbol_);  // if head is at the beginning of the tape, add a blank symbol
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
 * @param symbol 
 * @param color 
 */
void TM::printSymbol(const Symbol& symbol, const std::string& color) {
    std::cout << color << symbol << "\033[0m";
}


/**
 * @brief 
 * 
 * @param currentState 
 * @param head 
 */
void TM::printTape(State& currentState, int head) {
    std::string lightGray = "\033[2;37m";
    std::string boldWhite = "\033[1;37;40m";
    std::string blue = "\033[1;34m";

    // Fill the tape with blank symbols
    std::cout << "|";
    for (int i = 0; i < kNBlanks; i++)
        printSymbol(blankSymbol_, lightGray);

    for (int i = 0; i < tape_.size(); i++) {
        std::string color = (tape_[i] == blankSymbol_) ? lightGray : boldWhite;
        if (i == head) {
            if (printMode == kState) {  // printing state before head
                std::cout << blue << " q" << currentState << " ";
            } else {  // head position is blue
                color = blue;
            }
        }
        printSymbol(tape_[i], color);
    }

    // Fill the tape with blank symbols
    for (int i = 0; i < kNBlanks; i++)
        printSymbol(blankSymbol_, lightGray);

    std::cout << "|";
    std::cout << std::endl;
}


/**
 * @brief  Output Result method for the TM machine
 *         that calls acceptString() and prints the result
 * 
 */
void TM::processString() {
    std::string title = "TM Machine Trace";
    int titleLength = title.length();
    std::string lineTitle;
    std::string line;
    // Adjust table size depending on execution mode
    if (printMode == kState) {
        lineTitle = std::string((getTape().size()+kprinters-titleLength) / 2, '-');
        line = std::string(getTape().size()+kprinters, '-');
    } else {
        lineTitle = std::string((getTape().size()+kprinters-4-titleLength) / 2, '-');
        line = std::string(getTape().size()+kprinters-4, '-');
    }
    std::cout << "\033[1;39m " << lineTitle << title << lineTitle << "\033[0m\n";  // NOLINT
    if (acceptString(getTape())) {
        std::cout << "\033[1;39m " << line << "\033[0m\n";  // NOLINT
        std::cout << "  RESULT -----> "<< "\033[1;37;42m ACCEPTED string \033[0m\n";  // White text on green background
    } else {
        std::cout << "\033[1;39m " << line << "\033[0m\n";  // NOLINT
        std::cout << "  RESULT -----> " << "\033[1;37;41m REJECTED string \033[0m\n";  // White text on red background
    }
    std::cout << "\n";
}

