// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 13/09/2023
// Archivo cya-P01-multiple-grades.cc: programa cliente.
// Contiene la función main del proyecto que lee un fichero de texto con las notas de los alumnos 
//y crea un fichero de texto con todas las notas formateadas
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/09/2023 - Creación (primera versión) del código
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
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

    std::multimap<std::string, float> allGrades; // Utilizamos multimap para permitir múltiples notas por alumno
    std::string name;
    float grade;

    // Abre el archivo para lectura
    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    while (file >> name >> grade) {
        if ((grade >= 0) && (grade <= 10)) { // Validar que la nota esté en el rango válido
            allGrades.insert(std::make_pair(name, grade)); // Almacenar todas las notas
        } else {
            std::cerr << "Error: " << name << " tiene una nota no válida." << std::endl;
        }
    }

    // Cierra el archivo
    file.close();

    // Imprime el resultado en un fichero nuevo con el siguiente formato : alu0101018: 8.4 3 4 
    std::ofstream output("all_grades.txt");
    for(auto it = allGrades.begin(); it != allGrades.end();) {
        output << it->first << ": ";

        std::ostringstream gradeList;
        gradeList << it->second;
        std::string currentName = it->first;
        ++it;

        while (it->first == currentName && it != allGrades.end()) {
            gradeList << " " << it->second;
            ++it;
        }
        output << gradeList.str() << std::endl;
    }
    output.close();

    // Escanea y muestra todas las notas para cada alumno
    scanall(allGrades);

    return 0;
}
