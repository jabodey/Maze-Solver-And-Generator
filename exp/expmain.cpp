// expmain.cpp
//
// ICS 46 Spring 2017
// Project #1: Dark at the End of the Tunnel
//
// Do whatever you'd like here.  This is intended to allow you to experiment
// with the given classes in the darkmaze library, or with your own
// algorithm implementations, outside of the context of the GUI or
// Google Test.
#include <iostream>
#include <vector>
#include "Direction.hpp"
using namespace std;

int main()
{

    vector<Direction> directions;
    directions.push_back(Direction::up);
    directions.push_back(Direction::down);
    directions.push_back(Direction::left);

    vector<int> integers;
    integers.push_back(1);
    integers.push_back(5);
    integers.push_back(15);
    cout << integers[0] << endl;
    random_shuffle(integers.begin(), integers.end());
    cout << integers[0] << endl;
    random_shuffle(integers.begin(), integers.end());
    cout << integers[0] << endl;
    random_shuffle(integers.begin(), integers.end());
    cout << integers[0] << endl;
    //cout << integers.begin();
    cout << "HELLO";

    return 0;
}

