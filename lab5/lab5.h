// -*- bst.h -*-
#ifndef BST_H
#define BST_H

#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>

using namespace std;

#define nil 0
// #define Value int // restore for testing.
template < typename Value >
class BST 
{
    class Node 
    { // binary tree node
        public:
        
            Node* left;
            Node* right;
            Value value;
            Node( const Value v = Value() )
                : value(v), left(nil), right(nil)
            {}
            Value& content() { return value; }
            bool isInternal() { return left != nil && right != nil; }
            bool isExternal() { return left != nil || right != nil; }
            bool isLeaf() { return left == nil && right == nil; }
            int height() {
                // returns the height of the subtree rooted at this node
                // FILL IN
                if (right == nil || left == nil)
                {
                    return 0;
                }
                return max(right->height(), left->height()) +1;
            }
            int size() {
                // returns the size of the subtree rooted at this node,
                // FILL IN
                if (this == nil)
                {
                    return 0;
                }
                
                return this->right->size() + this->left->size() +1;
            }
    }; // Node
    
    
    // const Node* nil; // later nil will point to a sentinel node.
    Node* root;
    int count;
    vector<Node *> cover;
    bool selected;
    
    public:
    
        //BST() : count(0), root(nil) {}
        
        
        int size() {
            // size of the overall tree.
            // FILL IN
            if (root == nil)
            {
                return 1;
            }
            
            return root->right->size() + root->left->size() + 1;
        }
        
        bool empty() { return size() == 0; }
        
        void print_node( const Node* n ) {
            // Print the node’s value
            cout << n->value << endl;
        }
        
        bool search ( Value x ) {
            // search for a Value in the BST and return true iff it was found.
            
            Node* temp = root;
            
            while (temp!= NULL)
            {
                if (temp->value == x)
                {
                    return true;
                }
                else if (x < temp->value)
                {
                    temp = temp->left;
                }
                else 
                {
                    temp = temp->right;
                }
            }
            
            return false;
        }
        
        
        void preorder()const {
            // Traverse and print the tree one Value per line in preorder.
            // FILL IN
            preorder(root);
        }
        
        void preorder(Node* subtree) const
        {
            if (subtree == nil)
            {
                return;
            }
            
            cout << subtree->value << endl;
            preorder(subtree->left);
            preorder(subtree->right);
        }
        
        void postorder()const {
            // Traverse and print the tree one Value per line in postorder.
            // FILL IN
            postorder(root);
        }
        
        void postorder(Node* subtree) const
        {
            if (subtree == nil)
            {
                return;
            }
            postorder(subtree->left);
            postorder(subtree->right);
            cout << subtree->value << endl;
        }
        
        void inorder()const {
            // Traverse and print the tree one Value per line in inorder.
            // FILL IN
            inorder(root);
        }
        
        void inorder(Node* subtree) const
        {
            if (subtree == nil)
            {
                return;
            }
            inorder(subtree->left);
            cout << subtree->value << endl;
            inorder(subtree->right);
        }
        
        Value& operator[] (int n) {
            // returns reference to the value field of the n-th Node.
            // FILL IN
            return finder(n, root)->value;
        }
        
        Node* finder (int &n, Node* subtree)
        {
            if (subtree == nil)
            {
                return nil;
            }
            finder(n, subtree->left);
            
            if (n==0)
            {
                return subtree;
            }
            
            n--;
            
            return finder(n, subtree->right);
        }
        
        BST() : count(0), root(nil) {}

        
        void insert( Value X ) { root = insert( X, root ); }
        
        Node* insert( Value X, Node* T ) 
        {
            // The normal binary-tree insertion procedure ...
            if ( T == nil ) 
            {
                T = new Node( X ); // the only place that T gets updated.
            } 
            else if ( X < T->value ) 
            {
                T->left = insert( X, T->left );
            } 
            else if ( X > T->value ) {
                T->right = insert( X, T->right );
            } 
            else 
            {
                T->value = X;
            }
                // later, rebalancing code will be installed here
            return T;
        }
        
        void remove( Value X ) { root = remove( X, root ); }
        
        Node* remove( Value X, Node*& T ) 
        {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) 
            {
                if ( X > T->value ) 
                {
                T->right = remove( X, T->right );
                } 
            else if ( X < T->value ) 
            {
                T->left = remove( X, T->left );
            } 
            else 
            { // X == T->value
                if ( T->right != nil ) 
                {
                    Node* x = T->right;
                    while ( x->left != nil ) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                } 
                else if ( T->left != nil ) 
                {
                    Node* x = T->left;
                    while ( x->right != nil ) x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove( T->value, T->left );
                } 
                else 
                { // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
            }
                // later, rebalancing code will be installed here
            return T;
        }
        
        void okay( ) { okay( root ); }
        
        void okay( Node* T ) 
        {
            // diagnostic code can be installed here
            return;
        }
        
        void minCover(Node * n)
        {
              if (n == nil)
              {
                    return;
              }
              minCover(n->left);
              if (n->size() >= 2)
              {
                    cover.push_back(n);
                    // n->selected = true;
              }
              minCover(n->right);
        }
        
        void minCover()
        {
              minCover(root->left);
              minCover(root->right);
        }
        
        void displayMinCover()
        {
              int count =0;
              for (count =0; count < cover.size(); count++)
              {
                    cout << cover.at(count)->value << ' ';
              }
              cout << endl << count << endl;
        }
        
        void findSumPath(Node* n, int sum, int buffer[])
        {
              if (n == nil)
              {
                    return;
              }
              
              
        }
        
        void vertSum(Node* node, int hd, std::map<int, int>& m) 
        {
              m[hd] += node->value;
              
              if (node-> left != nil)
              {
                    hd = hd-1;
                    vertSum(node->left, hd, m);
                    hd = hd+1;
              }
              if (node->right != nil)
              {
                    hd = hd+1;
                    vertSum(node->right, hd, m);
                    hd = hd-1;
              }
              return;
        }
        
        void displayVertSum (map<int, int>& m)
        {
              map<int,int>::iterator itr;
              for (itr = m.begin(); itr != m.end(); itr++)
              {
                    cout << m[itr->first] << ' ';
              }
              cout << endl;
        }
        
        void vertSum()
        {
              if (root == nil)
              {
                    cout << '0' << endl;
                    return;
              }
              map<int,int> displayMap;
              vertSum(root, 0, displayMap);
              displayVertSum(displayMap);
        }
         
}; // BST

#endif
    
    
