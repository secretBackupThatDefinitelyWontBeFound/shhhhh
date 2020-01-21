//
// Created by nikol on 1/3/19.
//

#ifndef GENERICSERVER_STATE_H
#define GENERICSERVER_STATE_H

template<typename T>
class State {
    T state;
    double cost;
    double ori_cost;
    State<T> *prev;
public:
    State<T> *&getPrev() {
        return prev;
    }

    State(T state) {
        this->state = state;
    }

    State(T state, double cost, State<T> *prev) : state(state), cost(cost), ori_cost(cost), prev(prev) {}

    double getOriCost() const {
        return ori_cost;
    }

    void setCost(double cost) {
        this->cost = cost;
    }

    T getValue() {
        return state;
    }

    double getCost() const {
        return cost;
    }

    void setPrev(State<T> *&prev) {
        this->prev = prev;
    }

    //each State will override this function.
    /**
     * check if one state if equals to the given state
     * @param s - the given state
     * @return true if the given state is the same as this state
     */
    bool equals(State<T> *s) {
        return this->state == s->state;
    }

};


#endif //GENERICSERVER_STATE_H
