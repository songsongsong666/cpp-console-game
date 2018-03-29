//
//  Game.h
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#ifndef __Game__
#define __Game__

#include <stdio.h>

#include "Gamer.h"
#include "Player.h"

class Game
{
private:
    Player* player;
    Gamer* banker;
    int round_number;
    
public:
    Game();
    Game( int init_amount );
    ~Game();
    void run_game();
    bool one_round();
};
#endif /* defined(__Game__) */
