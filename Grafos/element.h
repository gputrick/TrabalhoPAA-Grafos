#ifndef ELEMENT_H
#define ELEMENT_H

template <class type>
class Element
{
private:
    type *element;
    Element<type> *next;
public:
    Element(type *e);
    void setNext(Element<type> *n);
    Element<type> *getNext();
    type *getElement();
    ~Element();
};

#include "element.cpp"

#endif // ELEMENT_H
