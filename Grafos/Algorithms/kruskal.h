#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <QThread>

#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include "element.h"
#include "queue.h"

class Kruskal : public QThread
{
    Q_OBJECT
private:
    Graph *graph;
    Queue<Edge> queue;
    void run();
public:
    Kruskal(Graph *graph);
signals:
    void repaint();
    void finished();
};

#endif // KRUSKAL_H
