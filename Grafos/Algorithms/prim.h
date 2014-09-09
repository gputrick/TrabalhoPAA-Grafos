#ifndef PRIM_H
#define PRIM_H

#include <QThread>

#include "queue.h"
#include "vertex.h"
#include "graph.h"

class Prim : public QThread
{
    Q_OBJECT
private:
    int initialVertice;
    Graph *graph;
    void run();
public:
    Prim(int initialVertice, Graph *graph);
signals:
    void repaint();
};

#endif // PRIM_H
