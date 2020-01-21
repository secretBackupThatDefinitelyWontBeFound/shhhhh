//
// Created by to on 1/7/19.
//

#ifndef GENERICSERVER_GENERIGSTRINGCONVEROTR_H
#define GENERICSERVER_GENERIGSTRINGCONVEROTR_H

#include <functional>
#include "StringConvertor.h"

template<typename Problem, typename Solution>
class GenerigStringConvertor : public StringConvertor<Problem, Solution> {
    std::function<std::string(Problem p)> problem_to_string;
    std::function<std::string(Solution s)> solution_to_string;
    std::function<Problem(std::string)> string_to_problem;
    std::function<Solution(std::string)> string_to_solution;

public:
    GenerigStringConvertor(const std::function<std::string(Problem)> &problem_to_string,
                           const std::function<std::string(Solution)> &solution_to_string,
                           const std::function<Problem(std::string)> &string_to_problem,
                           const std::function<Solution(std::string)> &string_to_solution) : problem_to_string(
            problem_to_string), solution_to_string(solution_to_string), string_to_problem(string_to_problem),
                                                                                             string_to_solution(
                                                                                                     string_to_solution) {}

public:
    std::string problemToString(Problem p) override {
        return problem_to_string(p);
    }

    std::string solutionToString(Solution s) override {
        return solution_to_string(s);
    }

    Solution stringToProblem(std::string s) override {
        return string_to_problem(s);
    }

    Solution stringToSolution(std::string s) override {
        return string_to_solution(s);
    }

};


#endif //GENERICSERVER_GENERIGSTRINGCONVEROTR_H
