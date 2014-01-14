#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>


/*
 * Name: Matthew Schwegler
 * Login: cs100way
 * Student ID: A09293823
 * Assignment PA1
 */


/** This class template defines a node type for the BST container.
 *  Note that all members are public. So, the BST implementation should
 *  take care not to expose any BSTNode objects.
 */
template<typename Data>
class BSTNode {

public:

  /** Member variables. */
  BSTNode<Data>* parent;
  BSTNode<Data>* left;
  BSTNode<Data>* right;
  const Data data;  // the const Data in this node
  int info;  // variable used in advanced algorithms 

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d): data(d) {
    left = right = parent = nullptr;
  }


  /** Return the inorder successor of this BSTNode in a BST,
   *  or nullptr if none.
   *  PRECONDITION: this BSTNode is a node in a BST.
   *  POSTCONDITION:  the BST is unchanged.
   *  RETURNS: the BSTNode that is the inorder successor of this BSTNode,
   *  or nullptr if there is none.
   */ // 
  BSTNode<Data>* successor() const {

    //Node used to iterate through the tree
    BSTNode<Data>* tempNode =(BSTNode<Data>*) this;
    BSTNode<Data>* leftChild;
     
    //if the right child exists find succesor
    if ( tempNode->right != nullptr ){
        tempNode = tempNode->right;
        //traverses left to find the succesor
        while ( tempNode->left != nullptr ){
            tempNode = tempNode->left;
        }
        return tempNode;
      }

    //No right child
    else{
        //compares to find parent such that leftChild
        //is the left decendent
        while(tempNode->parent != nullptr){
            leftChild = tempNode;
            tempNode = tempNode->parent;
            if (tempNode->left == leftChild ){
                break; //could return the parent here
            }
            leftChild = tempNode;
        }
        //returns the succesor
        return tempNode;
    }
    
    //nothing found return NULL
    return nullptr;

  }
};

/** Overload operator<< to insert a BSTNode's fields in an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; i:" << std::setw(10) << n.info;   // its info field
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
