//
// Created by nikol on 12/26/18.
//


#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(IOManager *io_manager) {
    while (true) {
        std::string p = io_manager->getLine();
        if (p == EXIT) {
            break;
        }
        std::string s;
        if (cache_manager->isSolutionExists(p)) {
            s = cache_manager->getSolution(p);
        } else {
            s = solver->solve(p);
        }
        io_manager->sendMsg(s);
    }
}

MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cache_manager)
        : solver(solver), cache_manager(cache_manager) {}
