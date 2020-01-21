//
// Created by to on 1/14/19.
//


#include "MatrixToString.h"

string MatrixToString::problemToString(SearchableMatrix &p) {
    std::string answer = p.matrixToString();
    pair<int, int> temp_pair = p.getInitialState()->getValue();
    answer += "/" + to_string(temp_pair.first) + "," + to_string(temp_pair.second);
    temp_pair = p.getGoalState()->getValue();
    answer += "/" + to_string(temp_pair.first) + "," + to_string(temp_pair.second);
    return answer;


}

string MatrixToString::solutionToString(vector<string> &s) {
    std::string answer;
    for (auto str : s) {
        answer += str + ",";
    }
    answer = answer.substr(0, answer.size() - 1);
    return answer;
}

SearchableMatrix MatrixToString::stringToProblem(std::string &s) {
    std::string sep_lines = "/";
    std::vector<std::string> lines = split(s, sep_lines);
    std::vector<std::vector<std::string>> matrix_str;
    std::string separator = ",";
    for (int i = 0; i < lines.size() - 2; ++i) {
        matrix_str.push_back(split(lines[i], separator));
    }
    std::vector<std::string> singal_state;
    singal_state = split(lines[lines.size() - 2], separator);
    std::pair<std::string, std::string> start(singal_state[0], singal_state[1]);
    singal_state = split(lines[lines.size() - 1], separator);
    std::pair<std::string, std::string> goal(singal_state[0], singal_state[1]);

    return SearchableMatrix(matrix_str, start, goal);


}

vector<string> MatrixToString::stringToSolution(std::string &s) {
    std::string sep = ",";
    return this->split(s, sep);
}
