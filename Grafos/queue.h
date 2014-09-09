#ifndef QUEUE_H
#define QUEUE_H

#include "edge.h"
#include "vertex.h"
#include "element.h"


template <class type>
class Queue
{
private:
    Element<type> *first;
    Element<type> *last;
    unsigned int size;
public:
    Queue();
    void append(type *v);
    void removeElement(Element<type>*);
    Element<type> *popBegin();
    type *extractSmaller();
    bool isEmpty();
    ~Queue();
    unsigned int getSize() const;
};

#include "queue.cpp"

#endif // QUEUE_H
