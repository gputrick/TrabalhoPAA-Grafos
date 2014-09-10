#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <QThread>

#include "queue.h"
#include "vertex.h"
#include "graph.h"

class BreadthFirstSearch: public QThread
{
   Q_OBJECT
private:
    int InitialVertex;
    int FinalVertex;
    Graph *graph;
    void run();
public:
    BreadthFirstSearch(int InitialVertex, int FinalVertex, Graph *graph);
signals:
    void repaint();
    void finished();
};

#endif // BREADTHFIRSTSEARCH_H
