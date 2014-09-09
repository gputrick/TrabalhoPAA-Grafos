#ifndef ELEMENT_H
#define ELEMENT_H

class Element
{
private:
    void *element;
    Element *next;
public:
    Element(void *e);
    void setNext(Element *n);
    Element *getNext();
    void *getElement();
    ~Element();
};

#endif // ELEMENT_H
