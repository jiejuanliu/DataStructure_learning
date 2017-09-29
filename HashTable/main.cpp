/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 27 September, 2017, 3:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    myhash Hashy;
    string name ="";
    
    Hashy.AddItem("JJL", "lemon juice");
    Hashy.AddItem("Lyy", "coke");
    Hashy.AddItem("Lhx", "soda");
    Hashy.AddItem("Paul", "apple juice");
    Hashy.AddItem("Kim", "iced mocha");
    Hashy.AddItem("Emma", "strawberry smoothy");
    Hashy.AddItem("Annie", "pession fruit tea");
    Hashy.AddItem("Pepper", "cider");
    Hashy.AddItem("Bill", "water");
    Hashy.AddItem("Marie", "long black");
    Hashy.AddItem("Joe", "barley");
    
    //Hashy.PrintTable();
    //Hashy.PrintItemsInIndex(4);
    while( name != "exit" )
    {
        cout<< "Search for name: ";
        cin >> name;
        if(name != "exit")
        {
            
            Hashy.RemoveItem(name);
            Hashy.PrintTable();
        }
        else
        {
            exit(0);
        }
    }
    
    
    return 0;
}

