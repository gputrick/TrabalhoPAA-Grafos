#ifndef GRAPH_H
#define GRAPH_H

#include <QDebug>
#include <QString>
#include <QColor>
#include <QObject>

#include "vertex.h"
#include "edge.h"

class Graph : public QObject
{
    Q_OBJECT
protected:
    Vertex **vertex;
    Edge *edge;
    int max;
    int size;
    int getVertexIndex(QString name);

public:
    Graph(int n, QObject *parent);
    void add(QString name, int x, int y);
    bool addEdge(QString source, QString target, int w);
    Vertex **getVertex();
    int getVertexCount();
    ~Graph();
};

#endif // GRAPH_H
