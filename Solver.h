//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_SOLVER_H
#define GENERICSERVER_SOLVER_H

template<class Problem, class Solution>

class Solver {
public:
    virtual Solution solve(Problem p) = 0;

    virtual ~Solver() {}
};

#endif //GENERICSERVER_SOLVER_H
