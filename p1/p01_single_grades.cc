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
// Contiene la función main del proyecto que lee un fichero de texto con las notas de los alumnos 
//y crea un fichero de texto con las notas más altas de cada alumno.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/09/2023 - Creación (primera versión) del código

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "usage.cc"
#include "scan.cc"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <grades.txt>" << std::endl;
        return 1;
    }
    if(std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
        Usage();
    }

    std::map<std::string, float> highestGrade;
    std::string name;
    float grade;

    // Abre el archivo para lectura
    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    while (file >> name >> grade) {
        if((grade < 10) && (grade > 0)) {
            if(highestGrade.find(name) == highestGrade.end()) { 
                    highestGrade[name] = grade;
            } else { 
                if(highestGrade[name] < grade) { 
                            highestGrade[name] = grade; 
                }
            }
        } else {
            std::cerr << "Error: " << name << " tiene una nota no válida." << std::endl;
        }
    }

    // Cierra el archivo
    file.close();

   // Imprime el resultado en un fichero nuevo
    std::ofstream output("highest_grades.txt");
    for(auto it = highestGrade.begin(); it != highestGrade.end(); ++it) {
        output << it->first << " " << it->second << std::endl;
    }
    output.close();

    scan(highestGrade);

    return 0;
}
