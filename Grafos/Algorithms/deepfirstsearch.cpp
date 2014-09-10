#include "deepfirstsearch.h"

DeepFirstSearch::DeepFirstSearch(int initial, int final, Graph *graph)
{
    this->InitialVertex = initial;
    this->FinalVertex   = final;
    this->graph = graph;
}

void DeepFirstSearch::run()
{
    Vertex **V = graph->getVertex();
    int n = graph->getVertexCount();
    for(int i = 0; i < n; i++) {
        V[i]->setParent(NULL);
        V[i]->setEntranceTime(INFINITO);
        V[i]->setExitTime(INFINITO);
        V[i]->setColor(Qt::white);
    }

    time = 0;
    for(int i = InitialVertex; i < n; i++) {
        if(V[i]->getColor() == Qt::white) {
        visit(V[i]);
        }
    }

    emit finished();
}

void DeepFirstSearch::visit(Vertex *v)
{
    Edge *e; Vertex *actualVertex;
    v->setColor(Qt::gray);
    emit repaint();
    sleep(1);
    v->setEntranceTime(time++);

    for(e = v->getEdge(); e != NULL; e = e->getNext()) {
        actualVertex = graph->getVertex()[e->getTargetID()];
        if(actualVertex->getColor() == Qt::white) {
            actualVertex->setParent(v);
            visit(actualVertex);
        }
    }

    v->setExitTime(time++);
    v->setColor(Qt::black);

    emit repaint();

    sleep(1);
}
