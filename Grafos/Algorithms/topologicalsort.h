#ifndef TOPOLOGICALSORT_H
#define TOPOLOGICALSORT_H

#include <QThread>

#include "graph.h"
#include "queue.h"
#include "vertex.h"
#include "edge.h"

class TopologicalSort : public QThread
{
    Q_OBJECT
private:
    int time;
    int InitialVertex;
    int FinalVertex;
    Graph *graph;
    Queue<Vertex> queue;
    void run();
    void visit(Vertex *vertex);
public:
    TopologicalSort(int initial, int final, Graph *graph);
    Queue<Vertex> *getQueue();
signals:
    void repaint();
    void finished();
};

#endif // TOPOLOGICALSORT_H
