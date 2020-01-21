//
// Created by nikol on 1/3/19.
//

#ifndef GENERICSERVER_BESTFS_H
#define GENERICSERVER_BESTFS_H

#include "Searcher.h"
#include <unordered_set>
#include <list>
#include <algorithm>
#include "CompareStates.h"

using namespace std;

template<typename T>
//the solution type:list<State<T> >
class BestFS : public Searcher<T, list<State<T> > > {
public:
    BestFS() : Searcher<T, list<State<T> > >(BestFS::compare) {}

    list<State<T> > search(ISearchable<T> *s) override {
        this->cleanOpenList();
        init(s->getGoalState());
        setDeterminedCost(s->getInitialState());
        this->addToOpenList(s->getInitialState());
        //evaluated states
        unordered_set<State<T> *> closed;
        while (this->getOpenListSize() > 0) {
            State<T> *n = this->popOpenList();//remove best state
            if (n->equals(s->getGoalState())) {//reached goal
                //returns the path through parents.
                return this->backTrace(n);
            }
            closed.insert(n);
            //list of n's children
            vector<State<T> *> successors = s->getAllPossibleStates(n);
            // for (int i = 0; i < successors.size(); i++) {
            for (State<T> *successor : successors) {
                double new_cost = successor->getOriCost() + n->getCost();
                //current son is not in closed and not in openList (meaning, wasn't visited)
                if (closed.find(successor) == closed.end() && !this->openContains(successor)) {
                    successor->setPrev(n);
                    setDeterminedCost(successor);
                    this->addToOpenList(successor);
                    //check if it is in closed and new cost is better then old cost
                } else if (new_cost < successor->getCost()) {

                    if (this->openContains(successor)) {
                        //update the state and the openlist
                        successor->setCost(new_cost);
                        this->adjustOpenList(successor);
                    }
                }
            }
        }
        return list<State<T>>();
        //done.
    }


    static bool compare(State<T> *s1, State<T> *s2) {
        return s1->getCost() < s2->getCost();
    }

    virtual ~BestFS() {}

protected:
    virtual void setDeterminedCost(State<T> *s) {
        if (s->getPrev() == NULL) {
            s->setCost(s->getOriCost());
        } else {
            s->setCost(s->getOriCost() + s->getPrev()->getCost());
        }
    }

    /**
     * dummy function in BestFS, but needed in AStar (BestFS's son)
     * @param goal - the goal State
     */
    virtual void init(State<T> *goal) {};


};


#endif //GENERICSERVER_BESTFS_H
