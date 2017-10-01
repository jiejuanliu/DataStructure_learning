/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 1 October, 2017, 4:00 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/* Code for LinkList learning
 * Try to search an item in the single link list by recursion
 */
struct node{
    int data;
    node* next;
};

void SearchRecursive( node* head, int value )
{
    node* ptr = head;
    if( ptr == NULL)
    {
        cout << "head of list is NULL\n";
        return;
    }
    while( ptr != NULL)
    {
        if( ptr->data == value)
        {
            cout << "found value!\n"; 
            return;
        }
                
        ptr = ptr->next;             
    }
    cout << "Not found the value in the list!\n"; 
    return;
}

int main(int argc, char** argv) {
    node* n = new node;
    node* head = n;
    node* t = n;
    int value;
    n->data = 1;
    
    for(int i=2; i<10; i++)
    {
        node* n = new node;
        n->data = i;
        n->next = NULL;
        t->next = n;
        t = n;
    }
    
    t = head;
    while( t != NULL )
    {
        cout << t->data << ",";
        t = t->next;
    }
    
    cout << "Input a search value:";
    cin >> value;
    if (value != 0)
    {
        SearchRecursive(head, value);
    }
   
    return 0;
}

