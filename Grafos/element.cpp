#ifndef ELEMENT_CPP
#define ELEMENT_CPP
#include "element.h"

template <class type>
Element<type>::Element(type *e)
{
    this->element = e;
}

template <class type>
void Element<type>::setNext(Element<type> *n)
{
    this->next = n;
}

template <class type>
Element<type> *Element<type>::getNext()
{
    return this->next;
}

template <class type>
type *Element<type>::getElement()
{
    return this->element;
}

template <class type>
Element<type>::~Element()
{
    if(next != NULL){
        delete next;
    }
}

#endif /*ELEMENT_CPP*/
