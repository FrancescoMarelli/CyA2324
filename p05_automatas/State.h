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
#include <string>

#pragma once

class State {
 private:
    std::string label_;
    bool isFinal_;
    bool isStarting_;

 public:
    State(std::string&, bool&, bool&);
    State() {}
    ~State() {}

    void setLabel(std::string label) { label_ = label; }
    void setIsFinal(bool isFinal) { isFinal_ = isFinal; }
    void setIsStarting(bool isStarting) { isStarting_ = isStarting; }

    std::string getLabel() const { return label_; }
    bool getIsFinal() const { return isFinal_; }
    bool getIsStarting() const { return isStarting_; }
};

