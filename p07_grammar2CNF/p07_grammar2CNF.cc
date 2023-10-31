// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramaticas en forma normal de Chomsky
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 28/10/2023
#include <iostream>
#include <fstream>
#include <string>

#include "Grammar.h"

void Help();
void Usage();
int checkArguments(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    if (checkArguments(argc, argv) == 1)
        return 1;

    //  Comprobación de los ficheros de entrada
    std::ifstream fileCFG(argv[1]);
    std::ofstream fileOutput(argv[2]);

    if (!fileCFG.is_open()) {
        std::cout << "Error al abrir el fichero de entrada de la FCG " << std::endl;
        return 1;
    }
    if (!fileOutput.is_open()) {
        std::cout << "Error al abrir el fichero de salida de la CNF" << std::endl;
        return 1;
    }


    // Programa principal
    Grammar grammar;
    std::cout.setf(std::ios::unitbuf);
    grammar.fileReader(fileCFG);
    grammar.convertCNF();
    grammar.printGrammar(fileOutput);


    fileCFG.close();
    fileOutput.close();
    return 0;
}


/**
 * @brief 
 * 
 */
void Help() {
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
    std::cout << "      Práctica 7: Gramaticas en forma normal de Chomsky" << std::endl;
    std::cout << "      Este programa es un programa que opera sobre Gramatica Independientes del contexto." << std::endl;  // NOLINT
    std::cout << "      Para compilar el programa ejecute el siguiente comando:" << std::endl;
    std::cout << "      make" << std::endl;
    std::cout << "      Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "          Uso: './Grammar2CNF input.gra output.gra'." << std::endl;
    std::cout << "          Uso 2: make clean -> make run" << std::endl;
    std::cout << "          Uso 3: make execute" << std::endl;
    std::cout << std::endl;
    std::cout << "      El formato de los ficheros de entrada va a ser: " << std::endl;
    std::cout << "          - La primera linea va a ser el tamaño N del alphabeto de la gramatica." << std::endl;  // NOLINT
    std::cout << "          - La siguientes N lineas van a ser el alphabeto de la gramatica." << std::endl;  // NOLINT
    std::cout << "          - La siguiente linea va a ser el tamaño M del conjunto de no terminales." << std::endl;  // NOLINT
    std::cout << "          - Las siguientes M lineas van a ser el conjunto de no terminales." << std::endl;  // NOLINT
    std::cout << "          - La siguiente linea va a ser el simbolo inicial de la gramatica." << std::endl;  // NOLINT
    std::cout << "          - La siguiente linea va a ser el tamaño P del conjunto de producciones." << std::endl;  // NOLINT
    std::cout << "          - Las siguientes P lineas van a ser las producciones de la gramatica." << std::endl;  // NOLINT
    std::cout << "          - El formato de las producciones podrá ser: " << std::endl;
    std::cout << "             S A" << std::endl;  // NOLINT
    std::cout << "             S a" << std::endl;  // NOLINT
    std::cout << "             S AB" << std::endl;  // NOLINT
    std::cout << "             S aB" << std::endl;  // NOLINT
    std::cout << "            Se tendrá que especificar una produccion por linea." << std::endl;  // NOLINT
    std::cout << "      El formato de los ficheros de salida va a ser igual. " << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
}


/**
 * @brief 
 * 
 */
void Usage() {
    std::cout << "Modo de empleo: ./Grammar2CNF input.gra output.gra" << std::endl;
    std::cout << "'Pruebe 'Grammar2CNF --help' para más información." << std::endl;
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
