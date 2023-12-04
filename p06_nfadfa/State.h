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
#include <string>

#pragma once

class State {
 private:
    std::string label_;
    std::string type_;  // final or notfinal

 public:
    State(std::string&, const std::string&);
    explicit State(std::string& label) : label_(label) {}
    State() {}
    ~State() {}


    // Setters and getters
    void setLabel(std::string label) { label_ = label; }
    void setType(std::string type) { type_ = type; }
    std::string getLabel() const { return label_; }
    std::string getType() { return type_; }


    //  Overloaders
    bool operator==(const State& other) const;
    bool operator<(const State& other) const;
    bool operator!=(const State& other) const;

    friend std::istream &operator>>(std::istream &is, State &state);
    friend std::ostream &operator<<(std::ostream &os, const State &state);
};

