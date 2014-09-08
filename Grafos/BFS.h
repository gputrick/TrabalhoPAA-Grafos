#ifndef BFS_H
#define BFS_H

#include <fila.h>

class BFS{
    void BFS(){
        if(size = 0){
            Lista = new Lista();
            Vertice *v, *va;
            Aresta *a;
            int i;

            for(i = 0; i < size; i++){
                v[i]->setpai(null);
                v[i]->setcolor(white);
                v[i]->setid(INF);
            }
            v[i]->setpai(null);
            v[i]->setcolor(gray);
            v[i]->setid(0);
        }
        f->push(v[0]);

        mostrar();

        while(!f->getIsEmpty()){
           v = (Vertice*)f->pop();
           for(a=v->){

           }
           mostrar();
        }
    }
};

#endif // BFS_H


