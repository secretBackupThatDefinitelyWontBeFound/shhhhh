//
// Created by to on 1/6/19.
//

#ifndef GENERICSERVER_BFS_H
#define GENERICSERVER_BFS_H

#include "Searcher.h"
#include <list>
#include <unordered_set>

template<class T>
//the solution type:list<State<T> >
class BFS : public Searcher<T, list<State<T>>> {
public:
    BFS() : Searcher<T, list<State<T>>>(BFS::compare) {}

    list<State<T> > search(ISearchable<T> *s) override {
        this->cleanOpenList();
        // the return value
        list<State<T>> answer;
        //set of the states we visited
        unordered_set<State<T> *> visited;
        //get the initial state
        State<T> *first_start = s->getInitialState();
        //insert the initial stat to the visited set
        visited.insert(first_start);
        //insert the initial stat to the open list
        this->addToOpenList(first_start);
        //while the open list is not empty
        while (this->getOpenListSize() != 0) {
            //get the current state we are in
            State<T> *current_stat = this->popOpenList();
            //check if we are done
            if (s->getGoalState()->equals(current_stat)) {
                return this->backTrace(current_stat);
            }
            //get all the states next to it
            vector<State<T> *> adj = s->getAllPossibleStates(current_stat);
            //go over all the states that are next to it
            for (State<T> *it : adj) {
                //if we didn't visit this state
                if (visited.find(it) == visited.end()) {
                    //set the pre
                    it->setPrev(current_stat);
                    //add it to the visited set
                    visited.insert(it);
                    //add it to openList
                    this->addToOpenList(it);
                }
            }
        }
        return answer;
    }

    static bool compare(State<T> *s1, State<T> *s2) {
        return false;
    }

};


#endif //GENERICSERVER_BFS_H
