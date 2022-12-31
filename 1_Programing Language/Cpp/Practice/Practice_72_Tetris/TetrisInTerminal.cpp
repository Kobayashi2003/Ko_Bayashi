#include "TetrisInTerminal.h"


using TiT = TetrisInTerminal;

TiT::TetrisInTerminal(int rows, int cols) : Tetris(rows, cols) {}

TiT::TetrisInTerminal() : TetrisInTerminal(20, 10) {}


void TiT::updateWindowFunc() {
    // clear the screen 
    std::cout << "\033[2J\033[1;1H"; // system("cls");

    curBlockPoints = curBlock->getPoints();
    preBlockPoints = preBlock.getPoints();
    nextBlockType = nextBlock->getType();

    // travel the board and print the blocks
    for (int row = 0; row < rows; ++row) {
        // show the board
        for (int col = 0; col < cols; ++col) {
            bool haveCur = haveCurBlock(row, col);
            bool havePre = havePreBlock(row, col);
            if (showCurBlock && haveCur) {
                if (COLOR) {
                    color(std::string("") + curBlock_icons[curBlock->getType()], curBlock->getType());
                } else {
                    std::cout << curBlock->getType();
                }
            } else if (showCurBlock && havePre) {
                if (COLOR) {
                    color(std::string("") + preBlock_icon, preBlock.getType());
                } else {
                    std::cout << preBlock_icon;
                }
            } else {
                if (showBackground && board[row][col] == EMPTY) {
                    if (COLOR) {
                        color(std::string("") + background_icon, -1);
                    } else {
                        std::cout << background_icon;
                    }
                } else if (showSolidBlock && board[row][col] != EMPTY) {
                    if (COLOR) {
                        color(std::string("") + curBlock_icons[board[row][col]], board[row][col]);
                    } else {
                        std::cout << board[row][col];
                    }
                }
            }
        }

        // show the next block
        if (showNextBlock) {
            if (row == 0) {
                std::cout << "\t\tNext Block:";
            }
            else if (row == 1) {
                std::cout << "\t\t";
                switch (nextBlockType) {
                default:
                    std::cout << " " << 0 << " ";
                    break;
                }
                switch (nextBlockType) {
                case 0: 
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "1";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 1 << "]"; break;
                default:
                    std::cout << " " << 1 << " "; break;
                }
            }
            else if (row == 2) {
                std::cout << "\t\t";
                switch (nextBlockType) {
                case 1: case 4: case 6:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "2";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 2 << "]"; break;
                default:
                    std::cout << " " << 2 << " "; break;
                }
                switch (nextBlockType) {
                case 0: case 2: case 3: case 4: case 5: case 6:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "3";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 3 << "]"; break;
                default:
                    std::cout << " " << 3 << " "; break;
                }
            }
            else if (row == 3) {
                std::cout << "\t\t";
                switch (nextBlockType) {
                case 1: case 2: case 3: case 6:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "4";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 4 << "]"; break;
                default:
                    std::cout << " " << 4 << " "; break;
                }
                switch (nextBlockType) {
                case 0: case 1: case 2: case 3: case 4: case 5: case 6:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "5";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 5 << "]"; break;
                default:
                    std::cout << " " << 5 << " "; break;
                }
            }
            else if (row == 4) {
                std::cout << "\t\t";
                switch (nextBlockType) {
                case 2: case 5:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "6";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 6 << "]"; break;
                default:
                    std::cout << " " << 6 << " "; break;
                }
                switch (nextBlockType) {
                case 0: case 1: case 3: case 4: case 5:
                    if (COLOR) {
                        color("[", nextBlockType);
                        std::cout << "7";
                        color("]", nextBlockType);
                        break;
                    }
                    std::cout << "[" << 7 << "]"; break;
                default:
                    std::cout << " " << 7 << " "; break;
                }
            }
        }

        // show the score, level, time, speed
        else if (showScore && row == 7) {
            std::cout << "\t\tScore: " << score;
        }
        else if (showLevel && row == 8) {
            std::cout << "\t\tLevel: " << curLevel;
        }
        else if (showTime && row == 9) {
            std::cout << "\t\tTime: " << gameTime;  
        }
        else if (showSpeed && row == 10) {
            std::cout << "\t\tSpeed: " << speed;
        }
        std::cout << std::endl;
    }
    
    // show the help
    if (showHelp) {
        std::cout << "\n\n\
        \t\t'A' 'LEFT' move left\n\
        \t\t'D' 'RIGHT' move right\n\
        \t\t'W' 'UP' rotate\n\
        \t\t'S' 'DOWN' drop speedup\n\
        \t\t'SPACE' droop\n\
        \t\t'P' pause\n\
        \t\t'Q' 'ESC' quit\n";
    }
}

bool TiT::haveCurBlock(int row, int col) {
    for (int i = 0; i < 4; ++i) {
        if (curBlockPoints[i].row == row && curBlockPoints[i].col == col) {
            return true;
        }
    }
    return false;
}

bool TiT::havePreBlock(int row, int col) {
    for (int i = 0; i < 4; ++i) {
        if (preBlockPoints[i].row == row && preBlockPoints[i].col == col) {
            return true;
        }
    }
    return false;
}

void TiT::color(std::string str, int color) {
    // -1 : black   0 : red    1 : green
    // 2 : yellow   3 : blue   4 : purple
    // 5 : cyan     6 : orange 7 : white
    switch (color) {
        case -1: std::cout << "\033[30m"; break;
        case 0: std::cout << "\033[31m"; break;
        case 1: std::cout << "\033[32m"; break;
        case 2: std::cout << "\033[33m"; break;
        case 3: std::cout << "\033[34m"; break;
        case 4: std::cout << "\033[35m"; break;
        case 5: std::cout << "\033[36m"; break;
        case 6: std::cout << "\033[33m"; break;
        case 7: std::cout << "\033[37m"; break;
        default: std::cout << "\033[37m"; break;
    }
    std::cout << str << "\033[0m";
}

