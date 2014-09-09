#ifndef EDGE_H
#define EDGE_H

#include <QDebug>

class Edge
{
private:
    Edge *next;
    int id1;
    int id2;
    int w;

public:
    Edge(int id1, int id2, int w);
    static void append(Edge **edge, int id1, int id2, int w);
    int getW();
    int getIdV1();
    int getIdV2();
    Edge *getNext();
    ~Edge();
};

#endif // EDGE_H
