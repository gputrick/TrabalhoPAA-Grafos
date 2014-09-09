#ifndef QUEUE_H
#define QUEUE_H

#include "edge.h"
#include "vertex.h"
#include "element.h"

class Queue
{
private:
    Element *first;
    Element *last;
public:
    Queue();
    void append(void *v);
    void *popBegin();
    bool isEmpty();
    ~Queue();
};

#endif // QUEUE_H
