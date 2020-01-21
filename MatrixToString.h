//
// Created by to on 1/14/19.
//

#ifndef GENERICSERVER_MATRIXTOSTRING_H
#define GENERICSERVER_MATRIXTOSTRING_H

#include "StringConvertor.h"
#include "SearchableMatrix.h"
#include "Spliter.h"


class MatrixToString : public StringConvertor<SearchableMatrix,std::vector<std::string>>, public Spliter{
public:
    string problemToString(SearchableMatrix &p) override;

    string solutionToString(vector<string> &s) override;

    SearchableMatrix stringToProblem(std::string &s) override;

    vector<string> stringToSolution(std::string &s) override;

};


#endif //GENERICSERVER_MATRIXTOSTRING_H
