<<<<<<< HEAD:P1/lib/students.h
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
#include <vector>
#include <algorithm>

#pragma once

class Students {
 private:
    std::multimap<std::string, float> students_;
    

 public:
    Students(std::multimap<std::string, float> students) { setStudents(students); }
    ~Students() {}

    std::multimap<std::string, float> getStudents() { return students_; }
    void setStudents(std::multimap<std::string, float> students) { students_ = students; }

    std::map<std::string, float> getHighGrades();

    std::multimap<std::string, float> getAllGrades();

    void addStudent(std::string name, float grade);
};
=======
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
    Students(std::multimap<std::string, float> students) { setStudents(students); }
    ~Students() {}

    std::multimap<std::string, float> getStudents() { return students_; }
    void setStudents(std::multimap<std::string, float> students) { students_ = students; }
   
    std::map<std::string, float> getHighGrades();  // Método para obtener la nota más alta de cada alumno
    std::multimap<std::string, float> getAllGrades();  // Método para obtener todas las notas de cada alumno

    void addStudent(std::string name, float grade);  // Método para añadir un alumno interactivamente
};
>>>>>>> 03e6cd1b6dac70b8e1ebb843e50dfc6f5f1f2ec5:p01_containers/lib/students.h
