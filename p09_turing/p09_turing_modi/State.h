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
#include <string>

#pragma once

class State {
 private:
    std::string label_;

 public:
    explicit State(std::string& label) : label_(label) {}
    State() {}
    ~State() {}


    // Setters and getters
    void setLabel(std::string label) { label_ = label; }
    std::string getLabel() const { return label_; }


    //  Overloaders
    bool operator==(const State& other) const;
    bool operator<(const State& other) const;
    bool operator!=(const State& other) const;
    State& operator=(const State& other);

    friend std::istream &operator>>(std::istream &is, State &state);
    friend std::ostream &operator<<(std::ostream &os, const State &state);
};

