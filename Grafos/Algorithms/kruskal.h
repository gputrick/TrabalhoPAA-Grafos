#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <QThread>

class Kruskal : public QThread
{
private:
    void run();
public:
    Kruskal();
};

#endif // KRUSKAL_H
