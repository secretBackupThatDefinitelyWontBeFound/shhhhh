//
// Created by to on 1/15/19.
//

#ifndef GENERICSERVER_ALGOFACTORY_H
#define GENERICSERVER_ALGOFACTORY_H

#include "Astar.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"

#include <string>

#define A_STAR "Astar"
#define BEST_FS "BestFS"
#define BFS_ALGO "BFS"
#define DFS_ALGO "DFS"

template<typename T>
class AlgoFactory {
    std::string algo_symbol;

public:

    AlgoFactory(const string &algp_symbol) : algo_symbol(algp_symbol) {}

    /**
     * create algo
     * @return  the algo synamiced cast
     */
    ISearcher<T, list<State<T>>> *createAlgo() {
        if (algo_symbol == A_STAR) {
            return new Astar<T>;
        }
        if (algo_symbol == BEST_FS) {
            return new BestFS<T>;
        }
        if (algo_symbol == BFS_ALGO) {
            return new BFS<T>;
        }
        if (algo_symbol == DFS_ALGO) {
            return new DFS<T>;
        }

    }

};


#endif //GENERICSERVER_ALGOFACTORY_H
