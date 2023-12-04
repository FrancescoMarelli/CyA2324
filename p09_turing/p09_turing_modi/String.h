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
    explicit String(const Symbol& symbol) : string_({symbol}) { size_ = 1; }
    String(const String &string);
    String() {}
    ~String() {}

    void addSymbol(Symbol symbol) { string_.push_back(symbol); }
    std::vector<Symbol> getSymbol() { return string_; }
    const Symbol getSymbol(int i) const { return string_[i]; }
    void setSymbol(std::vector<Symbol> symbol);
    unsigned size() const { return string_.size(); }

    bool belongsToAlphabet(Alphabet alphabet);

    friend std::ostream &operator<<(std::ostream &os, const String &string);
    friend std::istream &operator>>(std::istream &is, String &string);
    void write(std::ostream& os) const;
    bool operator==(const String &other) const;
    bool operator<(const String &other) const;
    void replaceSymbol(int, Symbol);
    void eraseSymbol(int pos) { string_.erase(string_.begin() + pos); }
};
