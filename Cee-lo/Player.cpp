//
//  Player.cpp
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#include "Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>

/**
 * default C-tor
 */
Player::Player()
{
    money = 500;
    amount_bet = 0;
}

/**
 * C-tor with init_amout of money which player hold
 */
Player::Player(int init_money) : money(init_money), amount_bet(0)
{
}

/**
 * default D-tor
 */
Player::~Player()
{
}

/**
 * Function which simulates player bets money on this game
 * return true if this is a successful bet, false if the user has no money or choose to quit
 */
bool Player::bet()
{
    if( money <= 0 ) {
        std::cout << "You don't have any money... Casino does not like people with no money." << std::endl;
        std::cout << "Exiting the cee-lo game... " << std::endl;
        return false;
    }
    
    while(true) {
        std::cout << "You have $" << money << " currently, please make your bet!" <<std::endl;
        std::cout << "Press 'a' for bet $50, 'b' for $100, 'c' for $150, or enter any other amount and then press enter. ";
        std::cout << "Or if you want to leave the casino, please enter 'q' and press enter." << std::endl;
        std::string input;
        std::cin >> input;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        int input_amount;
        if( input.compare("a") == 0 ) { //User input "a"
            input_amount = 50;
        } else if ( input.compare("b") == 0 ) { //User input "b"
            input_amount = 100;
        } else if ( input.compare("c") == 0 ) { //User input "c"
            input_amount = 150;
        } else if ( input.compare("q") == 0 ) {
            return false;
        } else { //User input anything else - try to parse it - atoi will return 0 if could not convert
            input_amount = atoi(input.c_str());
        }
        
        if( input_amount <= 0 ) {
            std::cout << "The number you bet is 0 or smaller, or bad input, ";
        } else if ( input_amount > money ) {
            std::cout << "The number you bet ($" << input_amount << ") is more than the money you have ($" << money <<"), ";
        } else {
            amount_bet = input_amount;
            return true;
        }
    }
}

/**
 * win - This means player wins this round, which doubles the player which user bet for this round
 */
void Player::win()
{
    money += amount_bet;
    amount_bet = 0;
}


/**
 * lose - This means player loses this round, which he lose all the money he bets
 */
void Player::lose()
{
    money -= amount_bet;
    amount_bet = 0;
}
