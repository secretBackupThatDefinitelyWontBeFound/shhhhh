//
// Created by to on 1/9/19.
//

#ifndef GENERICSERVER_COMPARESTATES_H
#define GENERICSERVER_COMPARESTATES_H

#include "State.h"
#include "Comparator.h"

template<typename T>
class CompareStates : Comparator<T> {
public:
    bool operator()(State<T> *s1, State<T> *s2) override {
        return s1->getCost() < s2->getCost();
    }


};


#endif //GENERICSERVER_COMPARESTATES_H
