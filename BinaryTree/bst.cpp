/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include "bst.h"

using namespace std;

#define INVALID_KEY -1000
BST::BST()
{
    root = NULL;
}

BST::~BST()
{

}

BST::node* BST::CreateLeaf(int key)
{
    node * n = new node;
    n->key = key;
    n->right = NULL;
    n->left = NULL;
    return n;     
}

void BST::AddLeaf(int key)
{
    AddLeafPrivate(key, root);
}

void BST::AddLeafPrivate(int key, node* ptr)
{
    if(root == NULL)
    {
        root = CreateLeaf(key);
    }
    else if(key < ptr->key)
    {
        if(ptr->left != NULL)
        {
            AddLeafPrivate(key, ptr->left);
        }
        else
        {
            ptr->left = CreateLeaf(key);
        }
    }
    else if(key > ptr->key)
    {
        if(ptr->right != NULL)
        {
            AddLeafPrivate(key, ptr->right);
        }
        else
        {
            ptr->right = CreateLeaf(key); 
        }
    }           
    else
    {
        cout << "key is already existed in the binary tree" << endl;
    }
   
}

void BST::PrintInOrder()
{
    PrintInOrderPrivate(root);
}

void BST::PrintInOrderPrivate(node* ptr)
{
    if(root == NULL)
    {
        cout << "The binary tree is empty!" << endl;
    }
    else
    {
        //cout << "root key is:" << root->key<<endl;
        if(ptr->left != NULL)
        {
            PrintInOrderPrivate(ptr->left);
        }
        cout << ptr->key <<",";
        if(ptr->right != NULL)
        {
            PrintInOrderPrivate(ptr->right);
        }    
    }
}
BST::node* BST::ReturnNodePrivate(int key, node* ptr)
{
    if(root != NULL)
    {
        if(key< ptr->key)
        {
            ReturnNodePrivate(key, ptr->left);
        }
        else if(key == ptr->key)
        {
            cout << "\nfound matched node for key:"<< key <<endl;
            return ptr;
        }
        else
        {
            ReturnNodePrivate(key, ptr->right);
        }
    }
    else
    {
        cout << "Binary tree is empty!"<<endl;
        return NULL;
    }
}
int BST::ReturnRootKey()
{
    if(root!=NULL)
    {
        return root->key;
    }
    else
    {
        return INVALID_KEY;
    }
}

void BST::PrintChildren(int key)
{
    node* ptr = ReturnNodePrivate(key, root);
    if( ptr != NULL)
    {
        (ptr->left == NULL)?
        cout << "left child is empty\n":
        cout << "left:" << ptr->left->key <<endl;
        
        (ptr->right == NULL)?
        cout << "right child is empty\n" :
        cout << "right:" << ptr->right->key <<endl;
    }
    else
    {
        cout << "Key " << key << "is not in the tree" <<endl;
    }
}

int BST::FindSmallest()
{
    int smallest;
    smallest = FindSmallest(root);
    return smallest;
}

int BST::FindSmallest(node* ptr)
{
    if(ptr == NULL)
    {
       cout << "It is an empty tree\n" ;
       return INVALID_KEY;
    }
    else
    {
        if(ptr->left != NULL)
        {
            return (FindSmallest(ptr->left));
        }  
        else
        {
            return ptr->key;
        }
    }
}

void BST::RemoveNode(int key)
{
    RemoveNode(key, root);
}

void BST::RemoveNode(int key, node* ptr)
{
    node * currPtr;
    currPtr = ReturnNode(key, ptr);
    if(currPtr == NULL)
    {
        cout <<"key is not existed in the tree\n"
    }
    
}