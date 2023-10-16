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
#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "Symbol.h"
#include "Alphabet.h"

#pragma once

const std::string kEpsilon = "&";  // NOLINT

class Language;
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

    void addSymbol(Symbol symbol) { string_.push_back(symbol); }
    std::vector<Symbol> getSymbol() { return string_; }
    const Symbol getSymbol(int i) const { return string_[i]; }
    void setSymbol(std::vector<Symbol> symbol);
    unsigned size() const { return string_.size(); }

    Alphabet extractAlphabet();
    unsigned extractLength() const;
    String inverse(String string, Alphabet alphabet);
    Language extractPrefixes();
    Language extractSuffixes();
    bool belongsToAlphabet(Alphabet alphabet);

    friend std::ostream &operator<<(std::ostream &os, const String &string);
    void write(std::ostream& os) const;
    bool operator==(const String &other);
    bool operator<(const String &other) const;
};
