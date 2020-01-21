//
// Created by nikol on 1/3/19.
//

#ifndef GENERICSERVER_SEARCHER_H
#define GENERICSERVER_SEARCHER_H

#include <set>
#include <list>
#include <iostream>
#include "ISearcher.h"

#include "Comparator.h"

#include "CompareStates.h"

using namespace std;

template<typename T, typename Solution>

class Searcher : public ISearcher<T, Solution> {
    multiset<State<T> *, bool (*)(State<T> *s1, State<T> *s2)> openList;
//    set<State<T> *, CompareStates<T>> openList;
    int evaluatedNodes;

public:
    Searcher(bool (*cmp_func)(State<T> *s1, State<T> *s2)) : evaluatedNodes(0), openList(cmp_func) {}

    State<T> *popOpenList() {
        evaluatedNodes++;
        auto it = openList.begin();
        State<T> *answer = *it;
        openList.erase(it);
        return answer;
    }

    int getOpenListSize() {
        return (int) openList.size();
    }

    int numOfNodesEvaluated() override {
        return evaluatedNodes;
    }

    multiset<State<T> *, CompareStates<T>> &getOpenList() {
        return openList;
    }

    void addToOpenList(State<T> *s) {
        openList.insert(s);
    }

    /**
     * gets a state
     * @return if state is in open list-true, false otherwise.
     */
    bool openContains(State<T> *s) {
        for (State<T> *state : openList) {
            if (state->equals(s)) {
                return true;
            }
        }
        return false;
    }


    /**
     *adjust the cost of a given state that is in the openList
     * @param new_state - the given state
     */
    void adjustOpenList(State<T> *new_state) {
        openList.erase(new_state);
        openList.insert(new_state);
    }

    /**
     * get the path by getting the states before the goal
     */
    list<State<T> > backTrace(State<T> *end) {
        list<State<T> > path;
        path.push_back(*end);
        State<T> *pre = end->getPrev();
        while (pre != NULL) {
            path.push_back(*pre);
            pre = pre->getPrev();
        }
        //reverse the list
        path.reverse();
        cout<<evaluatedNodes;
        return path;
    }

    /**
     * clean the openList
     */
    void cleanOpenList() {
        while (getOpenListSize() > 0) {
            popOpenList();
        }
        evaluatedNodes = 0;
    }

    virtual ~Searcher() {}

};

#endif //GENERICSERVER_SEARCHER_H
