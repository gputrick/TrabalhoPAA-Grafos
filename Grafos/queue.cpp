#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"

template <class type>
Queue<type>::Queue()
{
    first = NULL;
    last  = NULL;
}

template <class type>
void Queue<type>::append(type *v)
{
    Element<type> *e = new Element<type>(v);
    if(first == NULL){
        last = e;
    } else {
        e->setNext(first);
    }
    first = e;
    last->setNext(NULL);
}

template <class type>
type *Queue<type>::popBegin()
{
    Element<type> *e = NULL;
    Element<type> *tmp;
    if(first != NULL){
        e = first;
        first = first->getNext();
    }
    return e->getElement();
}

template <class type>
type *Queue<type>::extractLess()
{
    Element<type> *e = NULL, *tmp = NULL;

    if(first != NULL){
        e = first;
        tmp = first->getNext();
        while(tmp != NULL){
            if(*(e->getElement()) < *(tmp->getElement())){
                e = tmp;
            }
            tmp = tmp->getNext();
        }
    }

    return e->getElement();
}

template <class type>
bool Queue<type>::isEmpty()
{
    qDebug() << "Entrou";
    qDebug() << "first is = "<< first;
    return (first == NULL);
}

template <class type>
Queue<type>::~Queue()
{
    if(first != NULL){
        delete first;
    }
}

#endif
