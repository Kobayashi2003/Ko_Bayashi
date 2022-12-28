#include "Block.h"
#include "Game.h"

#include <vector>
#include <algorithm>

#include <ctime>
#include <cstdlib>

#include <conio.h>

#include <iostream>
#include <fstream>

#include <thread>
#include <chrono>

// for playing music
// #include <mmsystem.h>
// #pragma comment(lib, "winmm.lib")

// Graphic library
// #include <graphics.h>


template <typename T>
using vv = std::vector<std::vector<T>>;

class Tetris : public Game {
public:

    virtual void showDescription();

    // rows, cols are the number of the rows and columns of the game board
    // leftMargin, topMargin are the left and top margin of the game board
    // blockSize is the width of each block
    // all the above parameters determine the size of the game board, the block will be drawn in this area
    Tetris(int rows, int cols, int leftMargin, int topMargin, int blockSize);
    ~Tetris();

    // play function is the main function of the game, it will be called in the main function
    void play();

private:

    virtual void initDescription();

    // init function is used to initialize the data members of the class
    void init();
    // pause function is used to pause the program
    void pause();
    // clearBoard function is used to initialize the game board
    void clearBoard();
    // createBlock function is used to create a new block on the top of the game board randomly
    void createBlock();
    // preBlock function is used to preview where the curblock will be dropped
    void createPreBlock();
    // clearLine function is used to eliminate the lines that have been filled
    void clearLine();
    // updateScore function and updateLevel function are used to update the score and level
    void updateScore();
    void updateLevel();
    // updateTimer function is used to update the current time and the game time
    void updateTimer();
    // delay_fps function is used to control the fps of the game
    void delay_fps(int fps);
    void updateWindow();

    // keyEvent function responds to the keyboard events, and the other functions are used to control the curblock
    void keyEvent();
    // void drop();
    void drop();
    void droop();
    void moveLeftRight(int direction);
    void rotate();

    // checkCollision function is used to check whether the movement of the curblock is valid,
    // such as whether the curblock is out of the game board, whether the curblock collides with other blocks
    bool checkCollision();
    // checkGameOver function will  judge whether the game is over by check whether the newly generated block collides with other blocks
    void checkGameOver();

    void tetrisInTerminal();

private:

    int rows;
    int cols;
    int leftMargin;
    int topMargin;
    int blockSize;
    // IMAGE imgBg;
    // IMAGE **imgsBlock;
    const char *imgBgPath = "res/bg2.png";
    const char *musicBgCmd = "play res/bg.mp3";

    Block* curBlock;
    Block* nextBlock;
    Block bakBlock;
    Block preBlock;

    // the game board
    // -1 means no block
    // 0-6 means the type of the block
    // when the block is dropped, the corresponding element in the board will be set to the type of the block
    const int EMPTY = -1;
    vv<int> board;

    bool gameStart;
    bool gameOver;
    bool gamePause;
    time_t startTime;
    time_t curTime;
    time_t gameTime;
    time_t endTime;
    bool gameWin;
    // IMAGE imgGameLose;
    // IMAGE imgGameWin;
    const char *imgGameLosePath = "res/over.png";
    const char *imgGameWinPath = "res/win.png";
    const char *musicGameLoseCmd = "play res/over.mp3";
    const char *musicGameWinCmd = "play res/win.mp3";

    // if the window needs to be updated, updateWindowFlag will be set to true
    bool updateWindowFlag;
    bool updateScoreLevelFlag;

    // eliminatedLines is the number of lines that have been eliminated in this round
    int eliminatedLines;
    // combo is the number of lines that have been eliminated continuously
    int combo;
    // Rule: 1 combo ~ 2 combo 100 Points per line
    //       3 combo ~ 4 combo 200 Points per line
    //       5 combo ~ more 400 Points per line
    int score;
    // the level, the sore required to reach the next level, and the falling speed of corresponding level
    // if all the levels are passed, then win the game
    enum level { EASY, NORMAL, HARD, EXPERT, HELL };
    const int levelScore[5] = { 1000, 2000, 4000, 8000, 12000 };
    int curLevel;
    const int speed[5] = { 500, 300, 150, 100, 80 }; // ms
    int curSpeed; // mainly used to control the falling speed of the block
    // the top 10 scores
    int speedUp;
    std::vector<int> top10Scores;

    bool droopLock;
};