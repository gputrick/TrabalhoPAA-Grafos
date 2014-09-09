#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include "queue.h"
#include "vertex.h"
#include "graph.h"

class BreadthFirstSearch
{
    Graph *graph;
private:
    void run();
public:
    BreadthFirstSearch(Graph *graph);
};

#endif // BREADTHFIRSTSEARCH_H
