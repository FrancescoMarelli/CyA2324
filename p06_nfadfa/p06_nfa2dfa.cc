// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Algoritmo de Construcción de Subconjuntos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/10/2023
#include <iostream>
#include "Automaton.h"

void Help();
void Usage();
int checkArguments(int argc, char* argv[]);
void convertNFA(std::ifstream&, std::ofstream&);

int main(int argc, char* argv[]) {
    if (checkArguments(argc, argv) == 1)
        return 1;

    //  Comprobación de los ficheros de entrada
    std::ifstream fileFa(argv[1]);
    std::ofstream fileOutput(argv[2]);

    if (!fileFa.is_open()) {
        std::cout << "Error al abrir el fichero de entrada del automata " << std::endl;
        return 1;
    }
    if (!fileOutput.is_open()) {
        std::cout << "Error al abrir el fichero de entrada de las cadenas" << std::endl;
        return 1;
    }

    convertNFA(fileFa, fileOutput);  //  Program runner

    fileFa.close();
    fileOutput.close();
    return 0;
}


/**
 * @brief 
 * 
 * @param fileFa 
 * @param fileStrings 
 */
void convertNFA(std::ifstream& fileFa, std::ofstream& dfaOutput) {
    Automaton automaton(fileFa);  // Build the automaton
    Automaton dfa = automaton.SubSetConstruction();  //  Build the automaton with the subset construction
    dfa.outputDFA(dfaOutput);
}


/**
 * @brief 
 * 
 */
void Help() {
    std::cout << "-----------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
    std::cout << "      Práctica 6: Conversión NFA a DFA" << std::endl;
    std::cout << "      Este programa es un programa que opera sobre automatas finitos." << std::endl;
    std::cout << "      Para compilar el programa ejecute el siguiente comando:" << std::endl;
    std::cout << "      make" << std::endl;
    std::cout << "      Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "          Uso: './NFA2DFA input.nfa ouptut.dfa'." << std::endl;
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
    std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;  // NOLINT
}


/**
 * @brief 
 * 
 */
void Usage() {
    std::cout << "Modo de empleo: ./NFA2DFA input.nfa output.dfa" << std::endl;
    std::cout << "'./NFA2DFA --help' para más información" << std::endl;
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




