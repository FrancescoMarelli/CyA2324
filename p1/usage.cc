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
// Contiene la función Usage del proyecto que describe el uso del programa.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 13/09/2023 - Creación (primera versión) del código
#include <iostream>

void Usage(){
    std::cout << "Este programa calcula la nota más alta de cada alumno." << std::endl;
    std::cout << "El fichero de entrada debe tener el siguiente formato:" << std::endl;
    std::cout << "Identificador Nota :" << std::endl; 
    std::cout << "alu010117272 9.5" << std::endl;
    std::cout << std::endl;

    std::cout << "Uso: ./p01_single_grades <grades.txt>" << std::endl;
    std::cout << "Donde <grades.txt> es el fichero de entrada." << std::endl;
    std::cout << std::endl;

}
