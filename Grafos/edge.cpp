#include "edge.h"

Edge::Edge(int id1, int id2, int w)
{
    this->coordX  = id1; // origem
    this->coordY  = id2; // destino
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

int Edge::getCoordX()
{
    return this->coordX;
}

int Edge::getCoordY()
{
    return this->coordY;
}

Edge *Edge::getNext()
{
    return this->next;
}

Edge::~Edge()
{
    qDebug() << "Excluindo aresta (" << coordX <<","<< coordY <<"," << weight << ")";

    if (this->next != NULL){
        delete this->next;
    }
}
