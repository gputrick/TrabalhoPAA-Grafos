#ifndef DIJSTRA_H
#define DIJKSTRA_H

#include <vertice.h>
#include <aresta.h>
#include <fila.h>

class dijkstra{
    void dijkstra(int vi){
        Vertice **vertice;
        Vertice *v, *va;
        Aresta *a;
        Lista *l = new Lista();
        for (int i = 1; i < nVertices; i++){
            vertice[i]->setColor(Qt::white);
            vertice[i]->setPai(NULL);
            vertice[i]->setD(0);
        }
        vertice[vi]->setColor(Qt::gray);
        vertice[vi]->setD(0);
        l->append(vertice[vi]);
        while(!l->isEmpty){
            v = l->removeMenorVertice(); // falta implementar (na vdd falta bastante coisa .. kk)
            v->setColor(QColor::black);
            for(a = v->getAresta(); a != null; a = a->getNext()){
                Va = vertice[a->getV2()];
                d = v->getD() + a->getW();
                if(d < va->getD()){
                    va->setD(d);
                    va->setPai(v);
                }
                if(va->getColor() == Qt::white){
                    va->setColor(Qt::gray);
                    l->append(va);
                }
            }
        }
        delete l;
    }
};

#endif // DIJKSTRA_H
