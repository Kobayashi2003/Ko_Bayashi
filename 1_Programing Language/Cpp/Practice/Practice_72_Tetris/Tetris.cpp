#include "Tetris.h"

void Tetris::initDescription() { // done
    gameName = "Tetris";
    gameVersion = "1.0";
    gameAuthor = "KOBAYASHI";
}

void Tetris::showDescription() { // done
    std::cout << "Game Name: " << gameName << std::endl;
    std::cout << "Game Version: " << gameVersion << std::endl;
    std::cout << "Game Author: " << gameAuthor << std::endl;
}


Tetris::Tetris(int rows, int cols, int leftMargin, int topMargin, int blockSize)  { // done
    this->rows = rows;
    this->cols = cols;
    this->leftMargin = leftMargin;
    this->topMargin = topMargin;
    this->blockSize = blockSize;
}

Tetris::~Tetris() { // done
    delete curBlock;
    delete nextBlock;
}


void Tetris::play() {
    init();
    
    // create the first block
    nextBlock = new Block();
    curBlock = nextBlock;
    nextBlock = new Block();
    createPreBlock();

    startTime = clock();
    // create a new thread to update the current time and the game time
    std::thread t_time(&Tetris::updateTimer, this);

    // create a new thread to control the key event
    auto KeyEvent = [&]() {
        while (gameStart) {
            pause();
            keyEvent();
        }
    };
    std::thread t_key(KeyEvent);
    
    // create a new thread to control the drop of the block
    auto DropBlock = [&]() {
        while (gameStart) {
            pause();
            keyEvent();
            std::this_thread::sleep_for(std::chrono::milliseconds(curSpeed - speedUp));
            drop();
        }
    };
    std::thread t_drop(DropBlock);

    // create a new thread to control the preview of the block
    auto CreatePreBlock = [&]() {
        while (gameStart) {
            pause();
            droopLock = false;
            int c_0col = curBlock->getPoints()[0].col;
            int p_0col = preBlock.getPoints()[0].col;
            int c_3col = curBlock->getPoints()[3].col;
            int p_3col = preBlock.getPoints()[3].col;

            if (preBlock.checkCollision(board) || c_0col != p_0col || c_3col != p_3col) {
                createPreBlock();
            }
            droopLock = true;
        }
    };
    std::thread t_pre(CreatePreBlock);

    // the main loop of the game, mainly used to check the update flags and game state flags
    for (; gameStart; delay_fps(60)) {
        if (updateWindowFlag) {
            tetrisInTerminal();
            updateWindow();
            updateWindowFlag = false;
        }
        if (updateScoreLevelFlag) {
            updateScore();
            updateLevel();
            updateScoreLevelFlag = false;
        }
       
        if (gamePause) {
            std::cout << "Press 'P' to continue the game" << std::endl;
            // pause the game
            while (gamePause) {
                keyEvent();
            }
        }

        if (gameOver) {
            std::cout << "gameOver" << std::endl;
            gameStart = false;
            // release the resources
            t_time.detach();
            t_key.detach();
            t_drop.detach();
            t_pre.detach();
        }
    }
}

void Tetris::init() {
    // set the random seed
    srand((unsigned)time(nullptr));
    curBlock = nullptr;
    nextBlock = nullptr;

    // load the bgm
    

    // load the background image

    // load the block images
    // imgsBlock = Block::getImgs();

    // load the game over image

    // load the game win image

    // init the board
    clearBoard();

    // init the game state flags
    gameStart = true;
    gameOver = false;
    gamePause = false;
    gameWin = false;

    // init the function flags
    updateWindowFlag = false;
    updateScoreLevelFlag = false;

    eliminatedLines = 0;
    combo = 0;
    score = 0;
    curLevel = EASY;
    curSpeed = speed[curLevel];
    speedUp = 0;

    top10Scores = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    // load the top 10 scores from file top10Scores.txt
    std::ifstream fin;
    fin.open("top10Scores.txt");
    if (!fin.is_open()) {
        // if the file does not exist, then create a new file
        std::ofstream fout;
        fout.open("top10Scores.txt");
        for (int i = 0; i < 10; ++i) {
            fout << 0 << std::endl;
        }
    } else {
        // if the file exists, then load the top 10 scores
        for (int i = 0; i < 10; ++i) {
            fin >> top10Scores[i];
        }
    }
    fin.close();
}

void Tetris::pause() {
    while (gamePause) { /*blank run*/ }
}

void Tetris::clearBoard() { // done
    // clear all the elements in the Board
    board.clear();
    // reset the Board
    for (int i = 0; i < rows; ++i) {
        std::vector <int> one_row;
        for (int j = 0; j < cols; ++j) {
            one_row.push_back(EMPTY);
        }
        board.push_back(one_row);
    }
} 

