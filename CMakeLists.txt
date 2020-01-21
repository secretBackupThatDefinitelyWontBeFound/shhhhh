cmake_minimum_required(VERSION 3.12.3)
project(GenericServer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")

add_executable(GenericServer main.cpp CacheManager.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h
        FileCacheManager.cpp FileCacheManager.h MyTestClientHandler.h MyTestClientHandler.cpp MyParallelServer.cpp
        MyParallelServer.h MySerialServer.cpp MySerialServer.h Server.h Solver.h StringReverser.cpp StringReverser.h State.cpp State.h ISearchable.h Searcher.h ISearcher.h BestFS.cpp BestFS.h
        DFS.cpp DFS.h BFS.cpp BFS.h GenerigStringConvertor.h GenerigStringConvertor.cpp SearchableMatrix.cpp
        SearchableMatrix.h SocketManager.cpp StringToString.cpp Astar.h Astar.cpp Comparator.h SearchSolver.cpp SearchSolver.h HeuristicCalculator.h ManhattanHeuristic.cpp ManhattanHeuristic.h
        PathToOrders.cpp PathToOrders.h MyClientHandler.cpp MyClientHandler.h ClientArguments.h MatrixToString.cpp MatrixToString.h Spliter.cpp Spliter.h TestIO.cpp TestIO.h)