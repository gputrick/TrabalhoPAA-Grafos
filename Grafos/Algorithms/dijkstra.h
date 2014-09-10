#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <QThread>

#include "graph.h"
#include "vertex.h"
#include "queue.h"

class Dijkstra : public QThread
{
    Q_OBJECT
private:
    Graph *graph;
    int time;
    int InitialVertex;
    int FinalVertex;
    Queue<Vertex> queue;
    void run();
public:
    Dijkstra(int initial, int final, Graph *graph);
signals:
    void repaint();
    void finished();
};

#endif // DIJKSTRA_H
