/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.cpp
 * Author: jiejuan.liu
 * 
 * a max heap class
 * 
 * Created on 11 October, 2017, 3:30 PM
 */


#include "heap.h"
#include <cstdlib>
#include <iostream>


using namespace std;

heap::heap() {
    
}

void heap::InsertItem(int value)
{
    //Add a value in the tail of the array.
    list.push_back(value);
    BubbleUp();
    PrintList();
}

int heap::RemoveItem()
{
    //swap the root and the tail item
    int tail = list.size()-1;
    Swap(0, tail);
    
    //retrieve the value of root item and return
    int value = list.back();
    
    //remove the last value in the array
    list.pop_back();
    
    //Re-sort the tree, move the max value to the root
    BubbleDown();
    
    return value;
}

void heap::BubbleUp()
{
    int child = list.size()-1;
    int parent = GetParent(child);
    cout << "child = " << child <<" parent= " << parent <<endl;
    //if child is bigger than parent, flip the parent and child
    while((list[child]>list[parent]) && (child>=0) && (parent>=0))
    {
        Swap(parent, child);
        child = parent;
        parent = GetParent(child);
    }
    
}

void heap::BubbleDown()
{
    int parent = 0;
    int left = 0; 
    int right = 0;
    int max = 0;
    int length = 0;
    while(1)     
    {
        left = GetLeft(parent);
        right = GetRight(parent);
        length = list.size();
        
        //if both left and right are not empty items, max = largest of children
        if((left < length )&&(right < length))
        {
            max = (list[left]> list[right])? left : right;
        }
        //if left is existed, while right is NULL, max = left
        else if((left < length )&&(right >= length))
        {
            max = left;
        }
        //reach the end of list, return
        else
            break;
        
        if(list[max] > list[parent])
        {
            Swap(parent, max);
            parent = max;
        }
        else
        {
            break;
        }
    }
    
}

void heap::Swap(int parent, int child)
{
    int temp = list[parent];
    list[parent] = list[child];
    list[child] = temp;
   
}

int heap::GetLeft(int parent)
{
   //if parent is n, left child is 2n+1
    return (2*parent +1);
    
}

int heap::GetRight(int parent)
{
   //if parent is n, right child is 2n+2
    return (2*parent +2);
    
}

int heap::GetParent(int child)
{
    //if child is odd(left), supposed it is n, parent is (n-1)/2
    //if child is even(right), supposed it is n, parent is (n-2)/2
    if(child%2 == 0)
    {
        return (child/2 -1);
    }
    else
    {
        return ((child-1)/2);
    }
}

void heap::PrintList()
{
    cout << "list:";
    for (int i=0; i<list.size(); i++)
    {
        cout << list[i] <<"," ;
    }
    cout << endl;
}
int heap::GetMax()
{
    if(list.size() != 0)
        return list[0];
    else
        return 0;
}

heap::~heap() {
    while(list.size()>0)
    {
        RemoveItem(); 
    }
}

