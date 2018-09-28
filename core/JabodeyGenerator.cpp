#include <ics46/factory/DynamicFactory.hpp>
#include "JabodeyGenerator.hpp"
#include "Direction.hpp"
#include <iostream>
#include <vector>
#include <random>
using namespace std;

ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, JabodeyGenerator, "Jabodey's Algorithm (Required)");

JabodeyGenerator::JabodeyGenerator()
{
}

void JabodeyGenerator::generateMaze(Maze& maze)
{
maze.addAllWalls();

vector<vector<bool>> m(maze.getHeight(), vector<bool>(maze.getWidth()));
for (int i = 0; i < maze.getHeight(); ++i)
    for (int j = 0; j < maze.getWidth(); ++j)
        m[i][j] = false;

generatePath(0, 0, maze, m);
}

void JabodeyGenerator::generatePath(int x, int y, Maze& maze, vector<vector<bool>>& m)
{
m[x][y] = true;
vector<Direction> directions;
if ((x+1) < maze.getWidth()) 
    if (m[x+1][y] == false)
        directions.push_back(Direction::right);
if ((x-1) >= 0) 
    if (m[x-1][y] == false)
        directions.push_back(Direction::left);
if ((y+1) < maze.getHeight()) 
    if (m[x][y+1] == false)
        directions.push_back(Direction::down);
if ((y-1) >= 0) 
    if (m[x][y-1] == false)
        directions.push_back(Direction::up);

while (directions.size() > 0)
{
random_shuffle(directions.begin(), directions.end());
Direction newMove = directions[0];
maze.removeWall(x,y,newMove);
int newX = x;
int newY = y;
if (newMove == Direction::right)
    newX++;
if (newMove == Direction::left)
    newX--;
if (newMove == Direction::down)
    newY++;
if (newMove == Direction::up)
    newY--;      
generatePath(newX, newY, maze, m);
vector<Direction> newDirections;
if ((x+1) < maze.getWidth())
    if (m[x+1][y] == false)
        newDirections.push_back(Direction::right);

if ((x-1) >= 0)
    if (m[x-1][y] == false)
        newDirections.push_back(Direction::left);
                                       
if ((y+1) < maze.getHeight())
    if (m[x][y+1] == false)
        newDirections.push_back(Direction::down);
       
if ((y-1) >= 0)
    if (m[x][y-1] == false)
        newDirections.push_back(Direction::up);
directions = newDirections;
}
}

