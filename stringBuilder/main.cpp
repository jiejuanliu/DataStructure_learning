/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 19 September, 2018, 4:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "stringBuilder.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    string s1 ("First");
    string s2 ("Second");
    string s3 ("Third");
    string s4 ("Fourth");
    stringBuilder * result=new stringBuilder;
    result->append(s1);
    result->append(s2);
    result->append(s3);
    result->append(s4);
    cout << "final string:"<<result->str()<<endl;
    return 0;
}

