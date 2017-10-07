/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 7 October, 2017, 3:47 PM
 */

#include <cstdlib>
#include <iostream>
#include "linkList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int delData = 0;
    linkList* mylist = new linkList;
    for (int i=0; i<10; i++)
    {
        mylist->AddNode(i);
    }
    mylist->PrintList();
    cout << "Please input one int value for deleting, '99' for exit" << endl;
    while (delData != 99)
    {  
        cin >> delData;
        mylist->DeleteNode(delData);
        mylist->PrintList();
    } 
    delete mylist;
    return 0;
}

