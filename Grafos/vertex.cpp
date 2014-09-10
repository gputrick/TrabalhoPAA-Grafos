#include "vertex.h"


int Vertex::getEdgeNumber() const
{
    return edgeNumber;
}

void Vertex::setEdgeNumber(int value)
{
    edgeNumber = value;
}

bool Vertex::operator> (const Vertex &v) const
{
    qDebug() << this->name << " " << this->distance << " " << v.getName() << " " << v.distance;
    return (this->distance > v.distance);
}

Vertex::Vertex(int id, QString name, int x, int y)
{
    this->id = id;
    this->name = name;
    this->x = x;
    this->y = y;
    this->exitTime = 0;
    this->entranceTime = 0;
    this->distance = 0;
    this->edgeNumber = 0;
    this->color = Qt::white;
    this->edge = NULL;
    this->parent = NULL;
}

void Vertex::add(int id1, int id2, int w)
{
    Edge::append(&edge, id1, id2, w);
}

Edge *Vertex::getEdge()
{
    return this->edge;
}

QString Vertex::getName() const
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

void Vertex::setParent(Vertex *v)
{
    this->parent = v;
}

Vertex *Vertex::getParent()
{
    return this->parent;
}

int Vertex::getDistance()
{
    return this->distance;
}

void Vertex::setDistance(int d)
{
    this->distance = d;
}

Vertex::~Vertex()
{
    qDebug()  << "Excluindo vértice "<< name;

    if(this->edge != NULL){
        delete this->edge;
    }
}
