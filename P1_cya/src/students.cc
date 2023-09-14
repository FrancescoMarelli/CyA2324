// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 13/09/2023
// Archivo cya-P01-single-grades.cc: programa cliente.
// Contiene el main del programa
#include "../lib/students.h"


std::map<std::string, float> Students::getHighGrades() {
    std::map<std::string, float> highGrades;
    std::string name;
    float grade;

    for(auto it = students_.begin(); it != students_.end(); it++) {
        name = it->first;
        grade = it->second;

        if(highGrades.find(name) == highGrades.end()) {
            highGrades.insert(std::pair<std::string, float>(name, grade));
        } else {
            if(grade > highGrades[name]) {
                highGrades[name] = grade;
            }
        }
    }
    return highGrades;
}

std::multimap<std::string, float> Students::getAllGrades() {
    std::multimap<std::string, float> allGrades;
    std::string name;
    float grade;

    for(auto it = students_.begin(); it != students_.end(); it++) {
        name = it->first;
        grade = it->second;

        if(allGrades.find(name) == allGrades.end()) {
            allGrades.insert(std::pair<std::string, float>(name, grade));
        } else {
            allGrades.insert(std::pair<std::string, float>(name, grade));
        }
    }
    
    return allGrades;
}

void Students::addStudent(std::string name, float grade) {
    students_.insert(std::pair<std::string, float>(name, grade));
}

