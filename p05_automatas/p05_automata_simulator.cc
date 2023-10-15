// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Automatas
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 12/10/2023
#include <iostream>
#include "Automaton.h"
#include "Language.h"

void Help();

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Modo de empleo: ./p05_automata_simulation input.dfa input.txt" << std::endl;
        std::cout << "'./p05_automata_simulation --help' para más información" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "--h") {
        Help();
        return 0;
    }


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
    std::ofstream fileout("output.txt");
    if (!fileout.is_open()) {
        std::cout << "Error al abrir el fichero de salida" << std::endl;
        return 1;
    }
    Automaton automaton(fileFa);
   // automaton.checkString(fileStrings, fileout);

    fileFa.close();
    fileStrings.close();
    fileout.close();


    return 0;
}



/**
 * @brief 
 * 
 */
void Help() {
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Este programa es un programa que opera sobre automatas finitos." << std::endl;
    std::cout << "Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "'./p05_automata_simulation input.nfa input.txt'." << std::endl;
    std::cout << std::endl;
    std::cout << "De esta forma se elije cada operación que se desea realizar y los " << std::endl;
    std::cout << "ficheros de entrada sobre que operar" << std::endl;
    std::cout << std::endl;
    std::cout << "El formato de los ficheros de entrada va a ser: " << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}


