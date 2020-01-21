//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_CACHEMANAGER_H
#define GENERICSERVER_CACHEMANAGER_H

template <class Problem,class Solution>
class CacheManager{
public:
    virtual bool isSolutionExists(Problem &p) = 0;
    virtual Solution getSolution(Problem &p)= 0;
    virtual void saveSolution(Problem &p, Solution &s)= 0;

    virtual ~CacheManager() {}
};

#endif //GENERICSERVER_CACHEMANAGER_H
