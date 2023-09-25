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
#include "../lib/fileManager.h"

#include <fstream>
#include <regex>


/**
 * @brief Construct a new File Manager:: File Manager object reading 
 * the students' grades from a file.
 * 
 * @return std::multimap<std::string, float> 
 */
std::multimap<std::string, float> FileManager::getStudents() {
    std::multimap<std::string, float> students;
    std::ifstream file(file_name_);
    std::string line;

    // Expresión regular para validar el formato del nombre del alumno
    std::regex namePattern("alu\\d{10}");

    if (!file.is_open()) {
        std::cout << "Error: No se pudo abrir el archivo " << file_name_ << std::endl;
        return students;  // Devuelve un map vacío en caso de error de apertura
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        float grade;

        if (!(iss >> name >> grade)) {
            std::cout << "Error: Línea inválida en el archivo: " << line << std::endl;
            continue;
        }

        if (std::regex_match(name, namePattern)) {
            if (grade >= 0 && grade <= 10) {
                students.insert(std::pair<std::string, float>(name, grade));
            } else {
                std::cout << "Error: " << name << " tiene un formato de nota incorrecta." << std::endl;
            }
        } else {
            std::cout << "Error: " << name << " tiene un formato de identificador de alumno incorrecto." << std::endl;
        }
    }
    file.close();
    return students;
}

