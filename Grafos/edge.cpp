#include "edge.h"

Edge::Edge(int id1, int id2, int w)
{
    this->sourceID  = id1; // origem
    this->targetID  = id2; // destino
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

int Edge::getSourceID()
{
    return this->sourceID;
}

int Edge::getTargetID()
{
    return this->targetID;
}

Edge *Edge::getNext()
{
    return this->next;
}

Edge::~Edge()
{

    qDebug() << "Excluindo aresta (" << sourceID <<","<< targetID <<"," << weight << ")";

    if (this->next != NULL){
        delete this->next;
    }
}
