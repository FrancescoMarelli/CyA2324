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
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

#pragma once

class FileManager {
    private:
        std::string file_name_;
        std::string output_file_name_;

    public:
        FileManager(std::string file_name) { setFileName(file_name); }
        ~FileManager() {}

        std::string getFileName() { return file_name_; }
        std::string getOutputFileName() { return output_file_name_; }
        void setFileName(std::string file_name) { file_name_ = file_name; }
        void setOutputFileName(std::string output_file_name) { output_file_name_ = output_file_name; }

        void writeStudents(std::map<std::string, float> students);

        std::multimap<std::string, float> getStudents();
};
