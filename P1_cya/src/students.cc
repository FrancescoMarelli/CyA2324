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
#include "../lib/students.h"

#include <regex>
#include <limits>

/**
 * @brief Filter the students' grades to get the highest grade of each student.
 * 
 * @return std::map<std::string, float> 
 */
std::map<std::string, float> Students::getHighGrades() {
    std::map<std::string, float> highGrades;
    std::string name;
    float grade;

    for (auto it = students_.begin(); it != students_.end(); it++) {
        name = it->first;
        grade = it->second;

        if (highGrades.find(name) == highGrades.end()) {
             highGrades.insert(std::pair<std::string, float>(name, grade));
        } else {
            if (grade > highGrades[name]) {
                highGrades[name] = grade;
            }
        }
    }
    return highGrades;
}

/**
 * @brief Filter the students' grades to get all the grades of each student.
 * 
 * @return std::multimap<std::string, float> 
 */
std::multimap<std::string, float> Students::getAllGrades() {
    std::multimap<std::string, float> allGrades;
    std::string name;
    float grade;

    for (auto it = students_.begin(); it != students_.end(); it++) {
        name = it->first;
        grade = it->second;
        allGrades.insert(std::pair<std::string, float>(name, grade));
    }

    return allGrades;
}

/**
 * @brief Add a student to the students' list interacting with the user.
 * 
 * @param name 
 * @param grade 
 */
void Students::addStudent(std::string name, float grade) {
    std::regex namePattern("alu\\d{10}");
    if (std::regex_match(name, namePattern)) {
        if (grade >= 0 && grade <= 10) {
            students_.insert(std::pair<std::string, float>(name, grade));
        } else {
            std::cout << "Error: " << name << " tiene una nota incorrecta." << std::endl;
        }
    } else {
        std::cout << "Error: " << name << " tiene un formato de identificador de alumno incorrecto." << std::endl;
    }
}



