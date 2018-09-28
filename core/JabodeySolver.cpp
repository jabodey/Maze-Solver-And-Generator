#include "JabodeySolver.hpp"
#include "Maze.hpp"
#include "MazeSolution.hpp"
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <ics46/factory/DynamicFactory.hpp>
using namespace std;

ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, JabodeySolver, "JabodeySolver (Required)");


void JabodeySolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution)
{
vector<vector<bool>> m(maze.getHeight(), vector<bool>(maze.getWidth()));
for (int i = 0; i < maze.getHeight(); ++i)
    for (int j = 0; j < maze.getWidth(); ++j)
        m[i][j] = false;

generatePath(0, 0, maze, mazeSolution, m);
}

void JabodeySolver::generatePath(int x, int y, const Maze& maze, MazeSolution& mazeSolution, 
                                vector<vector<bool>>& m)
{
if (mazeSolution.isComplete() == true)
    return;
m[x][y] = true;
vector<Direction> directions = generateDirections(x, y, maze, m);

while(directions.size() > 0)
{
if (mazeSolution.isComplete() == true)
    return;
random_shuffle(directions.begin(), directions.end());
Direction newMove = directions[0];
int newX = x;
int newY = y;
mazeSolution.extend(newMove);
if (newMove == Direction::right)
    newX++;
if (newMove == Direction::left)
    newX--;
if (newMove == Direction::down)
    newY++;
if (newMove == Direction::up)
    newY--;
generatePath(newX, newY, maze, mazeSolution, m);
vector<Direction> directions = generateDirections(x, y, maze, m);
}

if (directions.size() == 0)
    {
    mazeSolution.backUp();
    x = mazeSolution.getCurrentCell().first;
    y = mazeSolution.getCurrentCell().second;
    generatePath(x, y, maze, mazeSolution, m);
    }
}


vector<Direction> JabodeySolver::generateDirections(int x, int y, const Maze& maze, vector<vector<bool>> &m)
{
vector<Direction> directions;
if((x+1) < maze.getWidth())
    if (!maze.wallExists(x,y, Direction::right))
        if (m[x+1][y] == false)
            directions.push_back(Direction::right);
if((x-1) >= 0)
    if(!maze.wallExists(x, y, Direction::left))
        if (m[x-1][y] == false)
            directions.push_back(Direction::left);
if((y+1) < maze.getHeight())
    if(!maze.wallExists(x, y, Direction::down))
        if(m[x][y+1] == false)
            directions.push_back(Direction::down);
if((y-1) >= 0)
    if(!maze.wallExists(x, y, Direction::up))
        if(m[x][y-1] == false)
            directions.push_back(Direction::up);

return directions;
}
