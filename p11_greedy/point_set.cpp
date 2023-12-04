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
#include "point_set.hpp"
#include <algorithm>

/**
 * @brief 
 * 
 */
void point_set::EMST(void) {
    CyA::arc_vector av;
    compute_arc_vector(av);

    forest st;

    for (const CyA::point &p : *this) {
        EMST::sub_tree s;
        s.add_point(p);

        st.push_back(s);
    }

    for (const CyA::weigthed_arc &a : av) {
        int i, j;
        find_incident_subtrees(st, a.second, i, j);

        if (i != j)
            merge_subtrees(st, a.second, i, j);
    }

    emst_ = st[0].get_arcs();
}


/**
 * @brief 
 * 
 * @param av 
 */
void point_set::compute_arc_vector(CyA::arc_vector &av) const {
        av.clear();
 
        const int n = size();
 
        for (int i = 0; i < n - 1; ++i) {
            const CyA::point &p_i = (*this)[i];
 
            for (int j = i + 1; j < n; ++j) {
                const CyA::point &p_j = (*this)[j];
 
                const double dist = euclidean_distance(std::make_pair(p_i, p_j));
 
                av.push_back(std::make_pair(dist, std::make_pair(p_i, p_j)));
            }
        }
 
        std::sort(av.begin(), av.end());
}

void point_set::find_incident_subtrees(const forest &st, const CyA::arc &a, int &i, int &j) const {
    i = j = -1;

    for (int k = 0; k < st.size(); ++k) {
        const EMST::sub_tree &s = st[k];

        if (s.contains(a.first))
            i = k;

        if (s.contains(a.second))
            j = k;
    }
}


/**
 * @brief 
 * 
 * @param st 
 * @param a 
 * @param i 
 * @param j 
 */
void point_set::merge_subtrees(forest &st, const CyA::arc &a, int i, int j) const {
    EMST::sub_tree &s_i = st[i];
    EMST::sub_tree &s_j = st[j];
    CyA::weigthed_arc wa = std::make_pair(euclidean_distance(a), a);
    s_i.merge(s_j, wa);

    st.erase(st.begin() + j);
}


/**
 * @brief 
 * 
 * @return double 
 */
double point_set::compute_cost(void) const {
    double cost = 0.0;

    for (const CyA::arc &a : emst_)
        cost += euclidean_distance(a);

    return cost;
}


/**
 * @brief 
 * 
 * @param a 
 * @return double 
 */
double point_set::euclidean_distance(const CyA::arc &a) const {
    const CyA::point &p_i = a.first;
    const CyA::point &p_j = a.second;

    const double dx = p_i.first - p_j.first;
    const double dy = p_i.second - p_j.second;

    return std::sqrt(dx * dx + dy * dy);
}


/**
 * @brief 
 * 
 * @param p1 
 * @param p2 
 */
void point_set::add_edge(const CyA::point &p1, const CyA::point &p2) {
    // Agrega la arista a la lista de puntos (aquí puedes ajustar según tu lógica)
    this->push_back(p1);
    this->push_back(p2);
}


/**
 * @brief 
 * 
 * @param os 
 */
void point_set::write_tree(std::ostream &os) const {
    os << "graph G {\n";
    
    // Escribir nodos con posiciones
    for (size_t i = 0; i < size(); ++i) {
        os << "  " << (*this)[i] << " [pos=\"" << (*this)[i].first << "," << (*this)[i].second << "!\"]\n";
    }

    // Escribir aristas
    for (size_t i = 0; i < emst_.size(); ++i) {
        os << "  " << emst_[i].first << " -- " << emst_[i].second << "\n";
    }

    os << "}\n";
}

