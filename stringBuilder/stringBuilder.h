/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   stringBuilder.h
 * Author: jiejuan.liu
 *
 * Created on 19 September, 2018, 4:41 PM
 */

#ifndef STRINGBUILDER_H
#define STRINGBUILDER_H
#include <cstdlib>
#include <string>

class stringBuilder {
private:
    std::string main;
    std::string scratch;
    const std::string::size_type ScratchSize = 1024;
    
public:
    stringBuilder();
    stringBuilder & append(const std::string & str);
    
    std::string & str();
    
    virtual ~stringBuilder();

};

#endif /* STRINGBUILDER_H */

