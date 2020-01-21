//
// Created by nikol on 12/30/18.
//

#ifndef GENERICSERVER_STRINGREVERSER_H
#define GENERICSERVER_STRINGREVERSER_H

#include "Solver.h"
#include <string>
#include <algorithm>

using namespace std;


class StringReverser : public Solver<string,string> {
public:
    string solve(string p) override;
};


#endif //GENERICSERVER_STRINGREVERSER_H
