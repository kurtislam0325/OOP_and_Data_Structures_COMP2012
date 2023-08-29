#include <iostream>
#include <cstring>
#include "player.h"
using namespace std;

// Player's Constructor and Destructor

Player::Player(const char* const name, const int elo):
    score{0} {
    
    this->name = new char[strlen(name)+1]; 
    strcpy(this->name, name);

    this->elo = elo;
    // cout << "Construct Player: " << name << endl;
}

Player::~Player() {
    delete [] name;
}

// PlayerList's Constructor and Destructor

PlayerList::PlayerList(): numPlayers(0), players{nullptr} {
    this->players = new Player*[this->numPlayers];
}

PlayerList::PlayerList(const PlayerList& list) {
    this->numPlayers = list.numPlayers;
    players = new Player*[this->numPlayers];

    // cout << "PlayerList Constructor" << endl;
    // for (int i = 0; i < (this->numPlayers); i++) {
    //     list.players[i]->print(); 
    //     cout << endl;
    // }

    for (int i = 0; i < (this->numPlayers); i++) {
        players[i] = &(*list.players[i]);
    }
}

PlayerList::~PlayerList() {
    delete [] players;
    // there is no need to set all elements to nullptr before delete it
}

// PlayerList's Member Functions Declaration

void PlayerList::addPlayer(Player* const player) {  
    int count = numPlayers;  
    Player** temp = new Player*[count + 1];

    for (int i = 0; i < count; ++i) {
        temp[i] = players[i];
    }
    temp[count] = player; 

    delete[] players; 
    players = temp;

    numPlayers++;
}

bool comparison(Player* x, Player* y) {
    if (x->getScore() < y->getScore())
        return true;
    if (x->getScore() == y->getScore())
        return x->getELO() < y->getELO();
    return false;
}

void PlayerList::sort() {

    for (int i = 0; i < numPlayers; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (comparison(players[i], players[j])) {
                swap(players[i], players[j]);
            }
        }
    }
}

PlayerList* PlayerList::splice(const int startIndex, const int endIndex) const {
    PlayerList* spliced_list = new PlayerList();

    // Error Checking
    if (startIndex < 0 || endIndex > this->numPlayers || startIndex >= endIndex) {
        return spliced_list;
    }

    spliced_list->numPlayers = endIndex - startIndex;
    for (int i = startIndex, count = 0; i < endIndex; i++, count++) {
        spliced_list->players[count] = this->players[i];
    }

    return spliced_list;
}