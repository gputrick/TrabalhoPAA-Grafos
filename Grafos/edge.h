#ifndef EDGE_H
#define EDGE_H

#include <QDebug>

class Edge
{
private:
    Edge *next;
    int coordX;
    int coordY;
    int weight;

public:
    Edge(int coordX, int coordY, int weight);
    static void append(Edge **edge, int coordX, int coordY, int weight);
    int getWeight();
    int getCoordX();
    int getCoordY();
    Edge *getNext();
    ~Edge();
};

#endif // EDGE_H
