// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un Automata finito
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023

#include <iostream>
#include "Symbol.h"
#include "State.h"

#pragma once

class Transition {
 private:
    Symbol symbol_;
    State stateOrigin_;
    State stateDestiny_;


 public:
    Transition() {}
    Transition(Symbol, State, State);
    ~Transition() {}

    //  Setters and getters
    Symbol getSymbol() const { return symbol_;}
    State getStateOrigin() const { return stateOrigin_;}
    State getStateDestiny() const { return stateDestiny_;}
    void setSymbol(Symbol symbol) { symbol_ = symbol;}
    void setStateOrigin(State stateOrigin) { stateOrigin_ = stateOrigin;}
    void setStateDestiny(State stateDestiny) { stateDestiny_ = stateDestiny;}
    void setTransition(Symbol, State, State);


    // Overloaders
    bool operator<(const Transition& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);
};


