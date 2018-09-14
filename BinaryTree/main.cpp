/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 3 September, 2018, 2:53 PM
 */
#include <cstdlib>
#include <iostream>
#include "bst.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int list[]={70, 55, 32, 12, 98, 100, 64, 101, 54, 96, 22, 33, 36, 47, 61, 44};
    class BST * myBST = new class BST;
    int i=0;
    int smallest;
   
    for(i=0; i < 16; i++)
    {
        myBST->AddLeaf(list[i]);
    }
    myBST->PrintInOrder();
    myBST->PrintChildren(myBST->ReturnRootKey());
    
    for(i=0; i < 16; i++)
    {
        myBST->PrintChildren(list[i]);
    }
    smallest = myBST->FindSmallest();
    cout << "\nsmallest key is:"<<smallest<<endl;
    cout << "input -1 for exiting\n";
    cin >> i;
    if(i == -1)
      delete myBST;  
    return 0;
}

