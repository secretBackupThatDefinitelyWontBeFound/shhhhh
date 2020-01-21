//
// Created by to on 1/14/19.
//

#include "Spliter.h"

std::vector<std::string> Spliter::split(std::string &line, std::string &separator) {

    std::vector<std::string> answer;
    std::string part;
    std::string c;
    for (int i = 0; i < line.size(); ++i) {
        c = line[i];
        if (c == separator) {
            if (!part.empty()) {
                answer.push_back(part);
            }
            part = "";
            continue;
        }
        part += line[i];
    }
    if (!part.empty()) {
        answer.push_back(part);
    }
    return answer;

}
