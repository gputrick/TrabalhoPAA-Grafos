#ifndef EDGE_H
#define EDGE_H

#include <QDebug>

class Edge
{
private:
    Edge *next;
    int sourceID;
    int targetID;
    int weight;

public:
    Edge(int sourceID, int targetID, int weight);
    static void append(Edge **edge, int sourceID, int targetID, int weight);
    int getWeight();
    int getSourceID();
    int getTargetID();
    Edge *getNext();
    ~Edge();
};

#endif // EDGE_H
