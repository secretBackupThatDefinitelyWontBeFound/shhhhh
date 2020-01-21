//
// Created by nikol on 1/6/19.
//

#ifndef GENERICSERVER_DFS_H
#define GENERICSERVER_DFS_H

#include "Searcher.h"
#include <list>
#include <iostream>
#include <unordered_set>

using namespace std;

template<class Problem>
class DFS : public Searcher<Problem, list<State<Problem> > > {


    /**
     * recursive helper function
     * @return goal state if there is a path from start to goal using dfs, otherwise NULL.
     */
    State<Problem>* isPath(State<Problem> *state, State<Problem> *goal, ISearchable<Problem> *s) {
        //openList is the states the alg. visited
        this->addToOpenList(state);
        //found goal!
        if (state->equals(goal)) {
            return state;
        }
        //count node as evaluated
        this->nodeEvaluated();
        //for each successor of current state, do the same thing with recursion.
        vector<State<Problem> *> adj = s->getAllPossibleStates(state);
        for (State<Problem> *it:adj) {
            //if not evaluated yet, evaluate.
            if (!this->openContains(it)) {
                it->setPrev(state);
                isPath(it,goal,s);
            }

        }
        //in case there is no path?
        //return NULL;
    }

public:
    DFS() : Searcher<Problem, list<State<Problem> > >(DFS::compare) {}

    /**
     *
     * @param s
     * @return the path using DFS, or empty list if there is no path.
     */
    list<State<Problem>> search(ISearchable<Problem> *s) override {
        this->cleanOpenList();
        State<Problem> *start = s->getInitialState();
        State<Problem> *goal = s->getGoalState();
        list<State<Problem> > path;
        if(isPath(start,goal,s)!=NULL)
           path =  this->backTrace(goal);
        return path;
    }


    static bool compare(State<Problem> *s1, State<Problem> *s2) {
        return true;
    }

};


#endif //GENERICSERVER_DFS_H
