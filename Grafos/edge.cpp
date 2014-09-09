#include "edge.h"

Edge::Edge(int id1, int id2, int w)
{
<<<<<<< HEAD
    this->sourceID  = id1; // origem
    this->targetID  = id2; // destino
=======
    this->Id1  = id1; // origem
    this->Id2  = id2; // destino
>>>>>>> 31f4c362641391bf8f3a9c26f58fc8c88e000cc2
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

<<<<<<< HEAD
int Edge::getSourceID()
{
    return this->sourceID;
}

int Edge::getTargetID()
{
    return this->targetID;
=======
int Edge::getId1()
{
    return this->Id1;
}

int Edge::getId2()
{
    return this->Id2;
>>>>>>> 31f4c362641391bf8f3a9c26f58fc8c88e000cc2
}

Edge *Edge::getNext()
{
    return this->next;
}

Edge::~Edge()
{
<<<<<<< HEAD
    qDebug() << "Excluindo aresta (" << sourceID <<","<< targetID <<"," << weight << ")";
=======
    qDebug() << "Excluindo aresta (" << Id1 <<","<< Id2 <<"," << weight << ")";
>>>>>>> 31f4c362641391bf8f3a9c26f58fc8c88e000cc2

    if (this->next != NULL){
        delete this->next;
    }
}
