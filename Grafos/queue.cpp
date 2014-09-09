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
}

template <class type>
Element<type> *Queue<type>::popBegin()
{
    Element<type> *e = NULL;
    Element<type> *tmp;

    if(first != NULL){
        e = first->getElement();
        tmp = first;
        first = first->getNext();
        delete tmp;
    }

    return e;
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
