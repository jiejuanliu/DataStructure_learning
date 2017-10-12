/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 11 October, 2017, 3:29 PM
 */

#include <cstdlib>
#include <iostream>

#include "heap.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    heap* mylist = new heap;
    int array[] = {10,30,40,78,99,44,23,18,9,11,110};
    int length = sizeof(array)/sizeof(int);
    int temp;
    int i;
    for(i=0; i<length; i++)
    {
        mylist->InsertItem(array[i]);
    }
    
    int max = mylist->GetMax();
    cout << "max of the list:" <<max << endl;
    cout <<"--------------------------\n";
    
    for (i=0; i<length; i++)
    {
        temp = mylist->RemoveItem();
        cout << "remove item:" <<temp <<endl;    
    }
    return 0;
}

