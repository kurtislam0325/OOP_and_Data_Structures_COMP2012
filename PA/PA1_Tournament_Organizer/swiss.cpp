#include <iostream>
#include "swiss.h"
#include "match.h"
using namespace std;

Swiss::Swiss(const int numRounds, const PlayerList& list):
    curRound(0), list(list), numRounds(numRounds) {

    this->list.sort();
}

Swiss::~Swiss() {

}

void Swiss::play() {    
    // cout << "numRounds: " << numRounds << endl;
    int numOfPossibleScores = 0;
    int numPlayers = 0;
    int midPoint = 0;
    PlayerList* listByScore = nullptr;

    for (curRound = 1; curRound <= numRounds; curRound++) {
        numOfPossibleScores = 2 * curRound - 1;
        listByScore = new PlayerList[numOfPossibleScores];
        numPlayers = list.getNumPlayers();


        this->list.sort();

        if (curRound == 1) {
            if (numPlayers % 2 == 1)
                list.getPlayer(numPlayers - 1)->addScore(2);
            midPoint = numPlayers/2;
            for (int i = 0; i < midPoint; i++) {
                Match x(list.getPlayer(i), list.getPlayer(i+midPoint));
                x.play();
            }
        } else {
            for (int i = 0; i < numOfPossibleScores; i++) {
                for (int j = 0; j < numPlayers; j++) {
                    if (list.getPlayer(j)->getScore() == (numOfPossibleScores - i - 1)) {
                        listByScore[i].addPlayer(list.getPlayer(j));
                    }
                }
                // for (int j = 0; j < listByScore[i].getNumPlayers(); j++) {
                //     listByScore[i].getPlayer(j)->print();
                //     cout << endl;   
                // } 
                // cout << "numPlayers: " << listByScore[i].getNumPlayers() << endl;
            }

            // cout << "Checking: ------ listByScore" << endl;
            // for (int i = 0; i < numOfPossibleScores; i++) {
            //     cout << "score: " << i << endl;
            //     for (int j = 0; j < listByScore[i].getNumPlayers(); j++) {
            //         listByScore[i].getPlayer(j)->print();
            //         cout << endl;   
            //     }  
            // }
            // cout << "Checking: ------ listByScore" << endl;

            for (int i = 0; i < (numOfPossibleScores - 1); i++) {
                listByScore[i].sort();
                numPlayers = listByScore[i].getNumPlayers();
                if (numPlayers % 2 == 1) {
                    // listByScore[i].getPlayer(numPlayers - 1)->print(); cout << endl;
                    listByScore[i + 1].addPlayer(listByScore[i].getPlayer(numPlayers - 1));
                }
                // cout << "score: " << i << endl;
                // for (int j = 0; j < listByScore[i].getNumPlayers(); j++) {
                //     listByScore[i].getPlayer(j)->print();
                //     cout << endl;   
                // } 
            }

            // cout << "Checking: ------ listByScore" << endl;
            // for (int i = 0; i < numOfPossibleScores; i++) {
            //     cout << "score: " << i << " " << endl;
            //     for (int j = 0; j < listByScore[i].getNumPlayers(); j++) {
            //         listByScore[i].getPlayer(j)->print();
            //         cout << endl;   
            //     }  
            // }
            // cout << "Checking: ------ listByScore" << endl;

            for (int i = 0; i < numOfPossibleScores; i++) 
                listByScore[i].sort();

            for (int i = 0; i < numOfPossibleScores; i++) {
                if (listByScore[i].getNumPlayers() == 0)
                    continue;
                midPoint = listByScore[i].getNumPlayers()/2;
                for (int j = 0; j < midPoint; j++) {
                    Match x(listByScore[i].getPlayer(j), listByScore[i].getPlayer(j+midPoint));
                    x.play();
                }

                // TODO: Add 2 Scores
                if (i == numOfPossibleScores - 1 && listByScore[i].getNumPlayers() % 2 == 1) {
                    listByScore[i].getPlayer(listByScore[i].getNumPlayers() - 1)->addScore(2);
                }
            }
        }

        list.sort();
        printLeaderboard();
        delete [] listByScore;
        listByScore = nullptr;
        // delete [] matchPair;
    }
}