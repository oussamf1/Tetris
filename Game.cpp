//
// Created by oussama on 31/03/2021.
//
#include "Game.h"
Game::Game() {
    score =0;
    numberLines;
    NumberOfLevels = 0;

}
bool Game::checkCollisionDown(const Map& m, const Piece& active1) {
    for (int j = 0; j <4 ; j++) {
        for (int i = 0; i < 4; i++) {
            if ((active->matrix[j][i] == 1) && (m.matrix[active1.Y + j + 1][active1.X + i] == 1)) {// the piece can be moved down only if it's position o
                return true;
            }
        }
    }
    return false;
}

bool Game::checkCollisionLeft(const Map& m, const Piece& active) {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {

            if ((active.matrix[i][j] == 1) && (m.matrix[active.Y + i][active.X + j - 1] == 1))// we check the column at the left if the piece can fit in it
                return true;
        }
    }
    return false;
}
bool Game::checkCollisionRight(const Map& m, const Piece& active)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j >= 0; j--) {

            if ((active.matrix[i][j] == 1) && (m.matrix[active.Y + i][active.X + j + 1] == 1))//we check the column at the right if the piece can fit in it
                return true;
        }
    }
    return false;
}
bool Game::checkCollisionRotation(const Map& m, const Piece& active)
{
    if ((typeid(active) == typeid(Piece2))) {// identifying the piece
        if (active.X < 0) {
            return true;
        }
        else {
            Piece2* temp = new Piece2();
            temp->copy(active);// copy the matrix and the coordinates of the active piece to temp
            temp->rotate();
            temp->adjust();
            for (int i = 0; i < 4; i++) {// check if the rotated piece collide with the map or not
                for (int j = 0; j < 4; j++) {

                    if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                        delete temp;
                        return true;
                    }
                        
                }
            }
            delete temp;
            return false;
        }
    }
    if ((typeid(active) == typeid(Piece5))) {
        if (active.X < 0) {
            return true;
        }
        else {
            Piece5* temp = new Piece5();
            temp->copy(active);
            temp->rotate();
            temp->adjust();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {

                    if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                        delete temp;
                        return true;
                    }
                        
                }
            }
            delete temp;
            return false;
        }
    }
    if ((typeid(active) == typeid(Piece7))) {
        if (active.X < 0) {
            return true;
        }
        else {
            Piece7* temp = new Piece7();
            temp->copy(active);
            temp->rotate();
            temp->adjust();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {

                    if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                        delete temp;
                        return true;
                    }
                        
                }
            }
            delete temp;
            return false;
        }
    }
    if (typeid(active) == typeid(Piece1)) {
        if (active.X < 1 || active.X>m.width - 5) {
            return true;
        }
        else {
            Piece1* temp = new Piece1();
            temp->copy(active);
            temp->rotate();
            temp->adjust();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {

                    if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                        delete temp;
                        return true;
                    }
                        
                }
            }
            delete temp;
            return false;

        }
    }
    if (typeid(active) == typeid(Piece3)) {

        Piece3* temp = new Piece3();
        temp->copy(active);
        temp->rotate();
        temp->adjust();
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {

                if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                    delete temp;
                    return true;
                }
                    
            }
        }
        delete temp;
        return false;
    }

    if (typeid(active) == typeid(Piece4)) {
        return true;
    }
    if (typeid(active) == typeid(Piece6)) {
        if (active.X < 0 || active.X>m.width - 5) {
            return true;
        }
        else {
            Piece6* temp = new Piece6();
            temp->copy(active);
            temp->rotate();
            temp->adjust();
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if ((temp->matrix[i][j] == 1) && (m.matrix[temp->Y + i][temp->X + j] == 1)) {
                        delete temp;
                        return true;
                    }      
                }
            }
            delete temp;
            return false;
        }
    }
}
void Game::tempMap(const Map& m1) {
    //this function will display a temporary map where the active piece can be moved
    //system("cls");// clear the console
    fflush(stdout);
    COORD cursorPosition;	
    cursorPosition.X = 0;	
    cursorPosition.Y = 0;	
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
    Map temp(m1);// copy constructor
    updateMap(temp);//place the piece in temprary map
    temp.drawMap();//draw the map 
}
bool Game::checkEnd(const Map& m1)
{
    for (int i = 1; i < m1.width - 1; i++) {// if the second row contains any filled position the game must end we do not consider the first row because all the original shape of all pieces have its first row as empty

        if (m1.matrix[1][i] == 1)
            return true;
    }
    return false;
}
void Game::calculateScore(const Map& m1)
{
    int hint;
    for (int i = 1; i < m1.height - 1; i++) {
        hint = 0;
        for (int j = 0; j < m1.width; j++) {
            if (m1.matrix[i][j] == 1)
                hint++;//if we reach the last column of matrix means it's a full line
        }
        if (hint == m1.width) {
            score += 10;
            numberLines++;
        }
    }
}
void Game::shiftLines(Map& m1)
{
    int hint;
    for (int i = 1; i < m1.height - 1; i++) {// the first row of the matrix is always empty that's why we start from 1
        hint = 0;
        for (int j = 0; j < m1.width; j++) {
            if (m1.matrix[i][j] == 1)
                hint++;
        }
        if (hint == m1.width) {// means that we found a full line
            for (int k = 1; k < m1.width - 1; k++) {
                m1.matrix[i][k] = 0;//we empty the full line 
            }
            for (int n = i; n > 0; n--) {// n is the order of the full line starting from the row above it we start shifting the positions down.
                for (int m = 1; m < m1.width - 1; m++) {
                    m1.matrix[n][m] = m1.matrix[n - 1][m];// The nth row is empty so it will receive the row above it and the process goes on.
                }
            }
        }

    }

}


