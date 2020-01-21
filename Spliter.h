//
// Created by to on 1/14/19.
//

#ifndef GENERICSERVER_SPLITER_H
#define GENERICSERVER_SPLITER_H


#include <string>
#include <vector>

class Spliter {
public:
    std::vector<std::string> split(std::string &line, std::string &separator);

};


#endif //GENERICSERVER_SPLITER_H
