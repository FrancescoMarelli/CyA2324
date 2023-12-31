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

#include "TM.h"


void Help();
void Usage();
int checkArguments(int argc, char* argv[]);

int main(int argc, char* argv[]) {
    if (checkArguments(argc, argv) == 1)
        return 1;

    //  Check input Files
    std::ifstream fileTM(argv[1]);
    std::ifstream fileTape(argv[2]);
    std::string mode = (argc > 3 && argv[3]) ? argv[3] : "0";  // Default mode


    // Choose Execution mode
    if (mode == kHead) {
        mode = kHead;
    } else {
        mode = kState;
    }

    if (!fileTM.is_open()) {
        std::cout << "Turing Machine File Error opening file" << std::endl;
        return 1;
    }
    if (!fileTape.is_open()) {
        std::cout << "TapeFile Error opening file " << std::endl;
        return 1;
    }
    // Intance of Turing machine
    TM turingMachine(mode);
    turingMachine.tmFileReader(fileTM);  //  Reading the configuration file
    turingMachine.tapeReader(fileTape);  // Reading the string on the tape
    turingMachine.processString();   // starting the machine and processing

    fileTape.close();
    fileTM.close();
    return 0;
}


/**
 * @brief 
 * 
 */
void Help() {
        // Formato de texto consistente
    std::cout << std::endl;
    std::cout << "\033[1;34m---------------------------------------------------------------------------------------------------------------------------------\033[0m\n";  // NOLINT
    std::cout << "\033[1;34m                                Práctica 9: Simulador de máquinas de Turing\033[0m\n";
    std::cout << "\033[1;34m---------------------------------------------------------------------------------------------------------------------------------\033[0m\n";  // NOLINT
    std::cout << "          Este programa simula máquinas de Turing de una cinta y una pista ." << std::endl;
    std::cout << "          Se lee una cinta desde un fichero y se procesa con una máquina de Turing." << std::endl;  // NOLINT
    std::cout << "          La máquina de Turing se lee desde un fichero también." << std::endl;
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------\n";  // NOLINT
    std::cout << "          **Compilar:**\n"
              << "          Para compilar el programa ejecute el siguiente comando:" << std::endl;
    std::cout << "  \033[1;32m                     'make'\033[0m\n";
    std::cout << "          **Ejecutar:**\n"
              << "          Para ejecutar correctamente el programa estos son los comandos:" << std::endl;
    std::cout << "              Uso:\033[1;32m './p09_MT [fichero.tm] cinta.tape modo'.\033[0m\n";
    std::cout << "              El modo puede ser 1 o 0 o nada:\n"
              << "              * al no tecleear nada se ejecuta por defecto como predefinido por el profeor\n"
              << "              * 1 se resaltará la cabeza de la máquina\n"
              << "              * 0 el modo predefinido del profesor.\n";
    std::cout << "              Uso 2: \033[1;32m 'make clean' -> 'make run' \033[0m (ejecutará abnb.tm en modo predefinido)\n";  // NOLINT
    std::cout << "              Uso 3: \033[1;32m 'make run2' \033[0m(ejecutará abcc.tm en modo predefinido )\n";  // NOLINT
    std::cout << "              Uso 4: \033[1;32m 'make execute' o 'make exe' compilará y ejecutará\033[0m en modo predefinido\n";  // NOLINT
    std::cout << "              Uso 5: \033[1;32m 'make run_head' | 'run2_head' | 'pal_head' \033[0m para modo alternativo de ejecución\n";  //  NOLINT
    std::cout << "\n";
    std::cout << "---------------------------------------------------------------------------------------------------------------------------------\n";  // NOLINT
    std::cout << "          **Formato archivos:**\n";
    std::cout << "              1. **Fichero de la máquina de Turing:**\n"
              << "                  * La primera línea contendrá el número de estados de la máquina de Turing." << std::endl;  // NOLINT
    std::cout << "                  * La segunda línea contendrá el estado inicial de la máquina de Turing." << std::endl;  // NOLINT
    std::cout << "                  * La tercera línea contendrá los estados de aceptación de la máquina de Turing." << std::endl;  // NOLINT
    std::cout << "                  * La cuarta línea contendrá el numero de transiciones de la máquina de Turing." << std::endl;  // NOLINT
    std::cout << "                  * Las siguientes líneas contendrán las transiciones con el siguiente formato de la máquina de Turing." << std::endl;  // NOLINT
    std::cout << "                  * estado entrada escribe movimiento siguientestado." << std::endl;
    std::cout << "              2. **Fichero de la cinta va a ser:**\n"
              << "                  * Una unica linea que contiene la cadena a analizar." << std::endl;
    std::cout << "\033[1;31m---------------------------------------------------------------------------------------------------------------------------------\033[0m\n";  // NOLINT
    // Información adicional
  std::cout << "        \033[1;31m**Información adicional:**\n"
            << "         * El estado inicial de la máquina de Turing debe ser uno solo.\n"
            << "         * Los estados de aceptación son los estados en los que la máquina de Turing acepta la cadena.\n"  // NOLINT
            << "         * Los estados de rechazo son los estados en los que la máquina de Turing rechaza la cadena.\n"
            << "         * La máquina de Turing puede leer, escribir y mover la cabeza de lectura en una dirección.\n"
            << "         * La máquina de Turing termina cuando llega a un estado de aceptación o la cadena se termina de comprobar y no se acepta.\n"  // NOLINT
            << std::endl;
  std::cout << "\033[1;31m---------------------------------------------------------------------------------------------------------------------------------\033[0m\n";  // NOLINT  
}


/**
 * @brief 
 * 
 */
void Usage() {
    std::cout << "Usage: ./TM maquina.tm cinta.tape mode" << std::endl;
    std::cout << "'Try 'TM --help' for more info." << std::endl;
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
    } else if (argc > 4 || argc < 3) {
        Usage();
        return 1;
    }
    std::string arg1(argv[1]);
    std::string arg2(argv[2]);

    if (arg1.substr(arg1.find_last_of(".") + 1) != "tm" || arg2.substr(arg2.find_last_of(".") + 1) != "tape") {
        std::cerr << "EXTENSION ERROR: First file MUST have .tm extension and Second must have .tape extension." << std::endl;  // NOLINT
        return 1;
    }
    int mode = 0;
    if (argc == 4) {
        mode = std::stoi(argv[3]);
        if (mode != 0 && mode != 1) {
            std::cout << "MODE must be a 0 or a 1" << std::endl;
            return 1;
        }
    }
    return 0;
}
