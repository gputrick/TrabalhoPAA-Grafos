#include "vertex.h"

Vertex::Vertex(int id, QString name, int x, int y)
{
    this->id = id;
    this->name = name;
    this->x = x;
    this->y = y;
    this->ti = 0;
    this->to = 0;
    this->d = 0;
    this->n_a = 0;
    this->color = Qt::white;
    this->edge = NULL;
    this->father = NULL;
}

void Vertex::add(int id1, int id2, int w)
{
    Edge::append(&edge, id1, id2, w);
}

Edge *Vertex::getEdge()
{
    return this->edge;
}

QString Vertex::getName()
{
    return this->name;
}

int Vertex::getX()
{
    return this->x;
}

int Vertex::getY()
{
    return this->y;
}

QColor Vertex::getColor()
{
    return this->color;
}

void Vertex::setColor(QColor color)
{
    this->color = color;
}

void Vertex::setFather(Vertex *v)
{
    this->father = v;
}

int Vertex::getD()
{
    return this->d;
}

void Vertex::setD(int d)
{
    this->d = d;
}

Vertex::~Vertex()
{
    qDebug()  << "Excluindo vértice "<< name;

    if(this->edge != NULL){
        delete this->edge;
    }
}
