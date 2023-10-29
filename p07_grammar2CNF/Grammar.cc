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
    // Set Alphabet
    int alphabetSize = std::stoi(lines[0]);
    for (int i = 1; i <= alphabetSize; i++) {
        alphabet_.addSymbol(Symbol(lines[i]));
    }

    // Set NonTerminals
    int nonTerminalSize = std::stoi(lines[alphabetSize + 1]);
    int nonTerminalStart = alphabetSize + 2;
    int nonTerminalEnd = nonTerminalStart + nonTerminalSize;
    for (int i = nonTerminalStart; i < nonTerminalEnd; i++) {
        nonTerminals_.addSymbol(Symbol(lines[i]));
    }
    // Set Start Symbol as is the first one read but is an S
    startSymbol_ = Symbol(lines[nonTerminalStart]);

    // Set Productions
    int productionsSize = std::stoi(lines[alphabetSize + nonTerminalSize + 2]);
    int productionsStart = alphabetSize + nonTerminalSize + 3;
    int productionsEnd = productionsStart + productionsSize;

    for (int i = productionsStart; i < productionsEnd; i++) {
        std::string left = lines[i].substr(0, 1);
        Symbol symbolLeft(left);
        std::string right = lines[i].substr(2, lines[i].size() - 2);
        String symbolProd;
        for (int j = 0; j < right.size(); j++) {
            Symbol symbolRight(std::string(1, right[j]));
            symbolProd.addSymbol(symbolRight);
        }
        String stringRight(right);
        productions_.insert(std::pair<Symbol, String>(symbolLeft, stringRight));
    }
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

void Grammar::printGrammar(std::ofstream& fileOut) const {

    fileOut << alphabet_.getAlphabet().size() << std::endl;
    fileOut << alphabet_ << std::endl;
    fileOut << nonTerminals_.getAlphabet().size() << std::endl;
    fileOut << nonTerminals_ << std::endl;
    fileOut << startSymbol_ << std::endl;
    fileOut << productions_.size() << std::endl;
    for (auto it = productions_.begin(); it != productions_.end(); it++) {
        fileOut << it->first << " " << it->second << std::endl;
    }

}

