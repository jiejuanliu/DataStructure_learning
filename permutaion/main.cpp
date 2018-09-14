/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 13 September, 2018, 4:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <array>

using namespace std;
bool checkPermutation(string& x, string& y);
/*Supposed the length of the string is the same
 * 
 */
int main(int argc, char** argv) {
    string a ("applejuice");
    string b ("eciujelpa");
    bool result = false;
    cout<<"string 1:"<<a<<endl;
    cout<<"string 2:"<<b<<endl;
    result = checkPermutation(a, b);
   
    if(result)
        cout<< "the two strings' permutation are the same\n";
    else
        cout<< "permutation of the two strings are NOT the same\n";
    return 0;
}

bool checkPermutation(string & x, string &y)
{
    array<int, 256> freq;
    freq.fill(0);
    
    if(x.size() != y.size())
        return false;
    
    for(int i=0;i<x.size();i++)
    {
        int val = x.at(i);
        (freq[val])++;
        cout <<"feq["<<val<<"]"<<freq[val]<<endl;
    }
    
    for(int i=0;i<y.size();i++)
    {
        int val = y.at(i);
        (freq.at(val))--;
        if(freq[val]<0)
            return false;        
    }

    return true;
}