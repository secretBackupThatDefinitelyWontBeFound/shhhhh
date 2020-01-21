//
// Created by nikol on 1/9/19.
//

#include "SearchableMatrix.h"

State<std::pair<int, int>> *SearchableMatrix::getInitialState() {
    return get(start);
}

State<std::pair<int, int>> *SearchableMatrix::getGoalState() {
    return get(goal);
}

State<std::pair<int, int>> *SearchableMatrix::get(std::pair<int, int> pos) {
    return matrix[pos.first][pos.second];
}

State<std::pair<int, int>> *SearchableMatrix::get(int i, int j) {
    return matrix[i][j];
}

std::vector<State<std::pair<int, int>> *> SearchableMatrix::getAllPossibleStates(State<std::pair<int, int>> *s) {
    std::vector<State<std::pair<int, int>> *> answer;
    std::vector<std::pair<int, int> > neighbors = getNeighbors(s->getValue());
    State<std::pair<int, int>> *posible_state;
    for (auto pos : neighbors) {
        posible_state = get(pos);
        if (posible_state->getCost() != -1) {
            answer.push_back(posible_state);
        }
    }
    return answer;

}

std::vector<std::pair<int, int> > SearchableMatrix::getNeighbors(std::pair<int, int> s) {
    std::vector<std::pair<int, int> > answer;
    //set as (x,y) - 1
    std::pair<int, int> temp_pos = s;
    //set as (x+1,y) - 2
    temp_pos.first = s.first + 1;
    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
        answer.push_back(temp_pos);
    }
    //set as (x-1,y) - 3
    temp_pos.first = s.first - 1;
    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
        answer.push_back(temp_pos);
    }
    //set as (x,y+1) - 4
    temp_pos.first = s.first;
    temp_pos.second = s.second + 1;
    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
        answer.push_back(temp_pos);
    }
    //set as (x,y-1) - 5
    temp_pos.second = s.second - 1;
    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
        answer.push_back(temp_pos);
    }
    //in case we need to add support to go in cross
//    //set as (x+1,y+1) - 6
//    temp_pos.first = s.first + 1;
//    temp_pos.second = s.second + 1;
//    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
//        answer.push_back(temp_pos);
//    }
//    //set as (x+1,y-1) - 7
//    temp_pos.second = s.second - 1;
//    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
//        answer.push_back(temp_pos);
//    }
//    //set as (x-1,y-1) - 8
//    temp_pos.first = s.first - 1;
//    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
//        answer.push_back(temp_pos);
//    }
//    //set as (x-1,y+1) - 9
//    temp_pos.first = s.first - 1;
//    temp_pos.second = s.second + 1;
//    if ((temp_pos.first >= 0 && temp_pos.first < hight) && ((temp_pos.second >= 0 && temp_pos.second < width))) {
//        answer.push_back(temp_pos);
//    }


    return answer;
}

SearchableMatrix::SearchableMatrix(std::vector<std::vector<std::string> > costs, pair<int, int> start,
                                   pair<int, int> goal) : hight(costs.size()), width(costs[0].size()), start(start),
                                                          goal(goal) {
    for (int i = 0; i < hight; ++i) {
        std::vector<State<std::pair<int, int>> *> line;
        for (int j = 0; j < width; ++j) {
            State<std::pair<int, int>> *state = new State<std::pair<int, int>>(std::pair<int, int>(i, j),
                                                                               atof(costs[i][j].c_str()), NULL);
            line.push_back(state);
        }
        matrix.push_back(line);
    }
}


SearchableMatrix::SearchableMatrix(std::vector<std::vector<std::string> > costs, pair<std::string, std::string> _start,
                                   pair<std::string, std::string> _goal) : hight(costs.size()), width(costs[0].size()) {
    this->start = pair<int, int>(stoi(_start.first), stoi(_start.second));
    this->goal = pair<int, int>(stoi(_goal.first), stoi(_goal.second));

    for (int i = 0; i < hight; ++i) {
        std::vector<State<std::pair<int, int>> *> line;
        for (int j = 0; j < width; ++j) {
            State<std::pair<int, int>> *state = new State<std::pair<int, int>>(std::pair<int, int>(i, j),
                                                                               atof(costs[i][j].c_str()), NULL);
            line.push_back(state);
        }
        matrix.push_back(line);
    }
}

int SearchableMatrix::getWidth() const {
    return width;
}

int SearchableMatrix::getHight() const {
    return hight;
}


SearchableMatrix::~SearchableMatrix() {
    for (int i = 0; i < hight; ++i) {
        for (int j = 0; j < width; ++j) {
            delete (matrix[i][j]);
        }
    }
}

std::string SearchableMatrix::matrixToString() {
    std::string answer;
    for (int i = 0; i < hight; ++i) {
        for (int j = 0; j < width; ++j) {
            answer += to_string(get(i, j)->getOriCost()) + ",";
        }
        answer = answer.substr(0, answer.size() - 1);
        answer+= "/";
    }
    answer = answer.substr(0, answer.size() - 1);
    return answer;
}