void Tetris::createBlock() { // done
    delete curBlock;
    curBlock = nextBlock;
    nextBlock = new Block();
    // randomly move the block to the left or right
    int move = rand() % (cols - 2 + 1);
    curBlock->moveLeftRight(move);
}

void Tetris::createPreBlock() { // Done
    Block tmpBlock;
    preBlock = *curBlock;
    while (!preBlock.checkCollision(board)) {
        tmpBlock = preBlock;
        preBlock.drop();
    }
    preBlock = tmpBlock;
}

void Tetris::clearLine() { // done
    // this function will check the board from the bottom to the top
    for (int i = rows-1, k = rows-1; i >= 0; --i) {
        // check if all the elements in the line are not -1
        if (std::find(board[i].begin(), board[i].end(), EMPTY) == board[i].end()) {
            // if all this line is full, then ignore this line
            eliminatedLines += 1;
            combo += 1;
            updateScoreLevelFlag = true;
            continue;
        }
        board[k--] = board[i];
    }
}

void Tetris::updateScore() { // done
    // the score update is based on the combo 
    // Rule: 1 combo ~ 2 combo 100 Points per line
    //       3 combo ~ 4 combo 200 Points per line
    //       5 combo ~ more 400 Points per line
    if (combo >= 1 && combo <= 2) { 
        score += 100 * combo;
    } else if (combo >= 3 && combo <= 4) {
        score += 200 * combo;
    } else if (combo >= 5) {
        score += 400 * combo;
    }
    combo = 0;
}

void Tetris::updateLevel() { // done
    // the level update is based on the score
    if (score < levelScore[0]) {
        curLevel = EASY;
    } else if (score < levelScore[1]) {
        curLevel = NORMAL;
    } else if (score < levelScore[2]) {
        curLevel = HARD;
    } else if (score < levelScore[3]) {
        curLevel = EXPERT;
    } else if (score < levelScore[4]) {
        curLevel = HELL;
    } else {
        gameOver = true;
    }
}

void Tetris::updateTimer() { // done
    // update the current time and the game time
    for (; gameStart; delay_fps(60)) {
        curTime = clock();
        gameTime = (curTime - startTime) / 1000;
    }
}

void Tetris::delay_fps(int fps) { // done
    // convert fps to delay
    std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps)); // delay 1/fps seconds, 1000ms = 1s, 1s/fps = 1/fps seconds
}

void Tetris::updateWindow() { // TODO

}

void Tetris::checkGameOver() { // done
    // if the new block is not valid, then the game is over
    gameOver = curBlock->checkCollision(board);
}

void Tetris::keyEvent() { // Done
    // Direction key
    // up: u_char key = 224; key = 72;
    //     stand for rotate the block
    // down: u_char key = 224; key = 80;
    //       stand for speed up the block to the bottom (curSpeed / 2)
    // left: u_char key = 224; key = 75;
    //       stand for move the block to the left
    // right: u_char key = 224; key = 77;
    //        stand for move the block to the right

    // additional rules:
    // 'w' is the same as 'up', 'a' is the same as 'left', 'd' is the same as 'right', 's' is the same as 'down'
    // if 'space' is pressed, the block will be moved to the bottom
    // if 'p' is pressed, the game will be paused or resumed 
    // if 'q' is pressed, the game will be over

    unsigned char key = '\0';
    bool rotateFlag = false;
    bool speedUpFlag = false;
    bool droopFlag = false;
    int dx = 0;

    clock_t pressTime = clock();
	if (_kbhit()) {
		key = _getch();
        pressTime = clock();
		if (key == 224) {
			key = _getch();
			switch (key) {
			case 72: rotateFlag = true;  break;
			case 80: speedUpFlag = true; break;
			case 75: dx = -1; break;
			case 77: dx = 1;  break;
			default: break;
			}
		}
		else {
			switch (key) {
			case 'w': case 'W': rotateFlag = true;  break;
			case 's': case 'S': speedUpFlag = true; break;
			case 'a': case 'A': dx = -1; break;
			case 'd': case 'D': dx = 1;  break;
			case 'p': case 'P': gamePause = !gamePause; break;
			case ' ': droopFlag = true; break;
            case 'q': case 'Q': gameOver = true; break;
			default: break;
			}
		}
	}
    else {
        // if the key is not pressed, then the speed will be set to the normal speed
        if (clock() - pressTime > 1) {
            speedUp = 0;
        }
    }

    if (gamePause || gameOver ) {
        return;
    }

	if (rotateFlag) {
		rotate();
		rotateFlag = false;
	}

	if (speedUpFlag) {
		speedUp = curSpeed / 2;
		speedUpFlag = false;
	}

	if (droopFlag) {
        droop();
		droopFlag = false;
	}

	if (dx != 0) {
		moveLeftRight(dx);
		dx = 0;
	}

}

