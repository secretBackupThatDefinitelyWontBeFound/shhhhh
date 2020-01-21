//
// Created by nikol on 1/9/19.
//

#ifndef GENERICSERVER_SEARCHABLEMATRIX_H
#define GENERICSERVER_SEARCHABLEMATRIX_H

#include <string>
#include <ostream>
#include "ISearchable.h"

typedef pair<int, int> intpair;


//intState represents a tile in matrix, [i,j] is the pair
class SearchableMatrix : public ISearchable<pair<int, int> > {
    std::vector<std::vector<State<pair<int, int>> *> > matrix;
    pair<int, int> start;
    pair<int, int> goal;
    int width;
    int hight;

public:
    int getWidth() const;

    int getHight() const;

    SearchableMatrix(std::vector<std::vector<std::string> > costs, pair<std::string, std::string> _start,
                     pair<std::string, std::string> _goal);

    SearchableMatrix(std::vector<std::vector<std::string> > costs, pair<int, int> start,
                     pair<int, int> goal);

    /**
     * get the State in the given position
     * @param pos - the given position
     * @return the State in a a given position
     */
    State<pair<int, int>> *get(std::pair<int, int> pos);

    State<pair<int, int>> *get(int i, int j);

    State<pair<int, int> > *getInitialState() override;

    State<pair<int, int> > *getGoalState() override;


    vector<State<pair<int, int> > *> getAllPossibleStates(State<pair<int, int>> *s) override;

    virtual ~SearchableMatrix();

    /**
     * convert the matrix to string
     * @return the matrix as string
     */
    std::string matrixToString();
//
//
//    SearchableMatrix(int size, vector<vector<int>> vec) {
//        vector<vector<State<int> > > matrix;
//        //rows
//        for (auto i: vec) {
//            //coulombs
//            for (auto j: i) {
//                //initilize state
//                State<int> s(j,)
//            }
//        }
//    }

private:
    /**
     * get all the near position of s
     * @param s - the given position
     * @return the position near s
     */
    std::vector<std::pair<int, int> > getNeighbors(std::pair<int, int> s);
};


#endif //GENERICSERVER_SEARCHABLEMATRIX_H
