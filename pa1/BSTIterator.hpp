#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

/*
 * Name: Matthew Schwegler
 * Login: cs100way
 * Student ID: A09293823
 * Assignment PA1
 */

// declare BST here, so friend declaration below will work.
template<typename X> class BST;

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr; // pointer to this BSTIterator's current BSTNode

  /** Constructor.  Use the argument to initialize a given BSTNode
   *  in this BSTIterator.
   *  Note: this constructor is private; but friend classes can access.
   */ // 
  BSTIterator(BSTNode<Data>* curr) {
   this->curr = curr; 
  }


public:
  // make BST a friend class, so BST can create a BSTIterator when needed.
  friend class BST<Data>;
  // make BSTNode a friend class, so BSTNode can access curr member variable.
  friend class BSTNode<Data>;


  /** Dereference operator.
   *  Return a copy of the Data item in the current BSTNode.
   */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator.
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a reference to the updated BSTIterator.
   */
  BSTIterator<Data>& operator++() {

    //Updates the iterator using succesor Node method
    curr = curr->successor();
    return *this;

  }

  /** Post-increment operator. 
   *  Update this BSTIterator to point to the inorder successor of the current
   *  BSTNode, and return a copy of the old, non-updated BSTIterator.
   */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ // 
  bool operator==(BSTIterator<Data> const & other) const {

      //Checks if other.curr is not null
      if( other.curr ){
         //Check for data field equality
         if (curr->data == other.curr->data ){
            return true;

         //if not null and not equal return false
         }else{
            return false;
         }

      //else if both null return true for equality 
      }else{
          if(curr)
              return false;
          else
              return true;
      }
  }

  /** Inequality test operator. */ // 
  bool operator!=(BSTIterator<Data> const & other) const {

      //Check if other.curr is not null
      if ( other.curr ){
        //if not null check fo inequality and return true
        if (curr->data != other.curr->data ){
              return true;
         }else{
             return false;
         }

        //if both null return false for inequality
       }else{
          if (curr)
              return true;
          else
              return false;
      }
  }

};

#endif //BSTITERATOR_HPP
