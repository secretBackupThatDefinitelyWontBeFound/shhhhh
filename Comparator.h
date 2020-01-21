//
// Created by to on 1/11/19.
//

#ifndef GENERICSERVER_COMPARATOR_H
#define GENERICSERVER_COMPARATOR_H

#include "State.h"

template<typename T>
class Comparator {
    virtual bool operator()(State<T> *s1, State<T> *s2) = 0;
};

#endif //GENERICSERVER_COMPARATOR_H
