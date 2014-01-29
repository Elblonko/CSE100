#ifndef RST_HPP
#define RST_HPP
#include "BST.hpp"
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

template <typename Data>
class RST : public BST<Data> {

public:


 virtual std::pair<typename BST<Data>::iterator,bool> insert(const Data& item) {
     /* Variable Declarations */
     //pair to hold bst return
     
     //holds randomly generated priority
     int randP;
     //Nodes for current and parent
     BSTNode<Data>* curr;
     BSTNode<Data>* parent;

     //First make call to BST's insert and take its returned iterator
    std::pair<typename BST<Data>::iterator,bool>  bstReturn = BST<Data>::insert(item);

     //Check if the BST iterator is true or false
     if(!bstReturn.second){
         std::cout << "Item was not inserted" << std::endl;
         
         //return value of existing item
         return bstReturn;
     }

     //If the item was inserted into the tree assign the random key
     
     //Seed srand
     srand(time(NULL));
     //generate random variable for insert
     randP = rand();
     //set curr node info to randP
     bstReturn.first.curr->info = randP;


      //Maintain treap property based on info field as priority 
     curr = bstReturn.first.curr;
     parent = bstReturn.first.curr->parent;

     //check if inserted item is root
     if(parent == nullptr)
         return  std::make_pair(typename BST<Data>::iterator(curr), true );


     while ( parent->info < curr->info ){
         //if current node is left child
         if(curr == parent->left){
            curr = rotateWithLeftChild(curr);
            parent = curr->parent;
         }
         //if current node is right child
         else if( curr == parent->right ){
             curr = rotateWithRightChild(curr);
             parent = curr->parent;
         }
     }

     return  std::make_pair(typename BST<Data>::iterator(curr), true );

 //endinsert   
  }


/* Helper Functions to get RST to work properly */
private:

/* Rotation for left child case
 * left child of passed in node becomes the root and is returned
 * make sure to assign left child the appropriate parent node upon
 * return
 */

BSTNode<Data>* rotateWithLeftChild( BSTNode<Data> *rotateRoot ){
    /* Variable Declarations */
    BSTNode<Data> *leftChild = rotateRoot->left;

    /* Swaps the nodes to preform left rotation */
    rotateRoot->left = leftChild->right;
    leftChild->right = rotateRoot;

    /* Update parent pointers */
    rotateRoot->parent = leftChild;
    rotateRoot->left->parent = rotateRoot;

    //return the new root which is leftChild preform parent assigmnet
    return leftChild;
}

/* Rotation for right child case
 * right child of passed in node becomes the root and is returned
 * ensure to update parent pointers
 */

BSTNode<Data>* rotateWithRightChild( BSTNode<Data> *rotateRoot ){
    /* Variable Declarations */
    BSTNode<Data> *rightChild = rotateRoot->right;

    /* Swaps the nodes to preform right rotation */
    rotateRoot->right = rightChild->left;
    rightChild->left = rotateRoot;

    /* Update parent pointers */
    rotateRoot->parent = rightChild;
    rotateRoot->right->parent = rotateRoot;

    //return the new root which is leftChild preform parent assigmnet
    return rightChild;
}

/* Rotation for the left child double rotation case
 * rotates twice about the left child
 * returns node pointing to new root
 */

BSTNode<Data>* doubleRotateWithLeftChild( BSTNode<Data> *rotateRoot ){

    rotateRoot->left = rotateWithRightChild(rotateRoot->left);

    return rotateWithLeftChild(rotateRoot);

}

/* Rotation for the right child double rotation case
 * rotates twice about the right child
 * returns node pointing to new root
 */

BSTNode<Data>* doubleRotateWithRightChild( BSTNode<Data> *rotateRoot ){
    
    rotateRoot->right = rotateWithLeftChild(rotateRoot->right);

    return rotateWithRightChild(rotateRoot);

}


};
#endif // RST_HPP
