

#include "Map.h"

Map::Map(int Height, int Width) {
    width = Width;
    height = Height;
    matrix = new int* [height];// allocaing  integer pointers .
    for (int i = 0; i < height; i++) {
        matrix[i] = new int[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = 0;// initializing the 2D array of integers
        }
    }
}
void Map::initialize() {
    for (int i = 0; i < height; i++) {// Left wall
        matrix[i][0] = 1;
    }
    for (int i = 0; i < height; i++) {// Right wall
        matrix[i][width - 1] = 1;
    }
    for (int j = 0; j < width; j++) {//bottom wall
        matrix[height - 1][j] = 1;
    }
}
void Map::drawMap()
{
    for (int i = 1; i < this->height; i++) { // we start draw the matrix from second row because for  all pieces when they are first respawned the first row will be empty. 
        for (int j = 0; j < this->width; j++) {
            if ((j == 0) || (j == this->width - 1) || (i == this->height - 1)) {//identify the borders of the matrix and print them differently
                cout << '#';
            }
            else if (this->matrix[i][j] == 1) {
                cout << '*';

            }

            else {
                cout << ' ';
            }
        }
        cout << endl;
    }
}
Map::~Map() {
    for (int i = 0; i < height; i++) {
        delete[]matrix[i];
    }
    delete[] matrix;
}

Map::Map(const Map& old) {
    width = old.width;
    height = old.height;
    matrix = new int* [height];// allocaing  integer pointers .
    for (int i = 0; i < height; i++) {
        matrix[i] = new int[width];
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = old.matrix[i][j];// coppying the 2D array of integers
        }
    }
}
