//
//  Gamer.cpp
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#include "Gamer.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <climits>

using namespace std;

/**
 * this function sorts the dices in an ascending order. Implemented using bubble sort.
 */
void Gamer::sort_dices()
{
    
    int i, j;
    int temp;
    for(i = 0; i < NUM_DICES; i++) {
        for (j = 0; j < NUM_DICES - i - 1; j++) {
            if (dices[j+1] < dices[j]) {
                temp = dices[j];
                dices[j] = dices[j+1];
                dices[j+1] = temp;
            }
        }
    }
    return;   //arrays are passed to functions by address; nothing is returned
}

/**
 * This function generates random numbers and assigned them to the dices
 * -- Just as if the gamer rolled the dice
 * auto_reroll: This boolean is used to denote if the automatic reroll is enabled
 *              This boolean is set to true for banker and false for player
 * return: Return 0 if the result is Automatic Loss
 *         Return 7 if the result is Automatic win
 *         Return the point if this is a set point
 */
int Gamer::roll_dices(bool auto_reroll)
{
    //Keep roll dices until getting a valid result
    while(true) {
        for (int i = 0; i < NUM_DICES; i ++) {
            dices[i] = rand()%6 + 1;
        }
        std::cout << "The dices are: " << dices[0] << ", " << dices[1] << ", "<< dices[2] << "." <<std::endl;
        //sort the dices in a ascending order
        this->sort_dices();
        //std::cout << "After sorting, the dices are: " << dices[0] << ", " << dices[1] << ", "<< dices[2] << "." <<std::endl;
        //Chekcs for automatic wins
        if(dices[0] == 4 && dices[1] == 5 && dices[2] == 6) { // 4-5-6
            return 7;
        }
        if (dices[0] == dices[1] && dices[1] == dices[2] ) { //Trio
            return 7;
        }
        if (dices[0] == dices[1] && dices[2] == 6) { //A pair with a six
            return 7;
        }
        
        //Checks for Automatic losses
        if(dices[0] == 1 && dices[1] == 2 && dices[2] == 3) { //1-2-3
            return 0;
        }
        if(dices[0] == 1 && dices[1] == dices[2]) { //A pair and a 1
            return 0;
        }
        
        //Checks for set-point
        if(dices[0] == dices[1]) {
            return dices[2];
        }
        if(dices[1] == dices[2]) {
            return dices[0];
        }
        
        //Falling off to reroll
        if( auto_reroll ) {
            std::cout << "Re-rolling.......";
        } else {
            std::string input;
            
            std::cout << "Press enter to reroll the dices, or enter 'a' and then press enter to enable auto-reroll.";
            std::getline(std::cin, input);
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            if( input.compare("a") == 0 ) {
                auto_reroll = true;
            }
            std::cout << "Re-rolling......";
        }
    }
}
