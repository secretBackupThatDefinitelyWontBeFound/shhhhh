//
// Created by to on 1/12/19.
//

#ifndef GENERICSERVER_MANHATTANHEURISTIC_H
#define GENERICSERVER_MANHATTANHEURISTIC_H

#include "HeuristicCalculator.h"
#include <cmath>

template<typename T>
class ManhattanHeuristic : public HeuristicCalculator<T> {
    State<T> *goal;
public:

    double calculateHeuristic(State<T> *s) override {

        T s1 = s->getValue();
        T s2 = goal->getValue();
        double dx = abs(s1.first - s2.first);
        double dy = abs(s1.second - s2.second);

        return dx + dy;
    }

    void setGoal(State<T> *s) override {
        goal = s;
    }

};


#endif //GENERICSERVER_MANHATTANHEURISTIC_H
