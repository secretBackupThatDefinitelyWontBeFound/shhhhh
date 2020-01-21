//
// Created by nikol on 1/3/19.
//

#ifndef GENERICSERVER_ISEARCHER_H
#define GENERICSERVER_ISEARCHER_H

#include "ISearchable.h"

template <class T,class Solution>

class ISearcher{
public:
    virtual Solution search(ISearchable<T> *s)=0;
    virtual int numOfNodesEvaluated()=0;
    ~ISearcher(){}

};

#endif //GENERICSERVER_ISEARCHER_H
