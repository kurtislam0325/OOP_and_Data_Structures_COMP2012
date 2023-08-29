#include "hashtable.h"
using namespace std;

BoardOptimalMove BoardHashTable::getHashedMove(const unsigned long long id, const int depth) {
    if (table[id % TABLE_SIZE]) {
        for (BoardHashNode* p = table[id % TABLE_SIZE]; p != nullptr; p = p->next) {
            if (p->id == id) {
                if (depth <= p->depth) 
                    return p->optimalMove;
                else break;
            }
        }
    }

    return BoardOptimalMove();
}

void BoardHashTable::updateTable(const unsigned long long id, const int depth, const BoardOptimalMove& optimalMove) {
    if (!table[id % TABLE_SIZE]) {
        table[id % TABLE_SIZE] = new BoardHashNode(id, depth, optimalMove);
    } else {
        for (BoardHashNode* p = table[id % TABLE_SIZE]; p != nullptr; p = p->next) {
            if (p->id == id) {
                if (p->depth > depth) {
                    p->depth = depth;
                    p->optimalMove = optimalMove;
                } else break;
            } else if (p->next == nullptr) {
                p->next = new BoardHashNode(id, depth, optimalMove);
                break;
            }

        }        
    }

    return;
}

void BoardHashTable::clearTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == nullptr)
            continue;

        BoardHashNode* prev = nullptr;
        BoardHashNode* current = table[i];
        while (current != nullptr) {
            prev = current;
            current = current->next;

            delete prev;
            prev = nullptr; 
        }
        table[i] = nullptr;
    }
}