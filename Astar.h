//
// Created by to on 1/7/19.
//

#ifndef GENERICSERVER_ASTRAT_H
#define GENERICSERVER_ASTRAT_H

#include "BestFS.h"
#include "HeuristicCalculator.h"
#include "ManhattanHeuristic.h"
#include <list>

template<class T>
//the solution type:list<State<T> >

class Astar : public BestFS<T> {
    HeuristicCalculator<T> *heuristic_calculator;

public:
    //defulte constructor
    Astar() {
        heuristic_calculator = new ManhattanHeuristic<T>();
    }

    Astar(HeuristicCalculator<T> *heuristic_calculator) : heuristic_calculator(heuristic_calculator) {}

    virtual ~Astar() {
        delete (heuristic_calculator);
    }

private:
    void setDeterminedCost(State<T> *s) override {
        if (s->getPrev() == NULL) {
            s->setCost(s->getOriCost() + heuristic_calculator->calculateHeuristic(s));
        } else {
            s->setCost(s->getOriCost() + s->getPrev()->getCost() + heuristic_calculator->calculateHeuristic(s) -
                       heuristic_calculator->calculateHeuristic(s->getPrev()));
        }
    }

    void init(State<T> *goal) override {
        heuristic_calculator->setGoal(goal);
    }

};


#endif //GENERICSERVER_ASTRAT_H
