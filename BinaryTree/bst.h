/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bst.h
 * Author: jiejuan.liu
 *
 * Created on 27 August, 2018, 6:01 PM
 */
#ifndef BST_H
#define BST_H

class BST
{
private:
    struct node
    {
        int key;
        node* left;
        node* right;
    };
    node* root;
    void AddLeafPrivate(int key, node* ptr);
    void PrintInOrderPrivate(node* ptr);
    node* ReturnNodePrivate(int key, node* ptr);
    int FindSmallest(node* ptr);
    void RemoveNode(int key, node* ptr);
public:
    BST();
    ~BST();
    node* CreateLeaf(int key);
    void AddLeaf(int key);
    void PrintInOrder();
    node* ReturnNode(int key);
    int ReturnRootKey();
    void PrintChildren(int key);
    int FindSmallest();
    void RemoveNode(int key);
};       

#endif /* BST_H */

