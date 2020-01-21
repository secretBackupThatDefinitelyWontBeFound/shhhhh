//
// Created by to on 1/12/19.
//

#ifndef GENERICSERVER_SEARCHPROBLEM_H
#define GENERICSERVER_SEARCHPROBLEM_H

#include "AlgoFactory.h"
#include "ISearchable.h"
#include "Solver.h"
#include "PathToOrders.h"
#include "FileCacheManager.h"

#include <string>
#include <list>
#include <vector>
#include <mutex>

template<typename T>
class SearchSolver : public Solver<ISearchable<T> *, std::vector<std::string>> {
    AlgoFactory<T> factory;
    PathToOrders<T> path_to_orders;
    std::vector<ISearcher<T, list<State<T>>>* > to_del;

public:
    SearchSolver(std::string &symbol) : factory(symbol) {}

    std::vector<std::string> solve(ISearchable<T> *p) override {
        ISearcher<T, list<State<T>>> *searcher = factory.createAlgo();
        return path_to_orders.convert(searcher->search(p));
    }

    virtual ~SearchSolver() {
        for (ISearcher<T, list<State<T>>>* searcher: to_del) {
            delete (searcher);
        }
    }
};


#endif //GENERICSERVER_SEARCHPROBLEM_H
