

#include "BinaryNode.h"
#include "queue.h"
#include <iostream>
#include <iomanip>
using namespace std;

template<class ItemType>
class BinaryTree
{
protected:
    BinaryNode<ItemType>* rootPtr;		// ptr to root node
    int count;							// number of nodes in tree
    
public:
    // "admin" functions
    BinaryTree() {rootPtr = 0; count = 0;}
    BinaryTree(const BinaryTree<ItemType> & tree){ }
    virtual ~BinaryTree() { destroyTree(rootPtr); }
    BinaryTree & operator = (const BinaryTree & sourceTree);
    
    // common functions for all binary trees
    bool isEmpty() const	{return count == 0;}
    int size() const	    {return count;}
    void clear()			{destroyTree(rootPtr); rootPtr = 0; count = 0;}
    void preOrder(void visit(ItemType &)) const {_preorder(visit, rootPtr);}
    void inOrder(void visit(ItemType &)) const  {_inorder(visit, rootPtr);}
    void postOrder(void visit(ItemType &)) const{_postorder(visit, rootPtr);}
    int getHeight() const{return getHeightHelper(rootPtr);}
    
    // add function for the binaray tree.
    // print_ indented. prints the tree horizontally
    // range. prints given range in the tree
    // tree_breath prints level by level, from the tree
    void print_indented(void visit(ItemType &, int&)) const {_print_indented(visit, rootPtr,0);}
    void range(void visit(ItemType &), const ItemType one, const ItemType two) const  {_range(visit, rootPtr, one, two);}
    void tree_breadth(void visit(ItemType &)) const { _TreeBreadth(visit,rootPtr); };
    
    
    
    
    
    
    // abstract functions to be implemented by derived class
    virtual bool insert(const ItemType & newData) = 0;
    virtual bool remove(const ItemType & data) = 0;
    virtual bool getEntry(const ItemType & anEntry, ItemType & returnedItem) const = 0;
    
    
private:
    // delete all nodes from the tree
    void destroyTree(BinaryNode<ItemType>* nodePtr);
    
    // copy from the tree rooted at nodePtr and returns a pointer to the copy
    BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* nodePtr);
    
    // internal traverse
    void _preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    void _postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const;
    int getHeightHelper(BinaryNode<ItemType>* subTreePtr) const;
    
    // internal function to help complete job.
    void _print_indented(void visit(ItemType &,int&), BinaryNode<ItemType>* nodePtr,int num) const;
    void _range(void visit(ItemType &), BinaryNode<ItemType>* nodePtr, const ItemType one, const ItemType two) const;
    void _TreeBreadth(void visit(ItemType &),BinaryNode<ItemType>* nodePtr)const;
    
    
};

//////////////////////////////////////////////////////////////////////////

template<class ItemType>
BinaryNode<ItemType>* BinaryTree<ItemType>::copyTree(const BinaryNode<ItemType>* nodePtr)
{
    BinaryNode<ItemType>* newNodePtr = 0;
    
    if(nodePtr != 0)
    {
        
        newNodePtr = new BinaryNode<ItemType> (nodePtr->getItem());
        newNodePtr->setLeftPtr(copyTree(nodePtr->getLeftPtr()));
        newNodePtr->setRightPtr(copyTree(nodePtr->getRightPtr()));
    }
    
    return newNodePtr;
}

template<class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType>* nodePtr)
{
    if (nodePtr != nullptr)
    {
        destroyTree(nodePtr->getLeftPtr());
        destroyTree(nodePtr->getRightPtr());
        delete nodePtr;
    }
}

template<class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        
        ItemType item = nodePtr->getItem();
        visit(item);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
        
    }
}

template<class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        
        _inorder(visit, nodePtr->getLeftPtr());
        ItemType item = nodePtr->getItem();
        visit(item);
        _inorder(visit, nodePtr->getRightPtr());
        
    }
    
    
    
}

template<class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType>* nodePtr) const
{
    if (nodePtr != 0)
    {
        
        _postorder(visit, nodePtr->getLeftPtr());
        _postorder(visit, nodePtr->getRightPtr());
        ItemType item = nodePtr->getItem();
        visit(item);
    }
    
}



template<class ItemType>
BinaryTree<ItemType> & BinaryTree<ItemType>::operator=(const BinaryTree<ItemType> & sourceTree)
{
    
    rootPtr = copyTree(sourceTree.rootPtr);
    
    return rootPtr;
}



template<class ItemType>
void  BinaryTree<ItemType>:: _print_indented(void visit(ItemType &, int&), BinaryNode<ItemType>* nodePtr, int num) const
{
    if (nodePtr !=0)
    {
        
        num++;
        _print_indented(visit, nodePtr->getRightPtr(),num);
        
        
        ItemType item = nodePtr->getItem();
        visit(item,num);
        
        _print_indented(visit, nodePtr->getLeftPtr(),num);
        
        
        
    }
}


template<class ItemType>
void BinaryTree<ItemType>::_range(void visit(ItemType &), BinaryNode<ItemType>* nodePtr,const ItemType one, const ItemType two) const
{
    
    if (nodePtr != 0)
    {
        
        _range(visit, nodePtr->getLeftPtr(), one, two);
        if(nodePtr->getItem() >= one && nodePtr->getItem() <= two)
        {
            ItemType item = nodePtr->getItem();
            visit(item);
        }
        _range(visit, nodePtr->getRightPtr(), one, two);
    }
    
}

template<class ItemType>
void BinaryTree<ItemType>::_TreeBreadth(void visit(ItemType &),BinaryNode<ItemType>* nodePtr)const
{
    
    if (nodePtr == 0)
    {
        return;
    }
    BinaryNode<ItemType>* rover = nodePtr;
    
    Queue<BinaryNode<ItemType>* > q;
    
    q.enqueue(rover);
    
    while(!q.isEmpty())
    {
        q.queueFront(rover);
        
        ItemType item = rover->getItem();
        visit(item);
        
        
        if ( rover->getLeftPtr() != NULL )
            q.enqueue(rover->getLeftPtr());
        
        
        if ( rover->getRightPtr() != NULL )
            q.enqueue(rover->getRightPtr());
        
        
        
        q.dequeue(rover);
    }
    
    
}


template<class ItemType>
int BinaryTree<ItemType>::getHeightHelper(BinaryNode<ItemType>* subTreePtr) const
{
    if (subTreePtr == nullptr) return 0;
    else
        return 1 + max(getHeightHelper(subTreePtr->getLeftPtr()),
                       getHeightHelper(subTreePtr->getRightPtr()));
} 
