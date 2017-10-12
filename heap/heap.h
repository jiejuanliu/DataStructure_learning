/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   heap.h
 * Author: jiejuan.liu
 *
 * Created on 11 October, 2017, 3:30 PM
 */

#ifndef HEAP_H
#define HEAP_H

#include <vector>

using namespace std;

class heap {
private:
   vector<int> list;
public:
    heap();
    void InsertItem(int value);
    int RemoveItem();
    int GetLeft(int parent);
    int GetRight(int parent);
    int GetParent(int child);
    void BubbleUp();
    void BubbleDown();
    void Swap( int parent, int child);
    int GetMax();
    void PrintList();
    virtual ~heap();
};

#endif /* HEAP_H */

