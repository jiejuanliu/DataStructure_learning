/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 13 September, 2018, 3:28 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    vector<string> myarray;
    if(argc>1)
    {
        for(int i=1; i<argc; i++)
        {
            myarray.push_back(argv[i]);
            cout << myarray[i-1]<<endl;
        }
        for(vector<string>::iterator it=myarray.begin(); it<myarray.end(); it++)
            cout<<*it<<endl;
    }
    return 0;
}

string 