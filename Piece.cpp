
#include "Piece.h"
Piece::Piece() {
    Y = 0;
    X = 0;
}
void Piece::setX(int x)
{
    X = x;
}
void Piece::intialize()// set The matrix to zeros at all positions
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
}
void Piece::copy(const Piece& p)// function that will copy the content of a piece to another one
{
    this->X = p.X;
    this->Y = p.Y;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = p.matrix[i][j];
        }
    }
}

void Piece::moveDown() {
    Y++;
}
void Piece::moveLeft() {

    X--;
}
void Piece::moveRight() {
    X++;
}
void Piece::rotate() {
    int temp[4][4];
    for (int i = 0 ,k = 3; i < 4; i++,k--)
        for (int j = 0,z=0; j < 4; j++,z++) {
            {
                temp[z][k] = matrix[i][j];
            }
        }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = temp[i][j];
        }
    }
}
Piece1::Piece1() {// defining the shape of the first piece ****
    rotationNumber = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == 1)
                matrix[i][j] = 1;
        }
    }
}
void Piece1::adjust() {
    // the adjustment will be done only when we are rotating from the horizontal format to the vertical one
    /*
    horizontal format : rotationNumber=1
    veritcal format :   rotationNumber=2
    */
    rotationNumber++;
    if (rotationNumber == 1) {
        for (int i = 0; i < 4; i++) {
            matrix[i][1] = 1;
            matrix[i][2] = 0;
        }
    }
    if (rotationNumber == 2) {
        rotationNumber = 0;
    }
}

Piece2::Piece2() { 
/*
          shape:    *      
                   ***
*/
    for (int i = 1; i < 4; i++) {
        matrix[2][i] = 1;
    }
    matrix[1][2] = 1;
}
void Piece2::adjust()// shift the shape to the right by one coordinate
{
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >0; j--) {
            matrix[i][j] = matrix[i][j - 1];
            matrix[i][j - 1] = 0;
        }
    }
   
}
Piece3::Piece3() { 
    /*         **
        shape : **            
     */
    matrix[1][0] = 1;
    matrix[1][1] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
}

void Piece3::adjust()// shift the shape down by one coordinate
{
    for (int i = 3; i >=1; i--) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = matrix[i - 1][j];
            matrix[i - 1][j] = 0;
        }
    }
}

Piece4::Piece4() {
    /*
          shape: **
                 **
    */
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
}
void Piece4::adjust()// no adjustment will be done for piece 4 becuase it won't be rotated
{
    cout << " " << endl;
}
Piece5::Piece5() {
    /*
          *
          *** 
     */
    matrix[1][1] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
}
void Piece5::adjust()// shift the shape to the right by one coordinate
{
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
            matrix[i][j - 1] = 0;
        }
    }
}
Piece6::Piece6() {
    /*
             *
    shape: *** 
    */
    
    matrix[2][1] = 1;
    matrix[2][2] = 1;
    matrix[2][3] = 1;
    matrix[1][3] = 1;
}
void Piece6::adjust()// shift the shape to the right by one coordinate
{
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            matrix[i][j] = matrix[i][j - 1];
            matrix[i][j - 1] = 0;
        }
    }
}
Piece7::Piece7() {

    /*        **
      shape: **
      */
    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[1][1] = 1;
    matrix[1][2] = 1;
}

void Piece7::adjust()// shift the shape down by one coordinate
{
    for (int i = 3; i >= 1; i--) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = matrix[i - 1][j];
            matrix[i - 1][j] = 0;
        }
    }
}
