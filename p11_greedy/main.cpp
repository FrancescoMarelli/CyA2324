#include "point_types.hpp"
#include "subtree.hpp"
#include "point_set.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>  // Para usar la función system()

void printMenu() {
    std::cout << "Opciones:\n"
              << "1. Agregar arista (Formato: x1 y1 x2 y2)\n"
              << "2. Calcular el árbol de expansión mínima\n"
              << "3. Imprimir el coste del árbol de expansión mínima\n"
              << "4. Guardar el grafo en formato DOT (-d)\n"
              << "5. Generar PDF del grafo (-pdf)\n"
              << "6. Salir\n"
              << "Seleccione una opción: ";
}

int main(int argc, char *argv[]) {
    point_set ps;

    // Añade algunos puntos a ps
    ps.push_back(CyA::point(0, 0));
    ps.push_back(CyA::point(0, 1));
    ps.push_back(CyA::point(1, 0));
    ps.push_back(CyA::point(1, 1));

    int option;
    do {
        printMenu();
        std::cin >> option;

        switch (option) {
            case 1: {
                // Agregar arista
                double x1, y1, x2, y2;
                std::cout << "Ingrese las coordenadas de los puntos (x1 y1 x2 y2): ";
                std::cin >> x1 >> y1 >> x2 >> y2;
                ps.add_edge(CyA::point(x1, y1), CyA::point(x2, y2));
                break;
            }
            case 2:
                // Calcular el árbol de expansión mínima
                ps.EMST();
                std::cout << "Árbol de expansión mínima calculado.\n";
                break;
            case 3:
                // Imprimir el coste del árbol de expansión mínima
                std::cout << "Coste del árbol de expansión mínima: " << ps.get_cost() << std::endl;
                break;
            case 4: {
                // Guardar el grafo en formato DOT
                std::ofstream dotFile("graph.dot");
                ps.write_tree(dotFile);
                dotFile.close();
                std::cout << "Grafo guardado en formato DOT en 'graph.dot'\n";
                break;
            }
            case 5: {
                // Generar PDF del grafo
                int result = system("neato graph.dot -Tpdf -o salida.pdf");
                if (result == 0) {
                    std::cout << "PDF generado con éxito (ver 'salida.pdf')\n";
                } else {
                    std::cerr << "Error al generar el PDF\n";
                }
                break;
            }
            case 6:
                // Salir
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cerr << "Error: Opción no válida. Inténtelo de nuevo.\n";
        }

    } while (option != 6);

    return 0;
}
