//
//  Game.cpp
// 
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#include "Game.h"
#include "Gamer.h"
#include <iostream>

/**
 * default C-tor
 */
Game::Game()
{
    player = new Player();
    banker = new Gamer();
    round_number = 0;
}

/**
 * C-tor overloaded with init amount of money which player has
 */
Game::Game( int init_amount )
{
    player = new Player( init_amount );
    banker = new Gamer();
    round_number = 0;
}

/**
 * D-tor
 */
Game::~Game()
{
    delete banker;
    delete player;
}

/**
 * This method runs the cee-lo game
 */
void Game::run_game()
{
    std::cout << "Welcome to the cee-lo game casino!" << std::endl;
    while( one_round() ) {;}
}

/**
 * This function simulates one round of the game
 */
bool Game::one_round()
{
    round_number ++;
    std::cout << "***************************" << std::endl;
    std::cout << "This is the #" << round_number << " round of the Cee-lo game." << std::endl;
    //Let the player make his bet
    if ( !player->bet() ) {
        return false;
    }
    
    //The banker rolls the dice
    std::cout << "The banker is rolling the dices..." << std::endl;
    int banker_point = banker->roll_dices(true);
    if(banker_point == 7) {
        std::cout << "The banker rolled an Automatic Win. You loss this round. Good luck!" << std::endl;
        player->lose();
    } else if( banker_point == 0 ) {
        std::cout << "The banker rolled an Automatic Loss. You win this round. Congratulations!" << std::endl;
        player->win();
    } else {
        std::cout << "Set Point! The banker got a point of " << banker_point << "." << std::endl;
        std::cout << "Your turn to roll the dices..." << std::endl;
        int player_point = player->roll_dices(false);
        if(player_point == 7) {
            std::cout << "You rolled an Automatic Win. You win this round. Congratulations!" << std::endl;
            player->win();
        } else if( player_point == 0 ) {
            std::cout << "You rolled an Automatic Loss. You loss this round. Good luck!" << std::endl;
            player->lose();
        } else {
            std::cout << "Set Point! You got a point of " << player_point << ", while banker got a point of " << banker_point << "." <<std::endl;
            if(player_point < banker_point) {
                std::cout << "You lose round #" << round_number << "."<< std::endl;
                player->lose();
            } else if (player_point > banker_point) {
                std::cout << "You win round #" << round_number << "."<< std::endl;
                player->win();
            } else {
                std::cout << "Round #" << round_number << " is a tie game!" << std::endl;
            }
        }
    }
    return true;
}
