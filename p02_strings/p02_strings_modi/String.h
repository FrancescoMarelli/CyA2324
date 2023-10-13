// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Alfabetos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/09/2023
#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "Symbol.h"
#include "Alphabet.h"

#pragma once

const std::string kEpsilon = "&";

class String {
 private:
    std::vector<Symbol> string_;
    unsigned size_;

 public:
    explicit String(std::vector<Symbol> &string) : string_(string) { size_ = string.size(); }
    explicit String(const std::string &line);
    String(const String &string);
    String() {}
    ~String() {}

    std::vector<Symbol> getSymbol() { return string_; }
    const Symbol getSymbol(int i) const { return string_[i]; }
    void setSymbol(std::vector<Symbol> symbol);
    unsigned size() const { return string_.size(); }

    bool checkString(Alphabet alphabet);
    std::set<Symbol> extractAlphabet();                //  opcode 1
    unsigned extractLength() const;                    //  opcode 2
    String inverse(String string, Alphabet alphabet);  //  opcode 3
    std::set<String> extractPrefixes();                //  opcode 4
    std::set<String> extractSuffixes();                //  opcode 5
    std::set<String> prefixSuffix();                   //  opcode 6

    friend std::ostream &operator<<(std::ostream &os, const String &string);
    void write(std::ostream& os) const;
    bool operator==(const String &other);
    bool operator<(const String &other) const;
    String operator+(const String &other) const;
};

