//
//  farkle.hpp
//  lab4
//
//  Created by Spencer Kim on 10/18/20.
//

#include <stdio.h>
#include <iostream>
//#include "Dice.hpp"

#ifndef farkle_hpp
#define farkle_hpp




class FarkleGame{
public:
    FarkleGame();
    void rollDice();
    void displayDice();



private:
    int turnScore;
    int rollScore;
    int calcRoll();
    int pairCounter;
    int tripCounter;
    int numDice;
    int arrDice[6];
    int sortedArrDice[7];
    bool shake;
    bool endTurn;
    bool diceChange;
    //bool continue;

};


#endif /* farkle_hpp */
