#include "element.h"

Element::Element(void *e)
{
    this->element = e;
}

void Element::setNext(Element *n)
{
    this->next = n;
}

Element *Element::getNext()
{
    return this->next;
}

void *Element::getElement()
{
    return this->element;
}

Element::~Element()
{
    if(next != nullptr){
        delete next;
    }
}
