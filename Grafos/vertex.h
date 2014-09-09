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
    int exitTime; // tempo de entrada
    int entranceTime; // tempo de saida
    int distance;  // distância
    int edgeNumber; // número de arestas
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
    int getDistance();
    void setDistance(int distance);

    ~Vertex();
};

#endif // VERTEX_H
