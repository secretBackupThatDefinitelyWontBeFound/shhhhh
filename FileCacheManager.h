//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_FILECACHEMANAGER_H
#define GENERICSERVER_FILECACHEMANAGER_H


#include "CacheManager.h"
#include "StringConvertor.h"
#include <fstream>
#include <vector>
#include <unordered_map>
#include <mutex>

//it is very important that this will not be used in the string form of T and of Solution
#define PROBLEM_SOLUTION_SEPORATOR "$"

template<typename Problem, typename Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    std::string _path;
    std::unordered_map<std::string, std::string> old_lines;
    std::unordered_map<std::string, std::string> new__lines;
    StringConvertor<Problem, Solution> *_string_covertor;
    std::mutex my_mutex;

public:
    FileCacheManager(const std::string &_path, StringConvertor<Problem, Solution> *_string_covertor) : _path(_path),
                                                                                                      _string_covertor(
                                                                                                              _string_covertor) {
        std::ifstream file(_path);
        if (!file.good()) {
            throw "error with file";
        }
        std::string line;
        std::string problem;
        std::string solution;
        unsigned long index;
        while (getline(file, line)) {
            index = line.find(PROBLEM_SOLUTION_SEPORATOR);
            if (index == std::string::npos) {
                throw "file does not fit format";
            }
            problem = line.substr(0, index);
            solution = line.substr(index + 1, line.size() - 1);
            old_lines[problem] = solution;
        }

        file.close();
    }


    ~FileCacheManager() {
        std::ofstream file(_path, std::ios::app);
        std::string to_wrie;
        for (auto pair : new__lines) {
            to_wrie = pair.first + PROBLEM_SOLUTION_SEPORATOR + pair.second + "\n";
            file << to_wrie;
        }
        file.close();
    }

    bool isSolutionExists(Problem &p) override {
        std::lock_guard<std::mutex> my_lock(my_mutex);
        return (old_lines.find(_string_covertor->problemToString(p)) != old_lines.end()) ||
               (new__lines.find(_string_covertor->problemToString(p)) != new__lines.end());
    }

    Solution getSolution(Problem &p) override {
        std::lock_guard<std::mutex> my_lock(my_mutex);
        std::string problem_str = _string_covertor->problemToString(p);
        if (old_lines.find(problem_str) != old_lines.end()) {
            return _string_covertor->stringToSolution(old_lines[problem_str]);
        }
        return _string_covertor->stringToSolution(new__lines[problem_str]);
    }

    void saveSolution(Problem &p, Solution &s) override {
        std::lock_guard<std::mutex> my_lock(my_mutex);
        new__lines[_string_covertor->problemToString(p)] = _string_covertor->solutionToString(s);
    }
};


#endif //GENERICSERVER_FILECACHEMANAGER_H
