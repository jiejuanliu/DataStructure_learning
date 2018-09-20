/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jiejuan.liu
 *
 * Created on 20 September, 2018, 11:15 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * rotate a matrix by 90 degree
 */

bool rotateMatrix(int matrix[][5], int n)
{ 
    int temp;
    for(int layer=0;layer<n/2;layer++)
    {
        int first = layer;
        int last = n-1-layer;
        for(int i=first;i<last;i++)
        {
            int offset=i-first;
            //save top to temp
            temp=matrix[first][i];
            //copy left to top
            matrix[first][i]=matrix[last-offset][first];
            //copy bottom to left
            matrix[last-offset][first]=matrix[last][last-offset];
            //copy right to bottom
            matrix[last][last-offset]=matrix[i][last];
            //copy temp to right
            matrix[i][last]= temp;
        }
    }
}
int main(int argc, char** argv) {
    int matrix [5][5]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    for(int i=0; i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           cout<<matrix[i][j]<<','; 
        }
        cout << endl;
    }
     cout << endl;
    rotateMatrix(matrix, 5);
    for(int i=0; i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
           cout<<matrix[i][j]<<','; 
        }
        cout << endl;
    }
    
    return 0;
}

