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
#include <array>

using namespace std;

bool IsUnique(string a);
/*
 * 
 */
bool IsUnique(string a)
{
    int length = a.size();
    array<bool,256> charList;
    int val;
   
    cout <<"------------------\n";
    cout <<"string=" << a <<endl;
    cout <<"length=" << length <<endl;
    cout <<"size of arry=" << charList.size()<<endl;
  
    for(int i=0; i<length; i++)
    {
        val = a.at(i);
        if(charList[val])
        {
            return false;
        }
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
        cout <<"IS unique";
    result = IsUnique(str2);
    
    if(result == false)
        cout <<"not unique\n";
    else
        cout <<"unique\n";
    return 0;
}

