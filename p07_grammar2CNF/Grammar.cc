// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/2023

#include <utility>
#include "Grammar.h"


/**
 * @brief 
 * 
 * @param file 
 */
void Grammar::fileReader(std::ifstream& file) {
    std::vector<std::string> lines = linesReader(file);
    alphabetReader(lines);  // Compruebo que el alfabeto es correcto
    nonTerminalReader(lines);  // Compruebo que los simbolos no terminales son correctos
    startNonTerminalReader(lines);  // Compruebo que el simbolo inicial es correcto
    productionsReader(lines);  // Falta comprobar que la parte derecha de las producciones es correcta
}


/**
 * @brief 
 * 
 * @param fileIn 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Grammar::linesReader(std::ifstream& fileIn) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(fileIn, line)) {
        lines.push_back(line);
    }
    return lines;
}


/**
 * @brief  Read the alphabet from the file 
 * 
 * @param lines 
 */
void Grammar::alphabetReader(std::vector<std::string>& lines) {
    lines[0].erase(std::remove_if(lines[0].begin(), lines[0].end(), ::isspace), lines[0].end());
    if (lines[0].empty()) {
        std::cout << "EMPTY_ALPHABET_ERROR: La linea del tamaño del alfabeto está vacía, comprueba input.gra" << std::endl;  // NOLINT
        exit(1);
    }
    if (!isdigit(lines[0][0])) {
        std::cout << "ALPHABET_DIGIT_ERROR: El alfabeto tiene que tener un tamaño numerico superior a 0, comprueba input.gra" << std::endl;  // NOLINT
        exit(1);
    }
    int alphabetSize = std::stoi(lines[0]);
    for (int i = 1; i <= alphabetSize; i++) {
        lines[i].erase(std::remove_if(lines[i].begin(), lines[i].end(), ::isspace), lines[i].end());
        alphabet_.addSymbol(Symbol(lines[i]));
    }
}


/**
 * @brief 
 * 
 * @param lines 
 */
void Grammar::nonTerminalReader(std::vector<std::string>& lines) {
    std::string line = lines[alphabet_.getAlphabet().size() + 1];
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    int nonTerminalSize = std::stoi(lines[alphabet_.getAlphabet().size() + 1]);
    int nonTerminalStart = alphabet_.getAlphabet().size() + 2;
    int nonTerminalEnd = nonTerminalStart + nonTerminalSize;
    for (int i = nonTerminalStart; i < nonTerminalEnd; i++) {
        if (lines[i].empty()) {
            std::cout << "EMPTY_NON_TERMINAL_ERROR: La linea del conjunto de no terminales está vacía, comprueba input.gra" << std::endl;  // NOLINT
            exit(1);
        }
        if (!isNonTerminal(Symbol(lines[i]))) {
            std::cout << "NON_TERMINAL_ERROR: El conjunto de no terminales no es correcto."
                        "Tienen que ser letras mayusculas, comprueba input.gra" << std::endl;  // NOLINT
            exit(1);
        }
        nonTerminals_.addSymbol(Symbol(lines[i]));
    }
}

/**
 * @brief 
 * 
 * @param lines 
 */
void Grammar::startNonTerminalReader(std::vector<std::string>& lines) {
    std::string line = lines[alphabet_.getAlphabet().size() + 2];
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    if (line.empty()) {
        std::cout << "EMPTY_START_SYMBOL_ERROR: La linea del simbolo inicial está vacía, comprubea input.gra" << std::endl;  // NOLINT
        exit(1);
    }
    if (!isNonTerminal(Symbol(line))) {
        std::cout << "START_SYMBOL_ERROR: El simbolo inicial no es un simbolo no terminal."
                      "Se recomienda llamarlo con una letra mayuscula, generalmente 'S', comprueba input.gra" << std::endl;  // NOLINT
        exit(1);
    }
    startSymbol_ = Symbol(line);
}



/**
 * @brief 
 * 
 * @param lines 
 */
