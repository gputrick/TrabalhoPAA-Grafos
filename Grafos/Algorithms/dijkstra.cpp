#include "dijkstra.h"

Dijkstra::Dijkstra(int initial, int final, Graph *graph)
{
    this->InitialVertex = initial;
    this->FinalVertex = final;
    this->graph = graph;
}

void Dijkstra::run()
{
    Vertex *actualVertex, *vertex;
    Edge *edge;
    Vertex **V = graph->getVertex();

    for ( int i = 0; i < graph->getVertexCount(); i++ ) {
        V[i]->setColor(Qt::white);
        V[i]->setParent(NULL);
        V[i]->setDistance(INFINITO);
    }

    V[InitialVertex]->setColor(Qt::gray);
    emit repaint();
    sleep(1);

    V[InitialVertex]->setDistance(0);

    queue.append(V[InitialVertex]);

    while(!queue.isEmpty()){
        vertex = queue.extractSmaller();
        vertex->setColor(Qt::black);
        emit repaint();
        sleep(1);

        for(edge = vertex->getEdge(); edge != NULL; edge = edge->getNext()){
            actualVertex = V[edge->getTargetID()];
            if((vertex->getDistance() + edge->getWeight()) < actualVertex->getDistance()) {
                actualVertex->setDistance(vertex->getDistance() + edge->getWeight());
                actualVertex->setParent(vertex);
            }

            if(actualVertex->getColor() == Qt::white){
                actualVertex->setColor(Qt::gray);
                emit repaint();
                sleep(1);

                queue.append(actualVertex);
            }
        }
    }

    emit finished();
}