void Tetris::drop() { // done
    bakBlock = *curBlock;
    curBlock->drop();
    if (checkCollision()) {
        bakBlock.solidify(board);
        clearLine();
        createBlock();
    }
    checkGameOver();
    updateWindowFlag = true;
}

void Tetris::droop() { // Done
    while (!droopLock) {/* blank */} // blank run, wait for the complete of preBlock
    Block* oldBlock = curBlock;
    Block* droopBlock = new Block();
    *droopBlock = preBlock;
    curBlock = droopBlock;
    delete oldBlock;
}

void Tetris::moveLeftRight(int direction) { // done
    bakBlock = *curBlock;
    curBlock->moveLeftRight(direction);
    if (checkCollision()) {
        *curBlock = bakBlock;
    }
    updateWindowFlag = true;
}

void Tetris::rotate() { // done
    if (curBlock->getType() == 6) {
        return;
    }
    bakBlock = *curBlock;
    curBlock->rotate();
    if (checkCollision()) {
        *curBlock = bakBlock;
    }
    updateWindowFlag = true;
}

bool Tetris::checkCollision() { // Done
    return curBlock->checkCollision(board);
}

void Tetris::tetrisInTerminal() { // Done
    Point* blockPoints = curBlock->getPoints();

    system("cls");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool hasBlock = false;
            for (int k = 0; k < 4; ++k) {
                if (i == blockPoints[k].row && j == blockPoints[k].col) {
                    hasBlock = true;
                }
            }
            if (hasBlock) {
                std::cout << curBlock->getType();
                continue;
            }
            bool hasPreBlock = false;
            for (int k = 0; k < 4; ++k) {
                if (i == preBlock.getPoints()[k].row && j == preBlock.getPoints()[k].col) {
                    hasPreBlock = true;
                }
            }
            if (hasPreBlock) {
                std::cout << "@";
                continue;
            }
            if (board[i][j] == EMPTY) {
                std::cout << "¡¤";
                continue;
            }
            std::cout << board[i][j];
        }
        int nextType = nextBlock->getType();
        if (i == 1) {
            std::cout << "\t\t";
            switch (nextType) {
            default:
                std::cout << " " << 0 << " ";
                break;
            }
            switch (nextType) {
            case 0: 
                std::cout << "[" << 1 << "]"; break;
            default:
                std::cout << " " << 1 << " "; break;
            }
        }
        else if (i == 2) {
            std::cout << "\t\t";
            switch (nextType) {
            case 1: case 4: case 6:
                std::cout << "[" << 2 << "]"; break;
            default:
                std::cout << " " << 2 << " "; break;
            }
            switch (nextType) {
            case 0: case 2: case 3: case 4: case 5: case 6:
                std::cout << "[" << 3 << "]"; break;
            default:
                std::cout << " " << 3 << " "; break;
            }
        }
        else if (i == 3) {
            std::cout << "\t\t";
            switch (nextType) {
            case 1: case 2: case 3: case 6:
                std::cout << "[" << 4 << "]"; break;
            default:
                std::cout << " " << 4 << " "; break;
            }
            switch (nextType) {
            case 0: case 1: case 2: case 3: case 4: case 5: case 6:
                std::cout << "[" << 5 << "]"; break;
            default:
                std::cout << " " << 5 << " "; break;
            }
        }
        else if (i == 4) {
            std::cout << "\t\t";
            switch (nextType) {
            case 2: case 5:
                std::cout << "[" << 6 << "]"; break;
            default:
                std::cout << " " << 6 << " "; break;
            }
            switch (nextType) {
            case 0: case 1: case 3: case 4: case 5:
                std::cout << "[" << 7 << "]"; break;
            default:
                std::cout << " " << 7 << " "; break;
            }
        }
        else if (i == 7) {
            std::cout << "\t\tscore: " << score;
        }
        else if (i == 8) {
            std::cout << "\t\tlevel: " << curLevel;
        }
        else if (i == 9) {
            std::cout << "\t\tTime: " << gameTime;
        }
        else if (i == 10) {
            std::cout << "\t\tSpeed: " << curSpeed;
        }
        std::cout << std::endl;
    }

    std::cout << "\n\n\
    'A' 'LEFT' move left\n\
    'D' 'RIGHT' move right\n\
    'W' 'UP' rotate\n\
    'S' 'DOWN' drop speedup\n\
    'SPACE' droop\n\
    'P' pause\n\
    'Q' 'ESC' quit\n";
}
