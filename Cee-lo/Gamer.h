//
//  Gamer.h
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#ifndef __Q1__Gamer__
#define __Q1__Gamer__

#include <stdio.h>
#define NUM_DICES 3

class Gamer
{
protected:
    int dices[NUM_DICES];
    void sort_dices();
    
public:
    Gamer() {};
    ~Gamer() {};
    int roll_dices(bool auto_reroll);
};

#endif /* defined(__Gamer__) */
