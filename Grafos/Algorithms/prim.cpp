#include "prim.h"

void Prim::run()
{
    Queue<Vertex> *Q = new Queue<Vertex>();
    Vertex **vertex = graph->getVertex();
    for(int i = 0; i < graph->getVertexCount(); i++){
        vertex[i]->setDistance(INFINITO);
        vertex[i]->setParent(NULL);
        vertex[i]->setColor(Qt::white);
        Q->append(vertex[i]);
    }

    Vertex *Va, *V;
    Edge *e;

    vertex[initialVertice]->setDistance(0);

    while(!Q->isEmpty()){
        V = (Vertex*)Q->extractLess();
        V->setColor(Qt::gray);
    }


}

Prim::Prim(int initialVertice, Graph *graph)
{
    this->initialVertice = initialVertice;
    this->graph = graph;
}
