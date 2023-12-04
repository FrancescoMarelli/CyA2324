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
#include "subtree.hpp"

#include <iomanip>
#include <cmath>

#include <algorithm>
#include <utility>

namespace EMST {
    /**
     * @brief Construct a new sub tree::sub tree object
     * 
     */
    sub_tree::sub_tree(void) : arcs_(),
                               points_(),
                               cost_(0){ }


    /**
     * @brief Destroy the sub tree::sub tree object
     * 
     */
    sub_tree::~sub_tree(void) {
        arcs_.clear();
        points_.clear();
    }


    /**
     * @brief Add an arc to the subtree
     * 
     * @param a 
     */
    void sub_tree::add_arc(const CyA::arc &a) {
        arcs_.push_back(a);
        points_.insert(a.first);
        points_.insert(a.second);
    }

    
    /**
     * @brief Add a point to the subtree
     * 
     * @param p 
     */
    void sub_tree::add_point(const CyA::point &p) {
        points_.insert(p);
    }


    /**
     * @brief  checks whether a point is in the subtree
     * 
     * @param p 
     * @return true 
     * @return false 
     */
    bool sub_tree::contains(const CyA::point &p) const {
        return points_.find(p) != points_.end();
    }


    /**
     * @brief merging two subtrees into one through an arc
     * 
     * @param st 
     * @param a 
     */
    void sub_tree::merge(const sub_tree &st, const CyA::weigthed_arc &a) {
        arcs_.insert(arcs_.end(), st.arcs_.begin(), st.arcs_.end());
        arcs_.push_back(a.second);

        points_.insert(st.points_.begin(), st.points_.end());

        cost_ += a.first + st.get_cost();
    }
}