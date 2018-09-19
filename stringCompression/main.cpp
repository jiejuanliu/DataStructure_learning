/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 19 September, 2018, 10:49 AM
 */

#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
original string:aabbbccc
returned string:a2b3c3
original string:aabbcc
returned string:aabbcc
 */
string & stringCompression(string & str)
{
    int count=1;
    char temp;
    int index;
    std::vector<char> newString;
    
    //std::string s (newString.data());
    for(int i=0; i<= str.length();i++)
    {
        if(temp != str[i])
        {
            if(i!=0)
            {
                newString.push_back(temp);
                newString.push_back(count+'0');
            }
            temp = str[i];
            count=1;
            index=i;
        }
        else
        {
            count++;
        }
    }
    newString.push_back('\0');
    //convert a vector to a string
    //std::string s( (char*)newString.data(), newString.size() );
    //s.assign( (char*)newString.data(), newString.size() );
    //cout << "s:"<< newString.data()<<endl;
    if(newString.size()< str.length())
    {
       str.assign(newString.begin(), newString.end());
    }
   
    return str;
    
}
int main(int argc, char** argv) {
    
    std::string mystring("aabbbccc");
    cout <<"original string:"<<mystring<<endl;
    string & temp=stringCompression(mystring);
    cout <<"returned string:"<<temp<<endl;
    
    std::string mystring1("aabbcc");
    cout <<"original string:"<<mystring1<<endl;
    temp=stringCompression(mystring1);
    cout <<"returned string:"<<temp<<endl;
    return 0;
}

