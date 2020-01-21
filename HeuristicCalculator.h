//
// Created by to on 1/12/19.
//

#ifndef GENERICSERVER_HEURISTICCALCULATOR_H
#define GENERICSERVER_HEURISTICCALCULATOR_H

#include "State.h"

template<typename T>
class HeuristicCalculator {
public:
    virtual double calculateHeuristic(State<T> *s) = 0;
    virtual void setGoal(State<T> *s) = 0;
};


#endif //GENERICSERVER_HEURISTICCALCULATOR_H
