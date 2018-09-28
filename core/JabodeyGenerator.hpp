#include "MazeGenerator.hpp"
#include "Maze.hpp"
#include <vector>
using namespace std;

class JabodeyGenerator : public MazeGenerator
{
private:

public:
void generateMaze(Maze& maze);
void generatePath(int x, int y, Maze& maze, vector<vector<bool>>& m);
JabodeyGenerator();

};
