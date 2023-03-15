
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H
#include "Map.h"
#include "Piece.h"
#include <fstream>
#include <conio.h>
#include<windows.h>
#include<string>
class Game {
private:
    string playerName;
    Piece *active;
    int score;
    int numberLines;
    int NumberOfLevels;
public:   
    Game();
    bool checkCollisionDown(const Map& m, const Piece& active);
    bool checkCollisionLeft(const Map& m, const Piece& active);
    bool checkCollisionRight(const Map& m, const Piece& active);
    bool checkCollisionRotation(const Map& m, const Piece& active);
    void startGame();
    void updateMap(Map& m1);
    void waitForKey(const Map& m);
    void tempMap(const Map& m1);
    bool checkEnd(const Map& m1);
    void calculateScore(const Map& m1);
    void shiftLines(Map& m1);
 
};


#endif //TETRIS_GAME_H
