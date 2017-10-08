/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stack.cpp
 * Author: jiejuan.liu
 * 
 * Created on 8 October, 2017, 4:01 PM
 */
#include <iostream>
#include "stack.h"

stack::stack() {
    stackPtr = NULL;
}

void stack::Push(string name, int value)
{
    //new a item, and fill name and data inside
    item* n = new item;
    n->name = name;
    n->value = value;
    //move stackPtr to the new item, and link the new item to the last one(saved in p)
    item * p = stackPtr;
    stackPtr = n;
    n->prev = p;
}
void stack::Pop()
{
    item* p = stackPtr;
    if(p != NULL)
    {
        stackPtr = stackPtr->prev;
        p->prev = NULL;
        delete p;   
    }
    else
    {
        cout << "no more item in the stack\n";
    } 
}

void stack::Print()
{
    item* p = stackPtr;
    if(p == NULL)
    {
        cout << "empty stack \n";
        return;
    }
    while( p != NULL )
    {
        cout<< "name="<< p->name << ",data=" << p->value << endl;
        p = p->prev;
    }
    
}

stack::~stack() {
    while(stackPtr != NULL)
        Pop();        
}

