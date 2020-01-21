//
// Created by to on 1/12/19.
//

#ifndef GENERICSERVER_PATHTOORDERS_H
#define GENERICSERVER_PATHTOORDERS_H


#include <string>
#include <vector>
#include <list>
#include "State.h"

#define LEFT "Left"
#define RIGHT "Right"
#define UP "Up"
#define DOWN "Down"

template<typename T>
class PathToOrders {
public:
    /**
     * convert a path to orders of left,right,up,down
     * @param path - the given path
     * @return orders of left,right,up,down
     */
    std::vector<std::string> convert(std::list<State<T> > path) {
        std::vector<std::string> answer;
        auto it = path.begin();
        if (it == path.end()) {
            return answer;
        }
        ++it;
        for (; it != path.end(); ++it) {
            --it;
            T p1 = (*it).getValue();
            ++it;
            T p2 = (*it).getValue();
            int dx = p2.second - p1.second;
            if (dx > 0) {
                answer.push_back(RIGHT);
                continue;
            }
            if (dx < 0) {
                answer.push_back(LEFT);
                continue;
            }
            int dy = p2.first - p1.first;
            if (dy > 0) {
                answer.push_back(DOWN);
                continue;
            }
            if (dy < 0) {
                answer.push_back(UP);
                continue;
            }

        }
        return answer;
    }
};


#endif //GENERICSERVER_PATHTOORDERS_H
