#include "breadthfirstsearch.h"
#include "queue.h"

void BreadthFirstSearch::run()
{
    Vertex **vertex = graph->getVertex();
    int size = 11; //hack
    Queue<Vertex> *Q = new Queue<Vertex>();
    Vertex  *v, *va;
    Edge *edge;
    for(int i = 1; i < size; i++){
        vertex[i]->setParent(NULL);
        vertex[i]->setColor(Qt::white);
        vertex[i]->setDistance(INT_MAX);
    }
    vertex[0]->setParent(NULL);
    vertex[0]->setColor(Qt::gray);
    vertex[0]->setDistance(INT_MAX);
    Q->append(vertex[0]);
    while(!Q->isEmpty()){
        v = (Vertex*)Q->popBegin();
        qDebug() <<"------------------- vertice = "<< v->getName();
        for(edge = v->getEdge(); edge != NULL; edge = edge->getNext()){
            qDebug() << "Visitou ID2 = "<< edge->getId2();
            va = vertex[edge->getId2()];
            if(va->getColor() == Qt::white){
                va->setColor(Qt::gray);
                qDebug() << "Pintou de cinza";
                va->setParent(v);
                va->setDistance(v->getDistance()+1);
                Q->append(va);
            }else qDebug() << "ja esta cinza";
        }
        v->setColor(Qt::black);
        qDebug() << "pintou de preto";
    }
    qDebug() << "Saiu!!!!!!";
    delete Q;
}

BreadthFirstSearch::BreadthFirstSearch(Graph *graph)
{
    this->graph = graph;
    this->run();
}
