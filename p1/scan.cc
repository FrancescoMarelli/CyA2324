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
// Contiene la función scan del proyecto que lee por teclado
// las notas de los alumnos
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/09/2023 - Creación (primera versión) del código

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>

void scan(std::map<std::string, float> highestGrade) {
    bool exit = false;

    while (exit == false) {
        std::string name;
        std::cout << "Introduce el identificador del alumno: ";
        std::cin >> name;
        std::cout << "Introduce la nota del alumno  " << name << ": ";
        float grade;
        std::cin >> grade;
        if ((grade < 10) && (grade > 0)) {
            if (highestGrade.find(name) == highestGrade.end()) {
                    highestGrade[name] = grade;
            } else {
                if (highestGrade[name] < grade) {
                            highestGrade[name] = grade;
                }
            }
        } else {
            std::cerr << "Error: " << name << " tiene una nota no válida." << std::endl;
        }

        std::ofstream output("highest_grades.txt");
        for (auto it = highestGrade.begin(); it != highestGrade.end(); ++it) {
            output << it->first << " " << it->second << std::endl;
        }
        std::cout << "¿Quieres seguir introduciendo notas? (s/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n') {
            exit = true;
        }
        output.close();
    }
}

void scanall(std::multimap<std::string, float> allGrades) {
    bool exit = false;

    while (exit == false) {
        std::string name;
        std::cout << "Introduce el identificador del alumno: ";
        std::cin >> name;
        std::cout << "Introduce la nota del alumno  " << name << ": ";
        float grade;
        std::cin >> grade;
        if ((grade <= 10) && (grade >= 0)) {
            allGrades.insert(std::make_pair(name, grade));
        } else {
            std::cerr << "Error: " << name << " tiene una nota no válida." << std::endl;
        }

         std::ofstream output("all_grades.txt");
         for (auto it = allGrades.begin(); it != allGrades.end();) {
            output << it->first << ": ";

            std::ostringstream gradeList;
            gradeList << it->second;
            std::string currentName = it->first;
            ++it;

            while (it->first == currentName && it != allGrades.end()) {
                gradeList << " " << it->second;
                ++it;
            }
            output << gradeList.str() << std::endl;
        }
        output.close();


        // Preguntar si quiere seguir introduciendo notas
        std::cout << "¿Quieres seguir introduciendo notas? (s/n): ";
        char answer;
        std::cin >> answer;
        if (answer == 'n') {
            exit = true;
        }
    }
}