void Grammar::productionsReader(std::vector<std::string>& lines) {
    std::string line = lines[alphabet_.getAlphabet().size() + nonTerminals_.getAlphabet().size() + 2];
    line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
    int alphabetSize = std::stoi(lines[0]);
    int nonTerminalSize = std::stoi(lines[alphabetSize + 1]);

    // Set Productions
    int productionsSize = std::stoi(lines[alphabetSize + nonTerminalSize + 2]);
    int productionsStart = alphabetSize + nonTerminalSize + 3;
    int productionsEnd = productionsStart + productionsSize;

    for (int i = productionsStart; i < productionsEnd; i++) {
        std::string left = lines[i].substr(0, 1);
        if (!isNonTerminal(Symbol(left))) {
            std::cout << "PRODUCTION_LEFT_ERROR: El simbolo de la izquierda de la produccion no es un simbolo no terminal. " // NOLINT
                        "Tienen que ser letras mayusculas, comprueba input.gra" << std::endl;  // NOLINT
            exit(1);
        }
        Symbol symbolLeft(left);
        std::string right = lines[i].substr(2, lines[i].size() - 2);

        if (right.empty()) {
            std::cout << "EMPTY_PRODUCTION_ERROR: La linea de la produccion está vacía, comprueba input.gra" << std::endl;  // NOLINT
            exit(1);
        }
        right.erase(std::remove(right.begin(), right.end(), '\r'), right.end());  // Delete carriage return
        right.erase(std::remove(right.begin(), right.end(), '\n'), right.end());  // Delete new line
        String stringRight(right);

        // Falta Comprobar si simbolo de alfabeto o de no terminales
        productions_.insert(std::pair<Symbol, String>(symbolLeft, stringRight));
    }
}


/**
 * @brief 
 * 
 * @param fileOut 
 */
void Grammar::printGrammar(std::ofstream& fileOut) {
    fileOut << alphabet_.getAlphabet().size() << std::endl;
    fileOut << alphabet_ << std::endl;
    fileOut << nonTerminals_.getAlphabet().size() << std::endl;
    fileOut << nonTerminals_ << std::endl;
    fileOut << productions_.size() << std::endl;
    for (auto it = productions_.begin(); it != productions_.end(); it++) {
        fileOut << it->first << " " << it->second << std::endl;
    }
}


/**
 * @brief 
 * 
 */
void Grammar::convertCNF() {
    deleteEpsilonProductions();
    deleteUnitProductions();
}


/**
 * @brief Necessitary to delete epsilon productions to apply the algorithm
 * 
 */
void Grammar::deleteEpsilonProductions() {
    std::multimap<Symbol, String> productions = productions_;
    // eliminar producciones vacias
    for (auto it = productions.begin(); it != productions.end();) {
        if ((it->first != startSymbol_) && (it->second.getSymbol()[0] == Symbol(kEpsilon))) {
            it = productions.erase(it);
        } else {
            ++it;
        }
    }
    productions_ = productions;
}


/**
 * @brief Necessary to delete unit productions to apply the algorithm
 * 
 */
void Grammar::deleteUnitProductions() {
    std::multimap<Symbol, String> productions = productions_;
    bool changed = true;
    while (changed) {
        changed = false;
        for (auto it = productions.begin(); it != productions.end();) {
            const String& rightSide = it->second;

            // Check for unit productions that produce another non-terminal.
            if ((rightSide.size() == 1) && (isNonTerminal(rightSide.getSymbol(0)))) {
                it = productions.erase(it);
                changed = true;
            } else {
                ++it;
            }
        }
    }
    productions_ = productions;
}


/**
 * @brief Check if a symbol is a non-terminal symbol
 * 
 * @param symbol 
 * @return true 
 * @return false 
 */
bool Grammar::isNonTerminal(Symbol symbol) {
   return (nonTerminals_.getAlphabet().find(symbol) != nonTerminals_.getAlphabet().end() && std::isupper(symbol.getSymbol()[0]));  // NOLINT
}


