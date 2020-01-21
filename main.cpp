#include <iostream>
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "StringToString.h"
#include "GenerigStringConvertor.h"

#include <string>


#include "State.h"
#include <set>
#include <string>
#include <list>
#include "ISearcher.h"
#include "SearchableMatrix.h"
#include "Searcher.h"
#include "BestFS.h"
#include "BFS.h"
#include "DFS.h"
#include "Astar.h"
#include "PathToOrders.h"
#include "MatrixToString.h"
#include "SearchSolver.h"
#include "TestIO.h"
#include "Spliter.h"
#include "MyParallelServer.h"
#include "AlgoFactory.h"
#include "MyTestClientHandler.h"

using namespace std;


int main() {
    Spliter spliter;
    MatrixToString sc;
    MatrixToString *sc_ptr = &sc;
    StringToString sts;
    StringToString *sts_ptr = &sts;
    StringReverser sr;
    StringReverser *sr_ptr = &sr;

    CacheManager<string, string> *fsm = new FileCacheManager<string, string>("test", sts_ptr);
    CacheManager<SearchableMatrix, std::vector<std::string>> *fcm = new FileCacheManager<SearchableMatrix, std::vector<std::string>>(
            "test", sc_ptr);
    Searcher<pair<int, int>, list<State<pair<int, int>>> > *b = new Astar<pair<int, int>>;
//    AlgoFactory<pair<int, int>> algo_factory(A_STAR);
    string symbol = BEST_FS;
    SearchSolver<pair<int, int>> solver(symbol);
    Solver<ISearchable<pair<int, int>> *, std::vector<std::string>> *s_ptr = &solver;



    //MyClientHandler client_handler(s_ptr, fcm);
    MyClientHandler client_handler(s_ptr, fcm);
    MyTestClientHandler ch(sr_ptr, fsm);

//    //server part
//
//
//    MyParallelServer server;
////    server.open(5400, client_handler);
//    server.open(5400, client_handler);
//    std::string temp;
//    while (temp != "exit") {
//        cin >> temp;
//    }
//    server.stop();
//    while (temp != "exit") {
//        cin >> temp;
//    }
//
//


    string line1_str = "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8";
    string line2_str = "4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4";
    string line3_str = "4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7";
    string line4_str = "3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7";
    string line5_str = "0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1";
    string line6_str = "7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9";
    string line7_str = "6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8";
    string line8_str = "10, 8, 0, 2, 3, 8, 0, 10, 10, 2, 7";
    string line9_str = "5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1";
    string line10_str = "7, 7, 5, 10, 8, 10, 1, 6, 9, 9, 1";
    string line11_str = "5,10, 1,10, 7, 7, 3,10, 8, 0, 6";
    string line12_str = "0,0";
    string line13_str = "10,10";
    string line14_str = "exit";


    //put the input here

    string input = " 7, 9, 4, 3, 7, 1, 4, 2, 7, 8, 2, 3, 1, 3, 6, 8, 0, 5, 4,-1, 5, 8, 2, 9, 6, 9, 5, 6, 6, 7\n"
                 " 6, 6, 4,-1, 3, 0, 0, 7, 6, 9, 0, 1, 3, 1, 3, 1, 5,-1, 2,-1, 5, 0, 1, 9,10, 7, 4, 8, 2,-1\n"
                 " 9, 0, 0, 5, 9, 6, 5, 1, 9, 0,10,-1,10, 2, 2, 3, 5, 0,-1, 8, 4, 4, 4, 4, 8, 8,-1,10, 2, 0\n"
                 " 1, 7, 4, 2, 9, 5, 8, 2, 1, 9, 1, 8, 8, 0, 2,-1,-1, 5, 5, 7, 8, 4, 8, 8, 9, 5,10, 1, 6,-1\n"
                 " 0, 6, 3, 6, 7, 0, 3,10, 8, 7, 5, 0, 2, 3, 8, 8, 3, 1,-1, 7,10, 1, 5,-1,-1, 3,-1, 5, 1, 7\n"
                 " 9, 6, 4, 6, 4,10, 1, 5, 3, 8,-1,-1,-1,10,-1, 8,-1, 4, 7, 3, 4, 1, 6, 3, 7, 0, 0, 1, 4, 6\n"
                 " 4, 0, 9, 6, 7, 5, 0, 3, 0,10, 2, 9, 4, 0,-1, 3, 0, 6, 6, 3,-1, 1,10, 7,10, 8,-1,10, 0,-1\n"
                 " 6, 3, 5, 5, 9, 2, 7, 0, 5, 4, 2, 2, 8,10, 2, 6, 6, 0, 7, 4, 4, 3,-1, 9, 1,-1,10, 6,-1, 4\n"
                 " 9, 6,10, 1, 1, 8, 4, 9, 0,-1, 6, 1, 4,-1, 5, 5, 1, 3, 1, 4, 6, 5, 0, 7, 4,-1, 0, 5, 5, 4\n"
                 " 8, 4,10, 1, 2,10, 0, 1, 5, 1,-1, 6, 4, 8, 2, 3, 6, 8, 7, 7, 3, 7, 2, 6, 8, 9, 1, 0, 2, 1\n"
                 " 4, 7, 7, 6, 9, 1, 5,10, 2, 9, 9, 0, 6, 3, 6, 6, 5, 0, 8, 3, 7, 3, 5, 6, 0, 3, 6, 3, 6, 8\n"
                 " 4, 8, 9, 1, 9, 4, 6, 1, 5, 6, 7, 7, 1, 5, 9, 8, 7, 6, 6, 6, 5, 4, 8, 2, 8,-1, 2, 3, 2, 2\n"
                 " 6, 1, 7, 7, 1, 5, 2, 5, 4,10, 4, 9, 2, 4, 5, 1, 0, 7, 2, 3, 4, 4,10, 6, 5, 3, 0, 7, 0,10\n"
                 " 5, 5, 7, 5, 8, 7, 4, 6, 9, 6, 3, 9, 4, 0, 3,10, 5, 0, 2,10, 6, 4, 4, 1, 3, 0, 4,10, 1, 6\n"
                 " 8, 4, 8, 6, 2, 3, 5, 9, 5, 9, 5, 2, 8, 1, 4, 8, 4, 6, 0, 5, 9, 2, 6, 7, 7, 1,10, 8,10, 1\n"
                 " 6, 9, 5, 3, 6, 3, 0,10, 3, 8, 2, 0, 8,10, 1, 5, 5, 7, 6, 4, 7, 6, 2,10, 0, 6, 5, 1, 1, 5\n"
                 " 7, 0, 8, 3, 2, 0, 9, 9, 6, 8, 7,10, 1, 1, 5, 1, 9, 7, 7, 5, 5,10, 1, 2, 2, 3, 4, 7, 8, 2\n"
                 "10, 6, 8, 9, 2, 9, 0,10, 2, 9, 0, 3, 1, 9,10, 6,10, 7, 9, 1, 5, 9,10, 5, 0, 5, 8, 1, 1, 1\n"
                 " 1, 2, 8, 9, 9, 6,10, 7,10, 3, 2, 6, 9, 2, 8, 5, 7, 2, 6, 1, 8, 5, 1, 3, 8, 0, 2, 8, 8,10\n"
                 " 9, 8, 1,10, 2, 9,10, 2, 6, 2, 9, 8, 1, 9, 1, 8, 3, 6, 4, 1,10, 5, 8, 2, 9, 0, 2, 9, 3, 9\n"
                 " 2, 1,10, 1,10, 0, 5, 6,10, 5, 3, 7, 2,10, 6, 4,10, 6, 8, 1, 5,10, 8, 4, 0, 2, 4, 0, 9, 7\n"
                 " 2, 5, 5, 1, 9, 7, 6, 9, 4, 5, 6, 7, 1, 6, 4, 5,10, 8, 7, 1, 8, 3, 7, 7, 3, 4, 0, 2, 3, 5\n"
                 " 9, 5, 7, 5, 0, 4, 2, 8, 7, 7, 3, 2, 8, 6, 4, 3, 7, 8, 0, 4, 9, 6, 6, 1, 7, 6,10, 1,10,10\n"
                 " 9, 0, 3,10, 3, 9, 7, 5, 6, 6, 1, 2, 3, 5, 4, 8, 0, 1, 9, 5, 7, 7, 9, 0,-1, 1, 0, 4, 3,10\n"
                 " 7, 1, 1, 6, 0, 5, 6, 0, 9, 8, 3, 4,10, 5, 4, 1,10, 8, 9, 6, 5, 3, 5, 7,-1, 1, 0, 1,10,10\n"
                 " 3, 1, 0, 2, 8, 3, 5, 3, 4, 6, 9, 1, 0, 5, 3, 0, 1, 0, 6, 2,10, 9, 1, 9, 0, 6, 0, 9, 0, 4\n"
                 " 1, 7, 7, 0,10, 3, 3, 0, 3, 1, 0,10, 5, 6,10, 1, 9, 6, 6, 6, 7, 2, 9,10, 2, 0, 1, 5,10, 1\n"
                 " 0, 0, 5, 0, 6, 3, 4,10, 2, 9, 1,10, 2, 4, 9, 3, 8, 6, 0,10, 4, 2, 2, 6, 7, 4, 4, 6, 5, 3\n"
                 " 6,10, 8, 2, 9, 6, 4, 2, 4, 7, 0, 8, 9, 8, 1, 1, 5, 0, 9, 9, 7,10, 5, 1, 7, 1, 0,10, 7, 1\n"
                 " 2,-1, 9, 4, 2, 8, 1, 1, 6, 4, 1,10, 0, 1, 9,10, 4, 6, 0, 5, 9, 9, 6, 0, 6, 7, 1, 8, 6, 3\n"
                 "0,0\n"
                 "29,29\n"
                 "exit\n";


    string sep = "\n";
    string m = "1,2,3\n"
               "4,5,6\n"
               "7,8,9\n"
               "0,0\n"
               "2,2\n"
               "end\n";
    vector<string> lines = spliter.split(m,sep);//{line1_str,line2_str,line3_str,line4_str,line5_str,line6_str,line7_str,line8_str,line9_str,line10_str,line11_str,line12_str,line13_str,line14_str};

    TestIO io(lines);
    client_handler.handleClient(&io);


    delete (fcm);
    delete (b);

    return 0;
}



