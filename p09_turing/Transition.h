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
#include <map>
#include "Symbol.h"
#include "State.h"

#pragma once

class Transition {
 private:
    State origin_;
    State destiny_;
    Symbol toRead_;
    Symbol toWrite_;
    std::string direction_;

 public:
    Transition() {}
    Transition(State, Symbol, State, Symbol, std::string);  // NOLINT
    ~Transition() {}

    //  Setters and getters
    State getStateDestiny() const;
    Symbol getToRead() const;
    State getStateOrigin() const;
    Symbol getToWrite() const;
    std::string getDirection() const;
    void setTransition(State, Symbol, State, Symbol, std::string); // NOLINT


    // Overloaders
    bool operator<(const Transition& other) const;
    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);
};


