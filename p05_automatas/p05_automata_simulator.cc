// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 5: Implementación de un Automata finito
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include <iostream>
#include "Automaton.h"
#include "Language.h"

void Help();
void Usage();
int checkArguments(int argc, char* argv[]);
void simulateAutomaton(std::ifstream&, std::ifstream&);

int main(int argc, char* argv[]) {
    if (checkArguments(argc, argv) == 1)
        return 1;

    //  Comprobación de los ficheros de entrada
    std::ifstream fileFa(argv[1]);
    std::ifstream fileStrings(argv[2]);

    if (!fileFa.is_open()) {
        std::cout << "Error al abrir el fichero de entrada del automata " << std::endl;
        return 1;
    }
    if (!fileStrings.is_open()) {
        std::cout << "Error al abrir el fichero de entrada de las cadenas" << std::endl;
        return 1;
    }

    simulateAutomaton(fileFa, fileStrings);  //  Program runner

    fileFa.close();
    fileStrings.close();
    return 0;
}


/**
 * @brief 
 * 
 * @param fileFa 
 * @param fileStrings 
 */
void simulateAutomaton(std::ifstream& fileFa, std::ifstream& fileStrings) {
    Automaton automaton(fileFa);  // Build the automaton
    automaton.elaborateStrings(fileStrings);  // Elaborate the strings
}


/**
 * @brief 
 * 
 */
void Help() {
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
    std::cout << "      Práctica 5: Simulador de Automatas Finitos" << std::endl;
    std::cout << "      Este programa es un programa que opera sobre automatas finitos." << std::endl;
    std::cout << "      Para compilar el programa ejecute el siguiente comando:" << std::endl;
    std::cout << "      make" << std::endl;
    std::cout << "      Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "          Uso: './p05_automata_simulation input.nfa input.txt'." << std::endl;
    std::cout << "          Uso 2: make clean -> make run" << std::endl;
    std::cout << "          Uso 3: make execute" << std::endl;
    std::cout << std::endl;
    std::cout << "      El formato de los ficheros de entrada va a ser: " << std::endl;
    std::cout << "      El fichero de configuración del automata es un fichero con extensión .fa con la siguiente estructura:" << std::endl;  // NOLINT
    std::cout << "          1. La primera línea contiene el alfabeto de entrada del autómata." << std::endl;
    std::cout << "          2. La segunda línea contiene el número de estados del autómata." << std::endl;
    std::cout << "          3. La tercera línea contiene el estado inicial del autómata." << std::endl;
    std::cout << "          4. Las siguientes líneas contienen los estados del autómata y el típo en la primera y segunda columna." << std::endl;  // NOLINT
    std::cout << "             A seguir el numero de transicciones y  las transiciones del autómata." << std::endl;
    std::cout << "      El fichero de entrada de las cadenas es un fichero con extensión .txt con la siguiente estructura:" << std::endl;  // NOLINT
    std::cout << "          Cadena a evaluar" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
}


/**
 * @brief 
 * 
 */
void Usage() {
    std::cout << "Modo de empleo: ./p05_automata_simulation input.dfa input.txt" << std::endl;
    std::cout << "'./p05_automata_simulation --help' para más información" << std::endl;
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




