#ifndef PRIM_H
#define PRIM_H

#include <QThread>

#include "queue.h"
#include "vertex.h"
#include "graph.h"

class Prim : QThread
{
    int initialVertice;
    Graph *graph;
private:
    void run();
public:
    Prim(int initialVertice, Graph *graph);
};

#endif // PRIM_H
