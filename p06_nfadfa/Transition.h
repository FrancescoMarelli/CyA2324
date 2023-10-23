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
#include <map>
#include "Symbol.h"
#include "State.h"

#pragma once

class Transition {
 private:
    std::map<std::pair<State, Symbol>, State> transition_;


 public:
    Transition() {}
    Transition(Symbol, State, State);
    ~Transition() {}

    //  Setters and getters
    State getStateDestiny(const State& origin, const Symbol& symbol) const;
    State getStateOrigin() const;
    Symbol getSymbol() const;
    std::map<std::pair<State, Symbol>, State> getTransition() const { return transition_; }  //  NOLINT
    void setTransition(Symbol, State, State);


    // Overloaders
    bool operator<(const Transition& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Transition &transition);
};


