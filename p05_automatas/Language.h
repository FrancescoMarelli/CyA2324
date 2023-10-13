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
#pragma once

#include <iostream>
#include <set>

#include "String.h"

class Language {
 private:
    std::set<String> language_;

 public:
    explicit Language(std::set<String> language);
    ~Language() {}
    std::set<String> getLanguage() const { return language_;}

    friend std::ostream &operator<<(std::ostream &os, const Language &language);
    void write(std::ostream& os) const;
};
