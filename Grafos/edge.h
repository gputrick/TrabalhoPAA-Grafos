#ifndef EDGE_H
#define EDGE_H

#include <QDebug>

class Edge
{
private:
    Edge *next;
    int Id1;
    int Id2;
    int weight;

public:
    Edge(int Id1, int Id2, int weight);
    static void append(Edge **edge, int Id1, int Id2, int weight);
    int getWeight();
    int getId1();
    int getId2();
    Edge *getNext();
    ~Edge();
};

#endif // EDGE_H
