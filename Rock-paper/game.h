//
//  game.h
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#ifndef __game__
#define __game__

#include <stdio.h>
#include <string>
#include "Words.h"
using namespace std;

class game{
private:

    int wincount;//count how times of win
    int input;//store the user input as int, rock-0,paper-1,scissor-2

public:
    game();
    int getCount();//get the wincount
    bool judgeWin();//randomly generate an action for the AI player, then determine whether the player win
    void updateInput(string inp);//convert input to int
    void gameControl();//game control;
    string translate(string inpt);//using words and translate the input back to user action
    
};

#endif /* defined(__game__) */
