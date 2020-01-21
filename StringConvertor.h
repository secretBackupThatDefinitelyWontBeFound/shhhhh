//
// Created by to on 1/4/19.
//

#ifndef GENERICSERVER_STRINGCOVERTOR_H
#define GENERICSERVER_STRINGCOVERTOR_H


#include <string>

template<typename Problem, typename Solution>
class StringConvertor {
public:
    /**
     * convert a given Problem into string
     * @param p - the given Problem
     * @return the Problem as string
     */
    virtual std::string problemToString(Problem &p) = 0;

    /**
     * convert a given Solution into string
     * @param s -  the given Solution
     * @return the Solution as string
     */
    virtual std::string solutionToString(Solution &s) = 0;

    /**
     * convert a given string into Problem
     * @param s -  the given string
     * @return the string as Problem
     */
    virtual Problem stringToProblem(std::string &s) = 0;

    /**
     * convert a given string into Solution
     * @param s -  the given string
     * @return the string as Solution
     */
    virtual Solution stringToSolution(std::string &s) = 0;


};


#endif //GENERICSERVER_STRINGCOVERTOR_H
