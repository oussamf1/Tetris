
#ifndef TETRIS_MAP_H
#define TETRIS_MAP_H
#include "iostream"
using namespace std;

class Map {
private:
    int width;
    int height;
    int** matrix;
    friend class Game;
public:
    Map(int Height, int Width);
    Map(const Map& old);
    void initialize();
    void drawMap();
    ~Map();
};
#endif //TETRIS_MAP_H
