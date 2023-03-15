using namespace std;
#include "iostream"

#ifndef TETRIS_PIECE_H
#define TETRIS_PIECE_H


class Piece {
  
protected:
    friend class Game;
    int X;
    int Y;
    int matrix[4][4] = {{0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0} };
public:
    Piece();
    void moveDown();
    void moveRight();
    void moveLeft();
    void rotate();
    void setX(int x);
    virtual void adjust()=0;// the class is abstract 
    void intialize();
    void copy(const Piece &p);
};



class  Piece1 :public Piece {
 int rotationNumber;// the adjustment will happen only at the first rotation that's we use this variable to identify the rotation.
public:
    Piece1();
    void adjust();
};
class  Piece2 :public Piece {
public:
    Piece2();
    void adjust();
};
class  Piece3 :public Piece {
public:
    Piece3();
    void adjust();
};
class  Piece4 :public Piece {
public:
    Piece4();
    void adjust();

};
class  Piece5 :public Piece {
public:
    Piece5();
    void adjust();

};
class  Piece6 :public Piece {
public:
    Piece6();
   void adjust();
};
class  Piece7 :public Piece {
public:
    Piece7();
    void adjust();
};
#endif //TETRIS_PIECE_H
