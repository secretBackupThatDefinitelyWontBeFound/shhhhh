//
// Created by to on 1/13/19.
//

#ifndef GENERICSERVER_MYCLIENTHANDLER_H
#define GENERICSERVER_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
#include "SearchableMatrix.h"

#include <vector>
#include <string>

#define EXIT "end"

class MyClientHandler : public ClientHandler {
    Solver<ISearchable<pair<int, int>> *, std::vector<std::string>>*solver;
    CacheManager<SearchableMatrix, std::vector<std::string>> *cache;


public:

    MyClientHandler(Solver<ISearchable<pair<int, int>> *, vector<string>> *solver,
                    CacheManager<SearchableMatrix, vector<string>> *file_cache);

    void handleClient(IOManager *io_manager) override;

private:
    /**
     * split a given line by a given separator
     * @param line - the given line
     * @param separator - the given separator
     * @return a vector of the split string
     */
    std::vector<std::string> split(std::string &line, std::string &separator);

};


#endif //GENERICSERVER_MYCLIENTHANDLER_H
