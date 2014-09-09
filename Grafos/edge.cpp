#include "edge.h"

Edge::Edge(int id1, int id2, int w)
{
    this->id1  = id1; // origem
    this->id2  = id2; // destino
    this->w    = w;
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

int Edge::getW()
{
    return this->w;
}

int Edge::getIdV1()
{
    return this->id1;
}

int Edge::getIdV2()
{
    return this->id2;
}

Edge *Edge::getNext()
{
    return this->next;
}

Edge::~Edge()
{
    qDebug() << "Excluindo aresta (" << id1 <<","<< id2 <<"," << w << ")";

    if (this->next != NULL){
        delete this->next;
    }
}
