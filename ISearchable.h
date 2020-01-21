//
// Created by nikol on 1/3/19.
//

#ifndef GENERICSERVER_ISEARCHABLE_H
#define GENERICSERVER_ISEARCHABLE_H

#include "State.h"
#include <vector>

using namespace std;

template<typename T>
class ISearchable {
public:
    virtual State<T> *getInitialState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual vector<State<T> *> getAllPossibleStates(State<T> *s) = 0;
    ~ISearchable(){}
};

#endif //GENERICSERVER_ISEARCHABLE_H
