//
// Created by nikol on 12/30/18.
//


#include "StringReverser.h"


string StringReverser:: solve(string p) {
    std::reverse(p.begin(), p.end());
    return p;
}
