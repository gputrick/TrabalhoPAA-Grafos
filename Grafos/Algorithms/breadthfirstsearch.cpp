#include "breadthfirstsearch.h"
#include "queue.h"


void BreadthFirstSearch::run()
{
    qDebug() << "funciona";
    Vertex **vertex = graph->getVertex();
    Queue<Vertex> *Q = new Queue<Vertex>();
    Vertex *v, *va;
    Edge *edge;

    for(int i = 1; i < graph->getVertexCount(); i++){
        vertex[i]->setParent(NULL);
        vertex[i]->setColor(Qt::white);
        vertex[i]->setDistance(INT_MAX);
    }

    emit repaint();
    sleep(1);

    vertex[0]->setParent(NULL);
    vertex[0]->setColor(Qt::gray);
    vertex[0]->setDistance(INT_MAX);
    emit repaint();

    Q->append(vertex[0]);
    while(!Q->isEmpty()){

       Element<Vertex> *e = Q->popBegin();
        v = (Vertex*)e->getElement();

        for(edge = v->getEdge(); edge != NULL; edge = edge->getNext()){
            va = vertex[edge->getTargetID()];

            if(va->getColor() == Qt::white){
                sleep(1);
                va->setColor(Qt::gray);
                emit repaint();
                va->setParent(v);
                va->setDistance(v->getDistance()+1);
                Q->append(va);
            }

        }

        sleep(1);
        v->setColor(Qt::black);
        emit repaint();
    }
    delete Q;
    emit finished();
}

BreadthFirstSearch::BreadthFirstSearch(Graph *graph)
{
    this->graph = graph;
}
