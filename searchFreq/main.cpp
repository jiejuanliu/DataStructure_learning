/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuanliu
 *
 * Created on 7 October, 2017, 9:08 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include "list.h"

using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {
    
   char a[] = "abcabcvf^^%&";
   int length = std::strlen(a);
            
   class list* myList = new list;
   
   for(int i = 0; i< length; i++)
       myList->AddValue((int)a[i]);
   myList->PrintNodeFreq();
   delete myList;
   return 0;
}

