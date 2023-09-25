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
#include <string>
#include <fstream>

#pragma once

class Symbol {
    private:
    std::string symbol_;

    public:
    Symbol(const std::string symbol) {setSymbol(symbol); }
    ~Symbol(){}

    void setSymbol(std::string symbol) {symbol_ = symbol;}
    std::string getSymbol() const { return symbol_; }

    friend std::ostream &operator<<(std::ostream &os, const Symbol &symbol);
    friend std::istream &operator>>(std::istream &is, const Symbol &symbol);

    bool operator==(const Symbol& other) const;
    bool operator!=(const Symbol& other) const;
    bool operator<(const Symbol& other) const;
};