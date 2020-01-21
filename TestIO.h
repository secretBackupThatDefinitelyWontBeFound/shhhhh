//
// Created by to on 1/14/19.
//

#ifndef GENERICSERVER_TESTIO_H
#define GENERICSERVER_TESTIO_H

#include <vector>
#include <iostream>
#include "IOManager.h"

class TestIO : public  IOManager{
    std::vector<std::string> lines;
    int index;
public:
    TestIO(const std::vector<std::string> &lines);

    std::string getMsg() override;

    std::string getLine() override;

    void sendMsg(std::string &msg) override;

};


#endif //GENERICSERVER_TESTIO_H
