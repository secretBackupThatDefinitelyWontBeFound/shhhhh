//
// Created by to on 1/13/19.
//



#include "MyClientHandler.h"


void MyClientHandler::handleClient(IOManager *io_manager) {
    std::string sep_lines = "/";
    std::vector<std::string> lines;
    std::string line = io_manager->getLine();
    while (line != EXIT) {
        lines.push_back(line);
        line = io_manager->getLine();

    }
    std::vector<std::vector<std::string>> matrix_str;
    std::string separator = ",";
    for (int i = 0; i < lines.size() - 2; ++i) {
        matrix_str.push_back(split(lines[i], separator));
    }
    std::vector<std::string> singal_state;
    singal_state = split(lines[lines.size() - 2], separator);
    std::pair<std::string, std::string> start(singal_state[0], singal_state[1]);
    singal_state = split(lines[lines.size() - 1], separator);
    std::pair<std::string, std::string> goal(singal_state[0], singal_state[1]);
    SearchableMatrix matrix(matrix_str, start, goal);
    std::vector<std::string> path;
    if (cache->isSolutionExists(matrix)) {
        path = cache->getSolution(matrix);
    } else {
        path = solver->solve(&matrix);
        cache->saveSolution(matrix, path);
    }

    std::string msg;
    for (std::string s : path) {
        msg += s + ",";
    }
    msg = msg.substr(0, msg.size() - 1);
    io_manager->sendMsg(msg);

}

std::vector<std::string> MyClientHandler::split(std::string &line, std::string &separator) {
    vector<string> answer;
    string part;
    string c;
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

MyClientHandler::MyClientHandler(Solver<ISearchable<pair<int, int>> *, vector<string>> *solver,
                                 CacheManager<SearchableMatrix, vector<string>> *file_cache) : solver(solver),
                                                                                               cache(file_cache) {}

