// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y Alfabetos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 22/09/2023
#include <iostream>
#include "Symbol.h"
#include "String.h"
#include "Alphabet.h"
#include "Language.h"

void Help();

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Modo de empleo: ./p02_strings filein.txt filoeout.txt opcode" << std::endl;
        std::cout << "'./p02_strings --help' para más información" << std::endl;
        return 1;
    }
    if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "--h") {
        Help();
    }

    int opcode = std::stoi(argv[3]);
    if (opcode < 1 || opcode > 5) {
        std::cout << "Error en el opcode, el rango es 1-5" << std::endl;
        return 1;
    }

    std::ifstream filein(argv[1]);

    if (!filein.is_open()) {
        std::cout << "Error al abrir el fichero de entrada" << std::endl;
        return 1;
    }

    std::ofstream fileout(argv[2]);

    if (!fileout.is_open()) {
        std::cout << "Error al abrir el fichero de salida" << std::endl;
        return 1;
    }

    const int kAlphabet = 1;
    const int kLength = 2;
    const int kInverse = 3;
    const int kPrefix = 4;
    const int kSuffix = 5;
    switch (opcode) {
        case kAlphabet: {
            std::string line;
            while (getline(filein, line)) {
                String string(line);
                Alphabet alphabet(string.extractAlphabet());
                alphabet.write(fileout);
            }
            break;
        }
        case kLength: {
            std::string line;
            while (getline(filein, line)) {
                String string(line);
                fileout << string.extractLength() << std::endl;
            }
            break;
        }
        case kInverse: {
            std::string line;
            while (getline(filein, line)) {
                String string(line);
                Alphabet alphabet(string.extractAlphabet());
                fileout << string.inverse(string, alphabet) << std::endl;
            }
            break;
        }
        case kPrefix: {
            std::string line;
            while (getline(filein, line)) {
                String string(line);
                Alphabet alphabet(string.extractAlphabet());
                std::set<String> prefixes = string.extractPrefixes();
                Language language(prefixes);
                language.write(fileout);
            }
            break;
        }
        case kSuffix: {
            std::string line;
            while (getline(filein, line)) {
                String string(line);
                Alphabet alphabet(string.extractAlphabet());
                std::set<String> suffixes = string.extractSuffixes();
                Language language(suffixes);
                language.write(fileout);
            }
            break;
        }
        break;
        default: {
            std::cout << "Error en el opcode" << std::endl;
            return 1;
        }
    }
    filein.close();
    fileout.close();
}

void Help() {
    std::cout << "---------------------------------------------------------------------" << std::endl;
    std::cout << "Este programa es un programa que opera sobre cadenas." << std::endl;
    std::cout << "Para ejecutar correctamente el programa pruebe el siguiente comando:" << std::endl;
    std::cout << "'./p02_strings filein.txt fileout.txt opcode'." << std::endl;
    std::cout << std::endl;
    std::cout << "De esta forma se elije cada operación que se desea realizar y los " << std::endl;
    std::cout << "ficheros de entrada y de salida de las operaciones." << std::endl;
    std::cout << std::endl;
    std::cout << "El formato de los ficheros de entrada va a ser: " << std::endl;
    std::cout << "abbbca" << std::endl;
    std::cout << "donde 'abbbca' es una cadena arbitraria de las que podremos calcularle:" << std::endl;
    std::cout << "1. Alfabeto" << std::endl;
    std::cout << "2. Longitud" << std::endl;
    std::cout << "3. Inversa" << std::endl;
    std::cout << "4. Prefijo" << std::endl;
    std::cout << "5. Sufijo" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
}
