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
        curr = temp;
    }
    else
    {
        curr->next = temp;
        curr = curr->next;
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
    }
    else
    {
        cout << "empty list\n";
    }    
    cout << "\n";
}
void linkList::DeleteNode(int delData)
{
    if(head == NULL)
    {
        //0. empty list
        cout << "empty list"<<endl;
    }
    else
    {
        //1. only one node and matched, directly delete the node, and reset the list
        if((head->data == delData) && (head->next == NULL))
        {
            delete head;
            head = NULL;
            curr = NULL;
            temp = NULL;
            cout << "only one node, matched and deleted" << endl;
        }
        //2. not only one node, first one matched, delete the first one and move the head to the next one
        else if (head->data == delData)
        {
            temp = head;
            head = head ->next;
            delete temp;
        }
        //3. not only one node, first one not matched
        else if(head->next != NULL)
        {
            last = head;
            curr = head->next;
            while(curr != NULL)
            {
                //3.1 not only one node in the list, if matched(not the head) then delete the node and link last node to next node 
                if(curr->data == delData)
                {
                    temp = curr;
                    curr = curr->next;
                    last->next = curr;
                    delete temp;   
                }
                //3.2 not only one node in the list, if not matched, move curr/last one forward
                else
                {
                    last = curr;
                    curr = curr->next;
                }
            }
        }
        //3. only one node, but not matched
        else 
        {
            cout << "only one node, not matched" << endl;
        }
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

