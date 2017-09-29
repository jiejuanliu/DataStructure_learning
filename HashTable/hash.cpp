/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   hash.cpp
 * Author: jiejuan.liu
 *
 * Created on 27 September, 2017, 3:05 PM
 */

#include "hash.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
myhash::myhash()
{
    for (int i = 0; i < tableSize; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = NULL;
        //cout << "init name = " << HashTable[i]->name << endl;
    }
}
int myhash::Hash(string key)
{
    int hash = 0;
    int index;

    for( int i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % tableSize;
    //cout << "hash = " << hash << endl;
    //cout << "index = " << index << endl;
    return index;
}

void myhash::AddItem(string name, string drink)
{
    int index;
    index = Hash(name);
    
    if (HashTable[index]->name == "empty")
    {
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else
    {
        item* ptr = HashTable[index];
        item* n = new item;
        n->name = name;
        n->drink = drink;
        n->next = NULL;
        while( ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

int myhash::NumberOfItemInIndex(int index)
{
    int num = 0;
    item* ptr = HashTable[index];
    if( ptr->name != "empty")
    {
        num++;
        while( ptr->next != NULL )
        {
            num++;
            ptr = ptr->next;
        }
    }
    
    //cout << "NumberOfItemInIndex " << "index="<< index << ", num="<<num << endl;
    return num;
}

void myhash::PrintTable()
{
    int num = 0;
    for(int i=0; i<tableSize; i++)
    {
        num = NumberOfItemInIndex(i);
        cout << "----------------\n";
        cout << "Index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "Num of index = " << num << endl;
        cout << "----------------\n";
    }
}

void myhash::PrintItemsInIndex(int index)
{
    item* ptr = HashTable[index];
    if(ptr->name != "empty")
    {
        cout << "index bucket " << index << " contains items as below: " <<endl;
        cout << "--------------------------\n";
        while(ptr != NULL)
        {
            cout << ptr->name <<endl; 
            cout << ptr->drink <<endl;
            cout << "--------------------------\n";
            ptr = ptr->next;
        } 
    }
    else
    {
        cout << "index bucket " << index << "is empty" <<endl;
    }
}

void myhash::FindDrink(string name)
{
    item* ptr;
    for (int i=0; i<tableSize; i++)
    {
        ptr = HashTable[i];
        while(ptr != NULL)
        {
            if(ptr->name == name)
            {
                cout << "Found item here:\n";
                cout << "-----------------\n";
                cout << ptr->name << endl;
                cout << ptr->drink << endl;
                break;
            }
            ptr = ptr->next;
        }
    }
}

void myhash::RemoveItem(string name)
{
    item* ptr;
    item* delPtr;
    bool found = 0;
    item* pCurr;
    item* pLast;
    
    for(int i=0; i<tableSize; i++)
    {
        //case 0: bucket is empty
        if((HashTable[i]->name == "empty")&&(HashTable[i]->drink =="empty"))
        {
            cout << "bucket " << i <<  " is empty" << endl;
        }            
        //case 1: bucket contains only one item, matched
        else if((HashTable[i]->name == name) && (HashTable[i]->next == NULL))
        {
            HashTable[i]->name = "empty";
            HashTable[i]->drink = "empty";
            cout << "Found item in bucket " << i << endl;
        }
        //case 2: bucket contains multi items, 1st one matched
        else if (HashTable[i]->name == name)
        {
            delPtr = HashTable[i];
            HashTable[i]= HashTable[i]->next;
            delete delPtr;
        }
        //case 3: bucket contains multi items, 1st one not matched
        else
        {
            pCurr = HashTable[i]->next;
            pLast = HashTable[i];
            while(pCurr != NULL)
            {
                //case 3.2: match is found
                if(pCurr->name == name)
                {
                    found = 1;
                    cout << "Found this item in bucket "<< i << endl;
                    delPtr = pCurr;
                    pCurr = pCurr->next;
                    pLast->next = pCurr;
                    delete delPtr;
                    break;
                }  
                pLast = pCurr;
                pCurr = pCurr->next;
            } 
            
            //case 3.1: no match
            if((found == 0)&&( i == tableSize-1))
            {
                cout << "bucket doesn't contain this item\n";
            }           
        }
                
    }

}
