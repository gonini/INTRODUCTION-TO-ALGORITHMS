//
//  main.cpp
//  BST
//
//  Created by GangGongUi on 2016. 8. 11..
//  Copyright © 2016년 GangGongUi. All rights reserved.
//

#include <iostream>

using namespace std;

class Tree
{
    
    class Node
    {
    public:
        Node * left, *right, *p;
        int key;
        Node(int k) : key(k)
        {
            this->left = this->right = this->p = NULL;
        }
    };
    
private:
    Node * get_minimum(Node * node)
    {
        Node * t = node;
        while(node->left != NULL)
        {
            t = node;
            node = node->left;
        }
        
        return t;
    };
    
    Node * search(int key)
    {
        Node * y = root;
        Node * t = NULL;
        
        while( y != NULL )
        {
            t = y;
            if(y->key == key) break;
            else if(y->key > key)
                y = y->left;
            else y = y->right;
        }
        
        if(t->key != key) return NULL;
        return t;
    };
    
    void transplant(Node * u, Node * v)
    {
        if(u->p == NULL) root = v;
        else if(u->p->left == u) u->p->left = v;
        else u->p->right = v;
        
        if(v != NULL)
        {
            v->p = u->p;
        }
    }
    
    
public:
    Node * root = NULL;
    
    Tree() {};
    
    void insert(int key)
    {
        Node * y = root;
        Node * t = root;
        while(y != NULL)
        {
            t = y;
            if(y->key >= key) y = y->left;
            else y = y->right;
        }
        
        y = new Node(key);
        y->p = t;
        if(t == NULL) root = y;
        else if(t->key >= key) t->left = y;
        else t->right = y;
    };
    
    void remove(int key)
    {
        Node * r = search(key);
        
        if(r == NULL) return;
        else if(r->left == NULL) transplant(r, r->right);
        else if(r->right == NULL) transplant(r, r->left);
        else
        {
            Node * minimum = get_minimum(r->right);
            
            if(r->right != minimum)
            {
                transplant(minimum, minimum->right);
                minimum->right = r->right;
                r->right->p = minimum;
            }
            
            transplant(r, minimum);
            minimum->left = r->left;
            minimum->left->p = minimum;
        }
    }
    
    void inOrder(Node * node)
    {
        if(node != NULL)
        {
            inOrder(node->left);
            std::cout << node->key << " ";
            inOrder(node->right);
        }
    }
};


int main()
{

    Tree tree;
    
    tree.insert(4);
    tree.insert(2);
    tree.insert(10);
    tree.insert(3);
    tree.insert(8);
    tree.insert(12);
    
    tree.inOrder(tree.root);
    
    tree.remove(10);
    
    cout << endl;
    
    tree.inOrder(tree.root);
    
    return 0;
}


