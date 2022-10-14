#pragma once

struct Edge {
    int m_vertice;
    double m_value;
    Edge(int vertice, double value) {
        m_vertice = vertice;
        m_value = value;
    }
};