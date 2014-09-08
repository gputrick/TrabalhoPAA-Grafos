#ifndef VERTICE_H
#define VERTICE_H

#include <QObject>
#include <QDebug>
#include <QColor>

#include <aresta.h>

class Vertice : public QObject {
    Q_OBJECT

public:
    Vertice ( int id, QString nome, int x, int y ) {
        this->id     = id;
        this->nome   = nome;
        this->x      = x;
        this->y      = y;

        this->ti     = 0;
        this->to     = 0;
        this->d      = 0;
        this->n_a    = 0;
        this->cor    = Qt::white;
        this->aresta = NULL;
        this->pai    = NULL;

    }

    void add ( int id1, int id2, int w ) { Aresta::append( &aresta, id1, id2, w ); }
    Aresta *getAresta ()                 { return this->aresta; }
    QString getNome ()                   { return this->nome; }
    int     getX ()                      { return this->x;    }
    int     getY ()                      { return this->y;    }
    QColor  getCor ()                    { return this->cor;  }

    ~Vertice() {
        qDebug() << "Excluindo vertice " << nome;
        if (this->aresta!=NULL)
            delete this->aresta;
    }

    int getD(){
        return this->d;
    }

    void setD(int d){
        this->d = d;
    }

    QColor getColor(){
        return this->cor;
    }

    void setColor( QColor color ){
        this->cor = color;
    }

    void setPai( Vertice *v ){
        this->pai = v;
    }

protected:
    int id; // Index do vértice no vetor
    QString nome;
    int ti; // tempo de entrada
    int to; // tempo de saida
    int d;  // distância
    int n_a; // número de arestas
    QColor cor; // cor do vértice
    Aresta *aresta;
    Vertice *pai;

    int x;
    int y;

};

#endif // VERTICE_H
