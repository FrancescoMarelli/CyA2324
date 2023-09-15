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
#include <iostream>
#include <map>
#include <string>

#pragma once

class Students {
 private:
    std::multimap<std::string, float> students_;

 public:
    Students(std::multimap<std::string, float> students) {setStudents(students);}
    ~Students() {}

    std::multimap<std::string, float> getStudents() { return students_; }
    void setStudents(std::multimap<std::string, float> students) { students_ = students; }

    std::map<std::string, float> getHighGrades();
    std::multimap<std::string, float> getAllGrades();

    void addStudent(std::string name, float grade);
};
