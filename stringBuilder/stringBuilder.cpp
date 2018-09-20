/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stringBuilder.cpp
 * Author: jiejuan.liu
 * 
 * Created on 19 September, 2018, 4:41 PM
 */
#include "stringBuilder.h"
#include <cstdlib>
#include <string>

using namespace std;

stringBuilder::stringBuilder() {
}

stringBuilder::~stringBuilder() {
}

stringBuilder & stringBuilder::append(const std::string & str)
{
    scratch.append(str);
    if(scratch.size()> ScratchSize)
    {
        main.append(scratch);
        scratch.resize(0);
    }
    return *this;
};

std::string & stringBuilder::str()
{
    if(scratch.size()>0)
    {
        main.append(scratch);
        scratch.resize(0);
    }
    return main;
};