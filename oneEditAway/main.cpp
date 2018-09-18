/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 18 September, 2018, 3:27 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */

bool oneEditReplace(string & str1, string & str2)
{
    int count=0;
    bool ret=false;
    cout<<"in oneEditReplace!\n";
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i]!=str2[i])
        {
            count++;
        }
    }
    if(count==1)
        ret=true;
    return ret;
}
bool oneEditInsert(string & str1, string & str2)
{
    int index1, index2;
    cout<<"in oneEditInsert!\n";
    while((index2<str2.length())&&(index1<str1.length()))
    {
        if(str1.at(index1)!=str2.at(index2))
        {
            if(index1 != index2)
                return false;
            index2++;
        }
        else
        {
            index1++;
            index2++;
        }
    }
    return true;
}

bool oneEditAway(string & str1, string & str2)
{
    bool ret=false;
    if(str1.length()==str2.length())
        ret = oneEditReplace(str1, str2);
    else if(str1.length()==str2.length()+1)
        ret = oneEditInsert(str2, str1);
    else if(str1.length()==str2.length()-1)
        ret = oneEditInsert(str1, str2);
    else
        ;
    return ret;
}
int main(int argc, char** argv) 
{
    bool ret = 0;
    string str1 ("pale");
    string str2 ("pake");
    cout <<"strings:"<<str1<<";"<<str2<<endl; 
    ret = oneEditAway(str1, str2);
    if(ret == true)
        cout <<"These are oneEditAway strings\n\n";
    
    string str3 ("pale");
    string str4 ("palke");
    cout <<"strings:"<<str3<<";"<<str4<<endl;
    ret = oneEditAway(str3, str4);
    if(ret == true)
        cout <<"These are oneEditAway strings\n\n";
    
    string str5 ("palke");
    string str6 ("pale");
    cout <<"strings:"<<str5<<";"<<str6<<endl;
    ret = oneEditAway(str5, str6);
    if(ret == true)
        cout <<"These are oneEditAway strings\n\n";
    return 0;
}

