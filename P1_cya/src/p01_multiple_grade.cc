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
#include <iostream>

#include "../lib/fileManager.h"
#include "../lib/students.h"

void Help();
void print(std::multimap<std::string, float> allGrades);
void interactive(Students students);

int main(int argc, char* argv[]) {

    if(argc != 2) {
        std::cout << "Error: ./p01_single_grade grades.txt" << std::endl;
        return 1;
    }
    if(std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        Help();
        return 1;
    }

    FileManager file(argv[1]);
    std::multimap<std::string, float> rawStudents = file.getStudents();
    Students students(rawStudents);
    print(students.getStudents());
    interactive(students);
}

void Help() {
        std::cout << "Este programa calcula la nota más alta de cada alumno." << std::endl;
        std::cout << "El fichero de entrada debe tener el siguiente formato:" << std::endl;
        std::cout << "Identificador Nota :" << std::endl;
        std::cout << "alu0101xxxxx 9.5" << std::endl;
        std::cout << std::endl;

        std::cout << "Uso: ./p01_single_grades <grades.txt>" << std::endl;
        std::cout << "Donde <grades.txt> es el fichero de entrada." << std::endl;
        std::cout << std::endl;
}

void print(std::multimap<std::string, float> allGrades) {
    for (auto it = allGrades.begin(); it != allGrades.end();) {
        std::string currentName = it->first;
        std::cout << currentName << ": ";

        while (it != allGrades.end() && it->first == currentName) {
            float grade = it->second;
            std::cout << grade << " ";
            ++it;
        }
        std::cout << std::endl;
    }
}

void interactive(Students students) {
    std::string answ = "si";
    
    while (answ == "si" || answ == "Si" || answ == "SI" || answ == "sI") {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Desea introducir una nueva nota? (s/n): ";
        std::string answer;
        std::cin >> answer;
        if(answer == "s") {
            std::cout << "Introduzca el nombre del alumno: ";
            std::string name;
            std::cin >> name;
            std::cout << "Introduzca la nota del alumno: ";
            float grade;
            std::cin >> grade;
            students.addStudent(name, grade);
            print(students.getAllGrades());
        } else {
            answ = "no";
        }
    }
    
}