void Game::updateMap(Map& m1) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (active->matrix[i][j] == 1) {
                m1.matrix[active->Y + i][active->X + j] = active->matrix[i][j];// for the matrix of the first piece , it's first and last row are always free
            }
        }
    }
}
void Game::waitForKey(const Map& m) {

    if ( _kbhit()) {
        int c = 0;

        switch ((c = _getch())) {
        case 80:
            if (!checkCollisionDown(m, *active)) {//if there is no collision the piece can move
                active->moveDown();
            }
            break;
 
        case 72:
            if (!checkCollisionRotation(m, *active)) {//if there is no collision the piece can rotate
                    active->rotate();
                  active->adjust();
           
            }
            break;
        case 75:
            if (!checkCollisionLeft(m, *active)) {
            
                active->moveLeft();
            }
            break;
        case 77:
            if (!checkCollisionRight(m, *active)) {
               
                active->moveRight();
            }
            break;
        default:
            break;
        }
    }
}
void Game::startGame() {
    int i = 0;// the integer i will be incremented at every level to extend the map
    score = 0;
    int currentLevel=1;
    std::ofstream data;
    cout << "enter the number of levels" << endl;
    try {
        cin >> NumberOfLevels;
        if (cin.fail() || (NumberOfLevels <= 0 || NumberOfLevels>5))
            throw 1;
    }
    catch (int e) {
        cout << "please open the game again and choose a number between 1 and 5" << endl;
        exit(1);
    }
    cout << "enter the player name" << endl;
    cin >> playerName;
    system("cls");//clear the console after displaying the menu and before starting the game
    do   {
        numberLines = 0;
        Map *m= new Map((i+4) + 10, 20+ (i*4));//size of the map will increment everytime by i*4 at each level
        m->initialize();
        while (!checkEnd(*m)) {
            srand((unsigned)time(NULL));
            int random = rand() % 7 + 1;//select a random piece
            switch (random) {
            case 1:
                active = new Piece1();
                break;
            case 2:
                active = new Piece2();
                break;
            case 3:
                active = new Piece3();
            case 4:
                active = new Piece4();
                break;
            case 5:
                active = new Piece5();
                break;
            case 6:
                active = new Piece6();
                break;
            case 7:
                active = new Piece7();
                break;
            default:
                break;
            }
            active->setX((m->width - 2) / 2);// to spawn the piece in the midlle of the map
            while (!checkCollisionDown(*m, *active)) {//here a loop that allow the player to move the active piece until a collision down is detected
                waitForKey(*m);
                tempMap(*m);
            }
            updateMap(*m);//when a collision of the piece and the map is detected the matrix coordinates will be updated
            calculateScore(*m);// every time we place a piece we check if there is full lines and update the score
            shiftLines(*m);// shift lines down also
            delete active;
        }
        system("cls");
        m->drawMap();
        cout << "The score is " << score << endl;
        i++;// increment i to extend the map
        currentLevel++;
        delete m;
    } while (numberLines >=5 &&currentLevel<= NumberOfLevels);
    
    data.open("data.txt", std::ios_base::app); 
    data <<" Player Name: "<<playerName<<" Score: " << score << " Number of Levels: " << NumberOfLevels;
    data << endl;
}





  
   
    
   



