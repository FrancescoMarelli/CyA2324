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
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include <vector>

#include "Alphabet.h"
#include "Symbol.h"
#include "String.h"

class Grammar {
 private:
    Alphabet alphabet_;
    Alphabet nonTerminals_;
    Symbol startSymbol_;
    std::multimap<Symbol, String> productions_;

 public:
    Grammar() : alphabet_(), nonTerminals_() {}
    ~Grammar() {}
    void fileReader(std::ifstream&);
    void setAlphabet(Alphabet alphabet) { alphabet_ = alphabet ; }
    Alphabet getAlphabet() const { return alphabet_; }
    Alphabet getNonTerminals() const { return nonTerminals_; }

    std::vector<std::string> linesReader(std::ifstream&);
    void alphabetReader(std::vector<std::string>&);
    void nonTerminalReader(std::vector<std::string>&);
    void startNonTerminalReader(std::vector<std::string>&);
    void productionsReader(std::vector<std::string>&);
    void printGrammar(std::ofstream&);
    friend std::ostream &operator<<(std::ostream &os, const Grammar& grammar);
    void deleteEpsilonProductions();
    void deleteUnitProductions();
    void convertCNF();
    bool isNonTerminal(Symbol);
    Symbol generateNewNonTerminal();
    bool belongsToProductions(std::multimap<Symbol, String>, Symbol, String);
};
