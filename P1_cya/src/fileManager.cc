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
#include "../lib/fileManager.h"

#include <fstream>

std::multimap<std::string, float> FileManager::getStudents() {
    std::multimap<std::string, float> students;
    std::ifstream file(file_name_);
    std::string name;
    float grade;

    if (file.is_open()){
        while(file >> name >> grade) {
            if(grade <= 10 && grade >= 0) {
                students.insert(std::pair<std::string, float>(name, grade));
            } else {
                std::cout << "Error: " << name << " tiene una nota incorrecta." << std::endl;
            }
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
    return students;
}
