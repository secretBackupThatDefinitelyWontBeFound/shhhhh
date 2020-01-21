//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_MYTESTCLIENTHANDLER_H
#define GENERICSERVER_MYTESTCLIENTHANDLER_H

#include "Solver.h"
#include "ClientHandler.h"
#include "CacheManager.h"

#define EXIT "end"


class MyTestClientHandler : public ClientHandler {
    Solver<std::string, std::string> *solver;
    CacheManager<std::string, std::string> *cache_manager;

public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cache_manager);

public:
    void handleClient(IOManager *io_manager) override;
};


#endif //GENERICSERVER_MYTESTCLIENTHANDLER_H
