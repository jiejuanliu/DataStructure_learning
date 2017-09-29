/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.h
 * Author: jiejuan.liu
 *
 * Created on 27 September, 2017, 3:05 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H


class myhash{
private:
    static const int tableSize = 10;
    
    struct item{
        string name;
        string drink;
        item* next;
    };
    
    item* HashTable[tableSize];

public:
    myhash();
    int Hash(string key);
    void AddItem(string name, string drink);
    int NumberOfItemInIndex( int index);
    void PrintTable();
    void PrintItemsInIndex(int index);
    void FindDrink(string name);
    void RemoveItem(string name);
};

#endif

