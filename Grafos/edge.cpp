#include "edge.h"

Edge::Edge(int id1, int id2, int w)
{
    this->Id1  = id1; // origem
    this->Id2  = id2; // destino
    this->weight    = w;
    this->next = NULL;
}

void Edge::append(Edge **edge, int id1, int id2, int w)
{
    if(*edge == NULL){
        *edge = new Edge(id1, id2, w);
    } else {
        append(&(*edge)->next, id1, id2, w);
    }
}

int Edge::getWeight()
{
    return this->weight;
}

int Edge::getId1()
{
    return this->Id1;
}

int Edge::getId2()
{
    return this->Id2;
}

Edge *Edge::getNext()
{
    return this->next;
}

Edge::~Edge()
{
    qDebug() << "Excluindo aresta (" << Id1 <<","<< Id2 <<"," << weight << ")";

    if (this->next != NULL){
        delete this->next;
    }
}
