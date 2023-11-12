// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Simulador de máquina de Turing
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 11/11/2023
#include <iostream>
#include <fstream>
#include <string>

#include "Turing.h"

void Help();
void Usage();
int checkArguments(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    if (checkArguments(argc, argv) == 1)
        return 1;

    //  Comprobación de los ficheros de entrada
    std::ifstream fileTM(argv[1]);
    std::ifstream fileTape(argv[2]);

    if (!fileTM.is_open()) {
        std::cout << "Error al abrir el fichero de entrada de la Máquina de Turing " << std::endl;
        return 1;
    }
    if (!fileTape.is_open()) {
        std::cout << "Error al abrir el fichero de entrada de la cinta " << std::endl;
        return 1;
    }


    // Programa principal
    Turing turingMachine;
    turingMachine.fileReader(fileTM);
    turingMachine.setTape(fileTape);
    if (turingMachine.acceptString(turingMachine.getTape()))
        std::cout << "Cadena ACEPTADA" << std::endl;
    else
        std::cout << "Cadena RECHAZADA" << std::endl;

    fileTape.close();
    fileTM.close();
    return 0;
}


/**
 * @brief 
 * 
 */
void Help() {
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
    std::cout << "      Práctica 9: Simulador de máquinas de Turing" << std::endl;
    std::cout << "      Este programa es un programa que opera sobre máquinas de Turing de 1 cinta." << std::endl;  // NOLINT
    std::cout << "      Para compilar el programa ejecute el siguiente comando:" << std::endl;
    std::cout << "      make" << std::endl;
    std::cout << "      Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "          Uso: './p09_mtmain maquina.tm cinta.tape'." << std::endl;
    std::cout << "          Uso 2: make clean -> make run" << std::endl;
    std::cout << "          Uso 3: make execute" << std::endl;
    std::cout << std::endl;
    std::cout << "      El formato de los ficheros de entrada va a ser: " << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
}


/**
 * @brief 
 * 
 */
void Usage() {
    std::cout << "Modo de empleo: ./TM maquina.tm cinta.tape" << std::endl;
    std::cout << "'Pruebe 'TM --help' para más información." << std::endl;
}


/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int checkArguments(int argc, char* argv[]) {
    if (argc == 1) {
        Usage();
        return 1;
    }
    if (std::string(argv[1]) == "--help"  || std::string(argv[1]) == "--h") {
        Help();
        return 1;
    } else if (argc != 3) {
        Usage();
        return 1;
    }
    return 0;
}
