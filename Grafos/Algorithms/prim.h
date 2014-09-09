#ifndef PRIM_H
#define PRIM_H

#include <QThread>

#include "queue.h"
#include "vertex.h"

class Prim : QThread
{
private:
    void run();
public:
    Prim();
};

#endif // PRIM_H
