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
public:
    Queue();
    void append(type *v);
    type *popBegin();
    type *extractLess();
    bool isEmpty();
    ~Queue();
};

#include "queue.cpp"

#endif // QUEUE_H