///////////////////////////////////////////////////////////////////////////////////
//
//#include <iostream>
//#include <string>
//
//
//#include "State.h"
//#include <set>
//#include <string>
//#include <list>
//#include "ISearcher.h"
//#include "SearchableMatrix.h"
//#include "Searcher.h"
//#include "BestFS.h"
//#include "BFS.h"
//#include "DFS.h"
//#include "Astar.h"
//#include "PathToOrders.h"
//#include "MatrixToString.h"
//#include "SearchSolver.h"
//
//using namespace std;
//
//std::vector<std::string> split(std::string &line, std::string &separator) {
//    vector<string> answer;
//    string part;
//    string c;
//    for (int i = 0; i < line.size(); ++i) {
//        c = line[i];
//        if (c == separator) {
//            if (!part.empty()) {
//                answer.push_back(part);
//            }
//            part = "";
//            continue;
//        }
//        part += line[i];
//    }
//    if (!part.empty()) {
//        answer.push_back(part);
//    }
//    return answer;
//}
//
//int main() {
//    string sep = ",";
//
//    string line1_str = "4, 2, 9, 5, 7, 0, 7, 6, 3, 7, 8";
//    string line2_str = "4, 0,10, 8, 1, 0, 5, 5, 7, 8, 4";
//    string line3_str = "4, 5, 2, 8, 1, 1, 9, 3, 3, 0, 7";
//    string line4_str = "3, 3, 6, 2, 8, 9, 6, 8, 3, 5, 7";
//    string line5_str = "0, 3, 7, 3, 7,10, 4, 8, 9, 1, 1";
//    string line6_str = "7, 3, 2, 3, 5, 0, 2, 1, 6, 0, 9";
//    string line7_str = "6, 9, 8, 1,10, 3, 9, 8, 3, 4, 8";
//    string line8_str = "10, 8, 0, 2, 3, 8, 0, 10, 10, 2, 7";
//    string line9_str = "5, 7, 0, 8, 8, 8, 0, 3, 4, 5, 1";
//    string line10_str = "7, 7, 5, 10, 8, 10, 1, 6, 9, 9, 1";
//    string line11_str = "5,10, 1,10, 7, 7, 3,10, 8, 0, 6";
//    vector<string> line1 = split(line1_str, sep);
//    vector<string> line2 = split(line2_str, sep);
//    vector<string> line3 = split(line3_str, sep);
//    vector<string> line4 = split(line4_str, sep);
//    vector<string> line5 = split(line5_str, sep);
//    vector<string> line6 = split(line6_str, sep);
//    vector<string> line7 = split(line7_str, sep);
//    vector<string> line8 = split(line8_str, sep);
//    vector<string> line9 = split(line9_str, sep);
//    vector<string> line10 = split(line10_str, sep);
//    vector<string> line11 = split(line11_str, sep);
//
//
//    vector<vector<string>> matrix = {line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11};
//    pair<int, int> enter = {0, 0};
//    pair<int, int> exit = {10, 10};
//    SearchableMatrix *mt = new SearchableMatrix(matrix, enter, exit);
//
//
//    //set the algorithm
//    ISearcher<pair<int, int>, list<State<pair<int, int>>> > *b = new DFS<pair<int, int>>;
//    //<T, list<State<T>> >
//    SearchSolver<pair<int, int>> solver(b);
////    list<State<pair<int, int> > > sol = b->search(mt);
////    cout << b->numOfNodesEvaluated() << endl;
////    cout << "////////////////////////////////////" << endl;
////
////    PathToOrders<pair<int, int>> pto;
//    vector<string> vector1 = solver.solve(mt);
//    for (string s: vector1) {
//        cout << s << endl;
//    }
//
//
//
//
//
///*
//    State<int> a = State<int>();
//    State<int> b = State<int>();
//    State<int> c = State<int>();
//    State<int> d = State<int>();
//    a.setCost(100);
//    b.setCost(4);
//    c.setCost(50);
//    d.setCost(75);
//
//    set<State<int>,CompareCost<int>> ss;
//    ss.insert(a);
//    ss.insert(b);
//    ss.insert(c);
//    ss.insert(d);
//
//    while (!ss.empty())
//    {
//        auto it = ss.begin();
//        State<int> sa = *it;
//        cout << sa.getCost() << endl;
//        ss.erase(it);
//    }
//*/
//
//    /*
//    string str = "hello";
//    StringReverser sr = StringReverser(str);
//    sr.reverseStr();
//    cout << sr.reverseStr() << endl;*/
//    return 0;
//}
//
//
//
//
//
//
//
