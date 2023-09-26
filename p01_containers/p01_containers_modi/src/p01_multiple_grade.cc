<<<<<<< HEAD:P1/src/p01_multiple_grade.cc
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
void print(std::multimap<std::string, float> allGrades);
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
    print(students.getAllGrades());
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
 * @param allGrades 
 */
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
            std::string gradeStr;  // Leemos la entrada como una cadena
            std::cin >> gradeStr;

            try {
                float grade = std::stof(gradeStr);  // Convertimos la cadena a float
                students.addStudent(name, grade);
                print(students.getAllGrades());
            } catch (const std::invalid_argument&) {
                std::cout << "Error: No se proporcionó una nota numérica válida para " << name << "." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Error: La nota proporcionada para " << name << " está fuera de rango." << std::endl;
            }
        } else if (answer == "n" || answer == "N") {
            break;
        } else {
            std::cout << "Error: respuesta no válida. s o n " << std::endl;
        }
    }
}








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

#include "../lib/fileManager.h"
#include "../lib/students.h"

void Help();
void print(std::multimap<std::string, float> allGrades);
void interactive(Students students);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Error: ./p01_multiple_grade grades.txt" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        Help();
        return 1;
    }


    // Si fichero no es de tipo txt
    if (std::string(argv[1]).substr(std::string(argv[1]).find_last_of(".") + 1) != "txt") {
        std::cout << "Error: El fichero debe ser de tipo txt" << std::endl;
        return 1;
    }

    FileManager file(argv[1]);
    std::multimap<std::string, float> rawStudents = file.getStudents();
    Students students(rawStudents);
    print(students.getAllGrades());
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
    std::cout << "Uso: ./p01_multiple_grades grades.txt" << std::endl;
    std::cout << "Donde <grades.txt> es el fichero de entrada." << std::endl;
    std::cout << std::endl;
}

/**
 * @brief Print the students' grades.
 * 
 * @param allGrades 
 */
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
            std::string gradeStr;  // Leemos la entrada como una cadena
            std::cin >> gradeStr;

            try {
                float grade = std::stof(gradeStr);  // Convertimos la cadena a float
                students.addStudent(name, grade);
                print(students.getAllGrades());
            } catch (const std::invalid_argument&) {
                std::cout << "Error: No se proporcionó una nota numérica válida para " << name << "." << std::endl;
            } catch (const std::out_of_range&) {
                std::cout << "Error: La nota proporcionada para " << name << " está fuera de rango." << std::endl;
            }
        } else if (answer == "n" || answer == "N") {
            break;
        } else {
            std::cout << "Error: respuesta no válida. s o n " << std::endl;
        }
    }
}








>>>>>>> 03e6cd1b6dac70b8e1ebb843e50dfc6f5f1f2ec5:p01_containers/src/p01_multiple_grade.cc
