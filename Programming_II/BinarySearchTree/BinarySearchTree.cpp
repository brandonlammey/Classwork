/*
 * File Name: BinarySearchTree.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 10
 * Description: Link-based implementation of the ADT binary search tree. 
 * Created by Frank M. Carrano and Tim Henry.
 * Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */


#include <iostream>




// PRIVATE HELPER METHODS

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
    if(subTreePtr != nullptr)
    {
        destroyTree(subTreePtr->getLeftChildPtr());
        destroyTree(subTreePtr->getRightChildPtr());
        delete(subTreePtr);
    }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::insertInorder(BinaryNode<ItemType>* subTreePtr,
                                                                BinaryNode<ItemType>* newNodePtr)
{
    BinaryNode<ItemType>* tempPtr = nullptr;
    
    //insertInorder    
    if(newNodePtr->getItem() < subTreePtr->getItem())
    {
        if(subTreePtr->getLeftChildPtr() == nullptr)
        {
            subTreePtr->setLeftChildPtr(newNodePtr);
        }
        else
        {
            insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
        }
    } 
    else
    {
        if(subTreePtr->getRightChildPtr() == nullptr)
        {
            subTreePtr->setRightChildPtr(newNodePtr);
        }  
        else
        {
            insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
        }  
    }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(
				BinaryNode<ItemType>* subTreePtr, const KeyType& target) const
{
    //find node 
    if(subTreePtr==nullptr) //value not found
    {
        return(nullptr);
    }
    else if(subTreePtr->getItem() == target) //value found
    {
        return(subTreePtr);
    }
    else if(subTreePtr->getItem() > target)//search left sub tree
    {
        return(findNode(subTreePtr->getLeftChildPtr(), target));
    }
    else
    {
        return(findNode(subTreePtr->getRightChildPtr(), target));
    }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorder(void visit(ItemType),BinaryNode<ItemType>* treePtr) const
{

    if(treePtr->getLeftChildPtr() != nullptr)
    {
        inorder(visit, treePtr->getLeftChildPtr());
    }
    visit(treePtr->getItem());
        
    if(treePtr->getRightChildPtr() != nullptr)
    {
        inorder(visit, treePtr->getRightChildPtr());
    }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preorder(void visit(ItemType), BinaryNode<ItemType>* treePtr) const 
{
  visit(treePtr->getItem());
  if(treePtr->getLeftChildPtr() != nullptr)
  {
      preorder(visit, treePtr->getLeftChildPtr());
  }
  if(treePtr->getRightChildPtr() != nullptr)
  {
      preorder(visit, treePtr->getRightChildPtr());
  }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postorder(void visit(ItemType), BinaryNode<ItemType>* treePtr) const 
{
    if(treePtr->getLeftChildPtr() != nullptr)
    {
        postorder(visit, treePtr->getLeftChildPtr());
    }
    if(treePtr->getRightChildPtr() != nullptr)
    {
        postorder(visit, treePtr->getRightChildPtr());
    }
    visit(treePtr->getItem());
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeValue(BinaryNode<ItemType>* subTreePtr, KeyType target, bool& success)
{
    BinaryNode<ItemType>* tempPtr;
    
    if(subTreePtr == nullptr)
    {
        success = false;
        return(nullptr);
    }
    else if(subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return(subTreePtr);
    }
    else if(subTreePtr->getItem() > target)
    {
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
        return(subTreePtr);
    }
    else
    {
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
        return(subTreePtr);
    }
} 

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeNode(BinaryNode<ItemType>* nodePtr)
{
    if(nodePtr->getLeftChildPtr()==nullptr && nodePtr->getRightChildPtr()==nullptr)//node has no children
    {
        delete(nodePtr);
        nodePtr = nullptr;
        return(nodePtr);
    }
    else if(nodePtr->getLeftChildPtr()==nullptr || nodePtr->getRightChildPtr()==nullptr)//node has one child
    {
        BinaryNode<ItemType>* nodeToConnectPtr;
        if(nodePtr->getRightChildPtr()==nullptr)//node has only a left child
        {
            nodeToConnectPtr = nodePtr->getLeftChildPtr();
        }
        else
        {
            nodeToConnectPtr = nodePtr->getRightChildPtr();
        }
        delete(nodePtr);
        nodePtr = nullptr;
        return(nodeToConnectPtr);
    }
    else//node has two children
    {
        BinaryNode<ItemType>* tempPtr;
        ItemType newNodeValue("", "");
        tempPtr = removeLeftMostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue); 
        return(nodePtr);
    }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::removeLeftMostNode(BinaryNode<ItemType>* nodePtr, ItemType& inorderSuccessor)
{
    if(nodePtr->getLeftChildPtr()==nullptr)
    {
        inorderSuccessor = nodePtr->getItem();
        return(removeNode(nodePtr));
    }
    else
    {
        return(removeLeftMostNode(nodePtr->getLeftChildPtr(), inorderSuccessor));
    }
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyTree(const BinaryNode<ItemType>* treePtr) const
{
    BinaryNode<ItemType>* newTreePtr = nullptr;
    // Copy tree nodes during a preorder traversal
    if (treePtr != nullptr)
    {
        // Copy node
        newTreePtr = new BinaryNode<ItemType>(treePtr->getItem(),nullptr, nullptr);
        newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
        newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
    } // end if
    // Else tree is empty (newTreePtr is nullptr)
    return newTreePtr;
}

//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree() : rootPtr(nullptr)
{
}

//copy constructor
template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree(const BinarySearchTree<ItemType, KeyType>& treePtr)
{
    rootPtr = treePtr.copyRoot();
}

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::add(const ItemType& newData)
{
	BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newData);
    if(rootPtr == nullptr) 
    {
        rootPtr = newNodePtr;
    } 
    else 
    {
        this->insertInorder(rootPtr, newNodePtr);
    }
    return (true);
}

template<typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
    BinaryNode<ItemType>* entryPtr = findNode(rootPtr, aKey);
    if(entryPtr == nullptr)
    {
        //throw exception
        throw NotFoundException("Value not found.");
    }
    else
    {
        return (this->findNode(rootPtr, aKey)->getItem());
    }
}

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::contains(const KeyType& aKey) const
{
    BinaryNode<ItemType>* entryPtr = this->findNode(rootPtr, aKey);
    if(entryPtr == nullptr)
    {
        return(false);
    }
    else
    {
        return(true);
    }
}

template<typename ItemType, typename KeyType>
 bool BinarySearchTree<ItemType, KeyType>::remove(KeyType target)
 {
     bool success = false;
     rootPtr = removeValue(rootPtr, target, success);
     return(success);
 }
 
template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::copyRoot() const 
{
  return copyTree(rootPtr);
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverse(void visit(ItemType)) const
{
    if(rootPtr != nullptr)
    {
        this->inorder(visit, rootPtr);        
    }

}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::preorderTraverse(void visit(ItemType)) const
{
  if(rootPtr != nullptr)
  {
      this->preorder(visit, rootPtr);
  }
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::postorderTraverse(void visit(ItemType)) const
{
  if(rootPtr != nullptr)
  {
      this->postorder(visit, rootPtr);
  }
}