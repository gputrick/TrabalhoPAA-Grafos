#ifndef DEEPFIRSTSEARCH_H
#define DEEPFIRSTSEARCH_H

#include <QThread>

#include "graph.h"
#include "vertex.h"

class DeepFirstSearch : public QThread
{
    Q_OBJECT
private:
    int time;
    int InitialVertex;
    int FinalVertex;
    Graph *graph;
    void run();
    void visit(Vertex*);
public:
    DeepFirstSearch(int initial, int final, Graph *graph);
signals:
    void repaint();
    void finished();
};

#endif // DEEPFIRSTSEARCH_H
