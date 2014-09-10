#include "breadthfirstsearch.h"
#include "queue.h"

/*BreadthFirstSearch::BreadthFirstSearch(Vertex **vertex)
{
    int size = 11; //hack
    Queue *queue = new Queue();
    Vertex  *v, *va;
    Edge *edge;
    for(int i = 1; i < size; i++){
        vertex[i]->setFather(NULL);
        vertex[i]->setColor(Qt::white);
        vertex[i]->setDistance(INT_MAX);
    }
    vertex[0]->setFather(NULL);
    vertex[0]->setColor(Qt::gray);
    vertex[0]->setDistance(INT_MAX);
    queue->append(vertex);
    while(!queue->isEmpty()){
        v = (Vertex*)queue->popBegin();
        for(edge = v->getEdge(); edge != NULL; edge = edge->getNext()){
            va = vertex[edge->getId2()];
            if(va->getColor() == Qt::white){
                va->setColor(Qt::gray);
                qDebug() << "funcionou?";
                va->setFather(v);
                va->setDistance(v->getDistance()+1);
                queue->append(va);
            }
            v->setColor(Qt::black);
        }
    }
    delete queue;
}*/
