/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: jiejuanliu
 *
 * Created on 7 October, 2017, 9:14 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

class list{
private:
    struct node 
    {
        int data;
        int num;
        node* next;
    };
    
    node* head;
    node* curr;
    node* last;
    
public:
    list();
    virtual ~list();
    void AddValue(int data);
    void PrintNodeFreq();
};

#endif /* LIST_H */

