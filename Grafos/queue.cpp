#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"


template <class type>
unsigned int Queue<type>::getSize() const
{
    return size;
}

template <class type>
Queue<type>::Queue()
{
    first = NULL;
    last  = NULL;
    size  = 0;
}

template <class type>
void Queue<type>::append(type *v)
{
    Element<type> *e = new Element<type>(v);
    if(first == NULL){
        last = e;
        e->setNext(NULL);
    } else {
        e->setNext(first);
    }

    first = e;
    size++;
}

template <class type>
void Queue<type>::removeElement(Element<type> *e)
{
    Element<type> *it, *before = NULL;

    if(first != NULL){
        it = first;
        while(it != NULL && it != e){
            before = it;
            it = it->getNext();
        }

        if(it == e){
            if(before != NULL){
                before->setNext(it->getNext());
            } else {
                first = first->getNext();
            }
            size--;
        }
    }
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
type *Queue<type>::extractSmaller()
{
    Element<type> *e, *tmp;
    type *t = NULL;

    if(first != NULL){
        e = first;
        tmp = first->getNext();
        while(tmp != NULL){
            if(*(e->getElement()) > *(tmp->getElement())){
                e = tmp;
            }

            tmp = tmp->getNext();
        }

        t = e->getElement();
        removeElement(e);
    }

    return t;
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
