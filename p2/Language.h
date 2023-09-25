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
#include <set>

#include "String.h"

class Language {
    private:
     std::set<String> language_;

    public:
        Language(std::set<String> language) { setLanguage(language); }
        Language() {}
        ~Language(){}
    
        void setLanguage(std::set<String> language) { language_ = language; }
        std::set<String> getLanguage() const { return language_; }
        void addString(String string) { language_.insert(string); }
    
        bool operator=(const Language& other) const;
        void write(std::ostream &os) const;
};