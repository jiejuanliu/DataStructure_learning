/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 14 September, 2018, 3:33 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void replaceSpace(string & str, int trueSize);
/*
 * 
 */
int main(int argc, char** argv) {
    int trueSize =13;
    string mystr ("Mr John Smith      ");
    replaceSpace(mystr, trueSize);
    cout << "final str:"<<mystr<<endl;
    return 0;
}

void replaceSpace(string & str, int trueSize)
{
    int requestSize, spaceCount, index;
    for(int i=0; i<trueSize;i++)
    {
        if(str.at(i)==' ')
            spaceCount++;
    }
    requestSize = trueSize+2*spaceCount;
    if(requestSize > str.size())
    {
        cout << "requested size exceeds size of string, exit\n";
        str.at(trueSize)='\0';
        return;
    }
    index = requestSize-1;
    for(int i=trueSize-1; i>=0; i--)
    {
        if(str.at(i)==' ')
        {
            str[index]='0';
            str[index-1]='2';
            str[index-2]='%';  
            index-=3;
        }
        else
        {
            str[index]=str[i];
            index--;
        }
    }
}