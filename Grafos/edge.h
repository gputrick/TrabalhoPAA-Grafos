#ifndef EDGE_H
#define EDGE_H

#include <QDebug>

class Edge
{
private:
    Edge *next;
<<<<<<< HEAD
    int sourceID;
    int targetID;
    int weight;

public:
    Edge(int sourceID, int targetID, int weight);
    static void append(Edge **edge, int sourceID, int targetID, int weight);
    int getWeight();
    int getSourceID();
    int getTargetID();
=======
    int Id1;
    int Id2;
    int weight;

public:
    Edge(int Id1, int Id2, int weight);
    static void append(Edge **edge, int Id1, int Id2, int weight);
    int getWeight();
    int getId1();
    int getId2();
>>>>>>> 31f4c362641391bf8f3a9c26f58fc8c88e000cc2
    Edge *getNext();
    ~Edge();
};

#endif // EDGE_H
