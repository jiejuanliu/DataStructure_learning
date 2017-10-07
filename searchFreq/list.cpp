/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.cpp
 * Author: jiejualiu
 * 
 * Created on 7 October, 2017, 9:14 PM
 */
#include <iostream>
#include <string>
#include "list.h"

list::list() {
    node* head = NULL;
    node* curr = NULL; 
    node* last = NULL;
}

void list::AddValue( int data )
{
    node* temp;
    if(head == NULL)
    {
        temp = new node;
        temp->data = data;
        temp->num = 1;
        temp->next = NULL;
        head = temp;
    }
    else
    {
        curr = head;
        while((curr != NULL)&&(curr->data != data))
        {
            last = curr;
            curr = curr->next;
        }
        if(curr == NULL)
        {
            //not found, add the data in the end of list
            temp = new node;
            temp->data = data;
            temp->num = 1; 
            temp->next = NULL;
            last->next = temp;
        }
        else
        {
            //found the node in the list, increase the num;
            curr->num++;
        }
    }
}

void list::PrintNodeFreq()
{  
    if (head == NULL)
    {
        cout << "empty list\n";
    }
    else
    {
        curr = head;
        while( curr != NULL)
        {
            cout <<"value:" <<curr->data<< ", num:" << curr->num << endl;
            curr = curr->next;   
        }
    }        
}

list::~list() {
    node* temp;
    if(head != NULL)
    {
        curr = head;
        while(curr!= NULL)
        {
            temp = curr;
            curr = curr->next;
            delete temp;  
        }
    }
    head = NULL;
    curr = NULL;
}

