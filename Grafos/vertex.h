#ifndef VERTEX_H
#define VERTEX_H

#include <QDebug>
#include <QColor>

#include "edge.h"

class Vertex
{
protected:
    int id; // Index do vétice no vetor
    QString name;
    int ti; // tempo de entrada
    int to; // tempo de saida
    int d;  // distância
    int n_a; // número de arestas
    QColor color; // cor do vértice
    Edge *edge;
    Vertex *father;
    int x;
    int y;

public:
    Vertex(int id, QString name, int x, int y);
    void add(int id1, int id2, int w);
    Edge *getEdge();
    QString getName();
    int getX();
    int getY();
    QColor getColor();
    void setColor(QColor color);
    void setFather(Vertex *v);
    int getD();
    void setD(int d);

    ~Vertex();
};

#endif // VERTEX_H
