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

#include "../lib/fileManager.h"
#include "../lib/students.h"

void Help();
void print(std::map<std::string, float> highGrades);
void interactive(Students students);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: ./p01_single_grade grades.txt" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        Help();
        return 1;
    }
    FileManager file(argv[1]);
    std::multimap<std::string, float> rawStudents = file.getStudents();
    Students students(rawStudents);
    std::map<std::string, float> highGradesOnly = students.getHighGrades();
    print(highGradesOnly);
    interactive(students);
}

/**
 * @brief Usage of the program.
 * 
 */
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

/**
 * @brief Print the students' grades.
 * 
 * @param highGrades 
 */
void print(std::map<std::string, float> highGrades) {
    for (auto it = highGrades.begin(); it != highGrades.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

/**
 * @brief Interactive mode.
 * 
 * @param students 
 */
void interactive(Students students) {
    std::string answ = "s";

    while (answ == "s" || answ == "S") {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Desea introducir una nueva nota? (s/n): ";
        std::string answer;
        std::cin >> answer;
        if (answer == "s") {
            std::cout << "Introduzca el nombre del alumno: ";
            std::string name;
            std::cin >> name;

            std::cout << "Introduzca la nota del alumno: ";
            std::string gradeStr; // Leemos la entrada como una cadena
            std::cin >> gradeStr;

            try {
                float grade = std::stof(gradeStr); // Intentamos convertir la cadena en un número de coma flotante
                students.addStudent(name, grade);
                print(students.getHighGrades());
            } catch (const std::invalid_argument&) {
                std::cout << "Error: No se proporcionó una nota numérica válida para " << name << "." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Error: La nota proporcionada para " << name << " está fuera de rango." << std::endl;
            }
        } else if (answer == "n" || answer == "N")  {
            break;
        } else {
            std::cout << "Error: respuesta no válida. s o n " << std::endl;
        }
    }
}


