/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkList.h
 * Author: jiejuan.liu
 *
 * Created on 7 October, 2017, 3:48 PM
 */

#ifndef LINKLIST_H
#define LINKLIST_H

class linkList {    
private:
    struct node{
       int data;
       node* next;
    };
    typedef struct node* nodePtr;
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    nodePtr last;
public:
    linkList();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();
    virtual ~linkList();
};

#endif /* LINKLIST_H */

