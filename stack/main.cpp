/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 8 October, 2017, 4:00 PM
 */

#include <cstdlib>
#include <iostream>
#include "stack.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    stack* mystack = new stack;
    mystack->Push("JJ", 98);
    mystack->Push("lyy", 100);
    mystack->Push("lhx",97);
    mystack->Print();
    cout <<"pop one ---------------\n";
    mystack->Pop();
    mystack->Print();
    cout <<"pop one ---------------\n";
    mystack->Pop();
    mystack->Print();
    cout <<"pop one ---------------\n";
    mystack->Pop();
    mystack->Print();
    cout <<"pop one ---------------\n";
    mystack->Pop();
    mystack->Print();
    delete mystack;
    
    return 0;
}

