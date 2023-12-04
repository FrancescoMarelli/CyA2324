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
#pragma once
#include <vector>
#include <iostream>

#include "subtree.hpp"
#include "point_types.hpp"

typedef std::vector<EMST::sub_tree> forest;

class point_set : public CyA::point_vector {
private:
    CyA::tree emst_;

public:
    point_set(void){}
    point_set(const CyA::point_vector &points);
    ~point_set(void){}

    void EMST(void);
    void add_edge(const CyA::point &p1, const CyA::point &p2);
    void write_tree(std::ostream &os) const;
    void write(std::ostream &os) const;

    inline const CyA::tree &get_tree(void) const { return emst_; }
    inline const CyA::point_vector &get_points(void) const { return *this; }
    inline const double get_cost(void) const { return compute_cost(); }

private:
    void compute_arc_vector(CyA::arc_vector &av) const;
    void find_incident_subtrees(const forest &st, const CyA::arc &a, int &i, int &j) const;
    void merge_subtrees(forest &st, const CyA::arc &a, int i, int j) const;

    double compute_cost(void) const;

    double euclidean_distance(const CyA::arc &a) const;
};