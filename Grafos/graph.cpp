#include "graph.h"

int Graph::getVertexIndex(QString name)
{
    for(int i = 0; i < size; i++){
        if((vertex[i] != NULL) && (vertex[i]->getName() == name.toUpper())){
            return i;
        }
    }

    return -1;
}

Graph::Graph(int n, QObject *parent) : QObject(parent)
{
    edge = NULL;
    this->max = n;
    this->size = 0;
    vertex = new Vertex*[max];

    for(int i = 0; i < max; i++){
        vertex[i] = NULL;
    }
}

void Graph::add(QString name, int x, int y)
{
    if(size < max){
        qDebug() << "Adicionando vértice " << name;
        vertex[size] = new Vertex(size, name.toUpper(), x, y);
        size++;
    } else {
        qDebug() << "Número de vértices maior que o informado";
    }
}

bool Graph::addEdge(QString source, QString target, int w)
{
    int s = getVertexIndex(source);
    int t = getVertexIndex(target);

    if((s == -1) || (t == -1)){
        qDebug() << "Vértice de [origem|destino] não encontrado: " << source << ", " << target;
        return false;
    }

    Edge::append(&edge, s, t, w);
    vertex[s]->add(s, t, w);

    return true;
}

Vertex **Graph::getVertex()
{
    return this->vertex;
}

int Graph::getVertexCount()
{
    return this->size;
}

Graph::~Graph()
{
    qDebug() << "Eliminando o grafo";

    for(int i = 0; i < size; i++){
        delete vertex[i];
    }

    delete[] vertex;
}
