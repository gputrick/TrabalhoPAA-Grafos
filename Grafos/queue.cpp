#include "queue.h"

Queue::Queue()
{
    first = NULL;
    last  = NULL;
}

void Queue::append(void *v)
{
    Element *e = new Element(v);
    if(first == NULL){
        last = e;
    } else {
        e->setNext(first);
    }

    first = e;
}

void *Queue::popBegin()
{
    void *e = NULL;
    Element *tmp;

    if(first != NULL){
        e = first->getElement();
        tmp = first;
        first = first->getNext();
        delete tmp;
    }

    return e;
}

bool Queue::isEmpty()
{
    return (first == NULL);
}

Queue::~Queue()
{
    if(first != NULL){
        delete first;
    }
}
