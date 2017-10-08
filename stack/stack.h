/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.h
 * Author: jiejuan.liu
 *
 * Created on 8 October, 2017, 4:01 PM
 */

#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class stack {
private:
    struct item{
        string name;
        int value;
        item* prev;
    };
    
    item* stackPtr;
public:
    stack();
    virtual ~stack();
    void Push(string name, int value);
    void Pop();
    void ReadItem(item* r);
    void Print();
};

#endif /* STACK_H */

