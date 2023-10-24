// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/10/2023

#include <iostream>
#include <map>
#include "Symbol.h"
#include "State.h"

#pragma once

class Transition {
 private:
    State origin_;
    State destiny_;
    Symbol symbol_;


 public:
    Transition() {}
    Transition(State, Symbol, State);
    ~Transition() {}

    //  Setters and getters
    State getStateDestiny() const;
    Symbol getSymbol() const;
    State getStateOrigin() const;
    void setTransition(State, Symbol, State);


    // Overloaders
    bool operator<(const Transition& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);
};


