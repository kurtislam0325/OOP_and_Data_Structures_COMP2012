#include "boardtree.h"
#include "const.h"
#include "hashtable.h"

using namespace std;

BoardTree::BoardTree(const Board& board) {
    root = new BoardNode(board);
}
// Destructor
BoardTree::~BoardTree() {
    delete root;
}

// Return a pointer to the subtree at the given coordinates. Build the tree if it is empty.
BoardTree* BoardTree::getSubTree(const BoardCoordinate& coords) {
    BoardTree* subTree = nullptr;

    // cout << "Start Searching" << endl;
    if (this->isEmpty()) { // Base Case 1
        return nullptr;
    }

    Board given = root->board;
    bool isValidMove = given.play(coords);

    for (int i = 0; i < BOARD_SIZE; i++) { 
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (root->subTree[i][j].isEmpty()) {
                if (isValidMove) {
                    root->subTree[i][j].root = new BoardNode(given);
                    subTree = &(root->subTree[i][j]);
                } else subTree = new BoardTree(given);
                break;
            }   

            if (root->subTree[i][j].root->board.getID() == given.getID()) {
                subTree = &(root->subTree[i][j]);
                break;
            } 
        }
    }

    return subTree;
}

// Calculate the best move by searching the tree up to depth moves ahead
BoardOptimalMove BoardTree::getOptimalMove(const unsigned int depth) {
    if (this->isEmpty()) {
        return BoardOptimalMove(); 
    }

    if (depth == 0 || root->board.isFinished()) {
        return BoardOptimalMove(root->board.getBoardScore(), BoardCoordinate(100, 100));
    }


    BoardOptimalMove bestMove;
    bestMove = BoardHashTable::getInstance().getHashedMove(root->board.getID(), depth);
    if (bestMove.score != ILLEGAL) {
        return bestMove;
    }

    Cell curPlayer = root->board.getCurPlayer();
    int estimatedScore = (curPlayer == X)? -30000: 30000;

    for (int i = 0; i < BOARD_SIZE; i++) { // i = row
        for (int j = 0; j < BOARD_SIZE; j++) { // j = col
            if (root->subTree[i][j].isEmpty()) {
                Board tempBoard = root->board;
                bool isValidMove = tempBoard.play(BoardCoordinate(i, j));
                
                if (isValidMove)
                    root->subTree[i][j].root = new BoardNode(tempBoard);
                else continue;
            }

            BoardOptimalMove childMove = root->subTree[i][j].getOptimalMove(depth - 1);

            if (childMove.score == ILLEGAL)
                continue;

            if (curPlayer == X) {
                if (childMove.score > estimatedScore) {
                    estimatedScore = childMove.score;
                    bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i, j));
                }
            } else if (curPlayer == O) {
                if (childMove.score < estimatedScore) {
                    estimatedScore = childMove.score;
                    bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i, j));
                }      
            }
        }
    }

    BoardHashTable::getInstance().updateTable(root->board.getID(), depth, bestMove);
    return bestMove;
}


// Same as above but utilizes alpha-beta pruning
BoardOptimalMove BoardTree::getOptimalMoveAlphaBeta(const unsigned int depth, int alpha, int beta) {
    if (this->isEmpty()) {
        return BoardOptimalMove(); 
    }

    if (depth == 0 || root->board.isFinished()) {
        return BoardOptimalMove(root->board.getBoardScore(), BoardCoordinate(100, 100));
    }

    BoardOptimalMove bestMove;
    bestMove = BoardHashTable::getInstance().getHashedMove(root->board.getID(), depth);
    if (bestMove.score != ILLEGAL) {
        return bestMove;
    }

    Cell curPlayer = root->board.getCurPlayer();
    int estimatedScore = (curPlayer == X)? -30000: 30000;
    bool isSkipped = false;

    for (int i = 0; i < BOARD_SIZE; i++) { // i = row
        for (int j = 0; j < BOARD_SIZE; j++) { // j = col
            if (root->subTree[i][j].isEmpty()) {
                Board tempBoard = root->board;
                bool isValidMove = tempBoard.play(BoardCoordinate(i, j));
                
                if (isValidMove)
                    root->subTree[i][j].root = new BoardNode(tempBoard);
                else continue;
            }

            BoardOptimalMove childMove = root->subTree[i][j].getOptimalMoveAlphaBeta(depth - 1, alpha, beta);

            if (childMove.score == ILLEGAL)
                continue;

            if (curPlayer == X) {
                if (childMove.score > beta) {
                    isSkipped = true;
                    break;
                }

                if (childMove.score > estimatedScore) {
                    estimatedScore = childMove.score;
                    bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i, j));
                }
            } else if (curPlayer == O) {
                if (childMove.score < alpha) {                   
                    isSkipped = true;
                    break;
                }
                
                if (childMove.score < estimatedScore) {
                    estimatedScore = childMove.score;
                    bestMove = BoardOptimalMove(estimatedScore, BoardCoordinate(i, j));
                }      
            }
        }
        if (isSkipped)
            break;
    }

    BoardHashTable::getInstance().updateTable(root->board.getID(), depth, bestMove);
    return bestMove;
}