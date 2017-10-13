/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 13 October, 2017, 4:05 PM
 * 
 * Implement an algorithm to determine if a string has all unique characters 
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

bool IsUnique(string a);
/*
 * 
 */
bool IsUnique(string a)
{
    int length = a.size();
    bool charList[256];//ASCII 256
    int val;
    
    cout <<"------------------\n";
    cout <<"string=" << a <<endl;
    cout <<"length=" << length <<endl;
    
    for(int i=0; i<length; i++)
    {
        val = a[i];
        if(charList[val] != false)
            return false;
        else
            charList[val] = true;
    }
    return true;
}

int main(int argc, char** argv) {

    string str1 = "abcdef";
    string str2 = "abcdefa";
    bool result;
    
    result = IsUnique(str1);
    if(result == false)
        cout <<"not unique\n";
    else
        cout <<"unique";
    result = IsUnique(str2);
    
    if(result == false)
        cout <<"not unique\n";
    else
        cout <<"unique\n";
    return 0;
}

