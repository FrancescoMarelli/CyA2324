// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/2023
#pragma once

#include <iostream>

#include "String.h"
#include "Symbol.h"

class Production {
 private:
    Symbol left_;
    String right_;

 public:
    Production() : left_(), right_() {}
    Production(Symbol left, String right) : left_(left), right_(right) {}
    ~Production() {}

    void setLeft(Symbol left) { left_ = left; }
    void setRight(String right) { right_ = right; }
    Symbol getLeft() const { return left_; }
    String getRight() const { return right_; }

    bool operator==(const Production& production) const { return (left_ == production.left_) && (right_ == production.right_); }  // NOLINT
    bool operator<(const Production& production) const { return (left_ < production.left_) && (right_ < production.right_); }  // NOLINT
    friend std::ostream& operator<<(std::ostream& os, const Production& production);
};
