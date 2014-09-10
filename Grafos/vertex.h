#ifndef VERTEX_H
#define VERTEX_H

#define INFINITO 10000

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
    Vertex *parent;
    int x;
    int y;

public:
    bool operator> (const Vertex &v) const;
    Vertex(int id, QString name, int x, int y);
    void add(int id1, int id2, int w);
    Edge *getEdge();
    QString getName() const;
    int getX();
    int getY();
    QColor getColor();
    void setColor(QColor color);
    void setParent(Vertex *v);
    Vertex *getParent();
    int getDistance();
    void setDistance(int distance);
    ~Vertex();
    int getEdgeNumber() const;
    void setEdgeNumber(int value);
};

#endif // VERTEX_H
