//
//  Player.h
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#ifndef __Q1__Player__
#define __Q1__Player__

#include <stdio.h>
#include "Gamer.h"


class Player : public Gamer
{
private:
    int money;
    int amount_bet;
    
public:
    Player();
    Player(int init_money);
    ~Player();
    bool bet();
    void win();
    void lose();
};

#endif /* defined(__Player__) */
