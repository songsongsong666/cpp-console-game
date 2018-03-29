//
//  game.cpp
//  
//
//  Created by ssf on 14-12-11.
//  Copyright (c) 2014年 Shifeng Song. All rights reserved.
//

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Words.h"
using namespace std;
//purpose statement go back see header file
game::game(){
    input = NULL;
    wincount = 0;

};

int game::getCount() {
    return wincount;
}


bool game::judgeWin(){
    int AI = rand()%3;
    if((input == 0 && AI ==2)||(input==1 && AI ==0)||(input ==2 && AI==1)) {
        cout<<"you win"<<endl;
        wincount++;
        return true;
    }
    cout<<"AI's action beat you, you lose"<<endl;
    return false;
};


void game::updateInput(string inp) {
    if(inp =="1"){
        input = 0;
    }
    if(inp =="2"){
        input = 2;
    }
    if(inp =="3"){
        input = 3;
    }
}
string game::translate(string inpt){
    string rock = "rock";
    string paper = "paper";
    string scissors = "scissors";
    char** list;
    list = new char*[3];
    for(int i=0;i<3;i++) list[i] = new char[10];
    for(int i = 0; i < rock.length(); i++) list[0][i]=rock.at(i);
    list[0][rock.length()+1]= '\0';
    for(int i = 0; i < paper.length(); i++) list[1][i]=paper.at(i);
    list[1][paper.length()+1]= '\0';
    for(int i = 0; i < scissors.length(); i++) list[2][i]=scissors.at(i);
    list[2][scissors.length()+1]= '\0';
    Words componet{3,10,list};//<<<<<<<<<<<<<<<<----------------words！！！！！！！！
    string output = "watever";
    if(inpt == "1") output = string(componet.list[0]);//
    if(inpt == "2") output = string(componet.list[1]);//<<<<<<<<<<<<<<--------------------using words and cstring!
    if(inpt == "3") output = string(componet.list[2]);//
        
    
    
    
   return output;
};

void game::gameControl(){
    string input=" ";
    string store= "no matter";

    while(input !="q"){
        cout<<"---------------------------------"<<endl;
        cout<<"please choose your action"<<endl;
        cout<<"yong words 1 rock 2 paper 3 scissor"<<endl;
        cout<<"or type q then enter to quit"<<endl;
    cin>>input;
            updateInput(input);
        store = translate(input);
        cout<<"you use :" + store<<endl;
            judgeWin();
        
    }
    cout<<"game is over, you winned: "<< wincount <<" times."<<endl;
   
    
    
}


















