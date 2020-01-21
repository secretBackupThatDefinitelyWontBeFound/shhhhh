//
// Created by to on 1/14/19.
//

#include "TestIO.h"

std::string TestIO::getMsg() {
    return std::__cxx11::string();
}

std::string TestIO::getLine() {
    std::string answer = lines[index];
    ++index;
    return answer;
}

void TestIO::sendMsg(std::string &msg) {
   std::cout<<msg<<std::endl;
}

TestIO::TestIO(const std::vector<std::string> &lines) : lines(lines), index(0) {}
