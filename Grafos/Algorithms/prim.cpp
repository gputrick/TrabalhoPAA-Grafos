#include "prim.h"

void Prim::run()
{
    Queue<Vertex> *queue = new Queue<Vertex>();
    Vertex **vertex = graph->getVertex();

    qDebug() << graph->getVertexCount();

    for(int i = 0; i < graph->getVertexCount(); i++){
        vertex[i]->setDistance(INFINITO);
        vertex[i]->setParent(NULL);
        vertex[i]->setColor(Qt::white);
        emit repaint();
        queue->append(vertex[i]);
    }

    Vertex *actualVetex, *V;
    Edge *e;

    vertex[initialVertice]->setDistance(0);

    while(!queue->isEmpty()){
        qDebug() << "Size: " << queue->getSize();
        V = queue->extractSmaller();
        V->setColor(Qt::gray);
        emit repaint();
        QThread::sleep(1);
        for(e = V->getEdge(); e != NULL; e = e->getNext()){
            actualVetex = vertex[e->getTargetID()];
            if( (actualVetex->getColor() != Qt::black) && (actualVetex->getDistance() > e->getWeight()) ){
                actualVetex->setParent(V);
                actualVetex->setDistance(e->getWeight());
            }
        }

        V->setColor(Qt::black);
        emit repaint();
        QThread::sleep(1);
    }

    delete queue;
    emit finished();
}

Prim::Prim(int initialVertice, Graph *graph)
{
    this->initialVertice = initialVertice;
    this->graph = graph;
}
