/*
 * File Name: BinarySearchTree.h
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 10
 * Description: Link-based implementation of the ADT binary search tree. 
 * Created by Frank M. Carrano and Tim Henry.
 * Copyright (c) 2013 __Pearson Education__. All rights reserved.
 * Additional methods included for pre- and post- order traversal. 
 */

 
#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "NotFoundException.h"

template<typename ItemType, typename KeyType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;
   
   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                       BinaryNode<ItemType>* newNodePtr);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,
                                  const KeyType& target) const;
                                  
    void inorder(void visit(ItemType), BinaryNode<ItemType>* treePtr) const;
    void preorder(void visit(ItemType), BinaryNode<ItemType>* treePtr) const; 
    void postorder(void visit(ItemType), BinaryNode<ItemType>* treePtr) const;
    
    //removes a given target from the binary search tree
    //returns a pointer to this tree
    //sets success to true if removal was possible
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, KeyType target, bool& success);
    
    //removes item in the node
    //returns a pointer to the node at this position after node is deleted 
    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
    
    //removes the leftmost node in the subtree of the node pointed to by nodePtr
    //sets inorderSuccessor to the value in this node
    //returns a pointer to the revised subtree
    BinaryNode<ItemType>* removeLeftMostNode(BinaryNode<ItemType>* nodePtr, ItemType& inorderSuccessor);
    
    //creates a deep copy of the BST
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   BinarySearchTree(const BinarySearchTree<ItemType, KeyType>& treePtr);//copy constructor
    
   virtual ~BinarySearchTree();
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool add(const ItemType& newData);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   bool contains(const KeyType& aKey) const;
   
   bool remove(KeyType target); //removes given data from this BST
   
   BinaryNode<ItemType>* copyRoot() const;
   
   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void inorderTraverse(void visit(ItemType)) const;
   void preorderTraverse(void visit(ItemType)) const;
   void postorderTraverse(void visit(ItemType)) const;
}; // end BinarySearchTree

#include "BinarySearchTree.cpp"
#endif
