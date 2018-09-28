#include "MazeSolver.hpp"
#include "Maze.hpp"
#include "MazeSolution.hpp"
#include <iostream>
#include <vector>
using namespace std;

class JabodeySolver: public MazeSolver
{
private:
public: 
vector<Direction> generateDirections(int x, int y,const  Maze& maze, vector<vector<bool>>& m);
void generatePath(int x, int y, const Maze& maze, MazeSolution& mazeSolution, vector<vector<bool>>& m);
void solveMaze(const Maze& maze, MazeSolution& mazeSolution);
}
;
