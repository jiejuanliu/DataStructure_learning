/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linkList.cpp
 * Author: jiejuan.liu
 * 
 * Created on 7 October, 2017, 3:48 PM
 */
#include <cstdlib>
#include <iostream>
#include "linkList.h"

using namespace std;

linkList::linkList() {
    head = NULL;
    curr = NULL;
    temp = NULL;
}

void linkList::AddNode(int addData)
{
    temp = new node;
    temp->data = addData;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}
void linkList::PrintList()
{
    if(head != NULL)
    {
        cout << head->data << ",";
        curr = head->next;
        while( curr != NULL)
        {
            cout << curr->data <<",";
            curr = curr->next;
        }
        cout << "\n";
    }
    else
    {
        cout << "empty list\n";
    }    
    
}
void linkList::DeleteNode(int delData)
{
    last = head;
    curr = head;
    
    while((curr != NULL)&&(curr->data != delData))
    {
        last = curr;
        curr = curr->next;   
    }
    if(curr == NULL)
    { 
        cout << "not found the node in the list"<< endl;  
    }
    else
    {
            temp = curr;
            curr = curr->next;
            last->next = curr;
            if( temp == head)
            {
                head = head->next;
                temp = NULL;
            }
            delete temp;
            cout << "found and deleted\n";
    }
}

linkList::~linkList() {
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    PrintList();      
}

