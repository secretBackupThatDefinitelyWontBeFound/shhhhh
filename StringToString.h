//
// Created by to on 1/4/19.
//

#ifndef GENERICSERVER_STRINGTOSTRING_H
#define GENERICSERVER_STRINGTOSTRING_H

#include "StringConvertor.h"

class StringToString : public StringConvertor<std::string, std::string> {
public:
    std::string problemToString(std::string &p) override;

    std::string solutionToString(std::string &s) override;

    std::string stringToProblem(std::string &s) override;

    std::string stringToSolution(std::string &s) override;

};


#endif //GENERICSERVER_STRINGTOSTRING_H
