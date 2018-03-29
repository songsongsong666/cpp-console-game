//
//  main.cpp
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#include <iostream>

#include"Game.h"

int main()
{
    Game *game = new Game(500);
    game->run_game();
    delete game;
    return 1;
}
