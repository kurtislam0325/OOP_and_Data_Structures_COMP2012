#include "board.h"
using namespace std;

Cell findMatch(const Cell cell[][BOARD_SIZE]) { // return the player who has a match
    int sum = 0;

    sum = 0; // horizontal match
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int i = 0; i < BOARD_SIZE; i++)
            sum += cell[row][i];
        if (sum == BOARD_SIZE || sum == -BOARD_SIZE)
            return (sum == BOARD_SIZE)? X: O;    
        sum = 0;            
    }

    sum = 0; // vertical match
    for (int col = 0; col < BOARD_SIZE; col++) {
        for (int i = 0; i < BOARD_SIZE; i++)
            sum += cell[i][col];   
        if (sum == BOARD_SIZE || sum == -BOARD_SIZE)
            return (sum == BOARD_SIZE)? X: O;    
        sum = 0;            
    }    

    sum = 0; // downsloping match
    for (int i = 0, j = 0; i < BOARD_SIZE; i++, j++)
        sum += cell[i][j];
    if (sum == BOARD_SIZE || sum == -BOARD_SIZE)
        return (sum == BOARD_SIZE)? X: O;       

    sum = 0; // upsloping match
    for (int i = BOARD_SIZE - 1, j = 0, count = 0; count < BOARD_SIZE; i--, j++, count++)
        sum += cell[i][j];
    if (sum == BOARD_SIZE || sum == -BOARD_SIZE)
        return (sum == BOARD_SIZE)? X: O;   

    return EMPTY;
}

// Initialize cells as all empty, score with the given parameter, curPlayer as X and id as 0.
Board::Board(const int score[][BOARD_SIZE]): curPlayer(X), id(0) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            cells[i][j] = EMPTY;
            this->score[i][j] = score[i][j];
        }
    }
}

// Return true if all cells are not EMPTY.
bool Board::isFull() const {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (cells[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

// Return true if the game has finished (a match is found or board is full).
bool Board::isFinished() const {
    int result = findMatch(cells);
    if (isFull() || result == X || result == O)
        return true;

    return false;
}

// Calculate the board's current score.
int Board::getBoardScore() const {
    // Check if any player has gotten a match
    int BoardScore = 0;    
    int result = findMatch(cells);

    if (result == X || result == O)
        return (result == X)? WIN_SCORE: -WIN_SCORE;
    else {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (cells[i][j] == X) {
                    // cout << "CellWeight: " << i << j << " " << getCellWeight(cells[i][j]) << endl;
                    BoardScore += (getCellWeight(cells[i][j]) * score[i][j]);
                }
            }
        }
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (cells[i][j] == O)
                    BoardScore -= (getCellWeight(cells[i][j]) * score[i][j]);
            }
        }    
    }

    return BoardScore;
}

// Play the next move at coords. If successful, update the data members and return true. Otherwise return false.
bool Board::play(const BoardCoordinate& coords) {
    if (coords.isValid() && cells[coords.row][coords.col] == EMPTY) {
        // cout << "is Valid move" << endl;
        cells[coords.row][coords.col] = curPlayer;
        curPlayer = (curPlayer == X)? O: X;

        id = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                int cellValue = 0;                
                switch (cells[i][j]) {
                    case EMPTY:
                        cellValue = 0; break;                    
                    case X:
                        cellValue = 1; break;
                    case O:
                        cellValue = 2; break;
                }
                id += cellValue * pow(3,i * BOARD_SIZE + j);
            }
        }
        // cout << *this << endl; // debug
        return true;
    }

    return false;
}
