// Copyright (C) 2023 Francesco Marelli
// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 11: Algoritmo de Kruskal
// Autor: Francesco Marelli
// Correo: alu0101161730@ull.edu.es
// Fecha: 04/12/2023
#include "point_types.hpp"

#include <iomanip>


/**
 * @brief 
 * 
 * @param os 
 * @param ps 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const CyA::point_vector& ps) {
    os << ps.size() << std::endl;

    for (const CyA::point &p : ps)
        os << p << std::endl;

    return os;
}


/**
 * @brief 
 * 
 * @param os 
 * @param p 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const CyA::point& p) {
    os << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.first << "\t" << std::setw(MAX_SZ) << std::fixed << std::setprecision(MAX_PREC) << p.second;

    return os;
}


/**
 * @brief 
 * 
 * @param is 
 * @param ps 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, CyA::point_vector& ps) {
    int n;
    is >> n;

    ps.clear();

    for (int i = 0; i < n; ++i) {
        CyA::point p;
        is >> p;

        ps.push_back(p);
    }

    return is;
}


/**
 * @brief 
 * 
 * @param is 
 * @param p 
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, CyA::point& p) {
    is >> p.first >> p.second;

    return is;
}


/**
 * @brief 
 * 
 * @param os 
 * @param t 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const CyA::tree& t) {
    for (const auto& arc : t) {
        os << "  " << arc.first << " -- " << arc.second << "\n";
    }
    return os;
}

/**
 * @brief 
 * 
 * @param os 
 * @param a 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const CyA::arc& a) {
    os << a.first << " -- " << a.second;
    return os;
}
