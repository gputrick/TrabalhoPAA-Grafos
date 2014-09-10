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
    Graph *graph;
    void run();
public:
    BreadthFirstSearch(Graph *graph);
signals:
    void repaint();
    void finished();
};

#endif // BREADTHFIRSTSEARCH_H
