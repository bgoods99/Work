// Brian Goodson

#ifndef LBAG_H
#define LBAG_H

#include <cstdlib>
#include <ostream>
#include "node.h"

using std::size_t;

template <typename T>
class LBag {
public:
  // 0-arg constructor, copy constructor, and destructor
  LBag() : head(nullptr), tail(nullptr) {}
  LBag(const LBag<T> & b);
  ~LBag();
  // accessors
  size_t size() const;
  size_t count(const T & target) const;
  bool isSorted();
  // mutators
  void insert(const T & target); //
  bool erase_one(const T & target);
  size_t erase(const T & target);
  // overloaded assignment operator
  void operator =(const LBag<T> & b);
  // insertion operator overloaded as friend
  template<typename T2>
  friend std::ostream & operator <<(std::ostream & out, const LBag<T2> & b);
private:
  node<T> *head, *tail;
};

// pre: out is an ostream and b is an LBag
// post: the list associated with b has been inserted into out
// recall friends can access private member vars and << is overloaded for node *
template<typename T>
std::ostream& operator <<(std::ostream& out, const LBag<T>& b) {
  out << b.head;
  return out;
}

// pre:
// post: all dynamic memory associated with this bag is released
template<typename T>
LBag<T>::~LBag() {
  while (head != nullptr) list_remove_head(head,tail);
  // use cout below to have test program report when destructors are called
  //std::cout << "destroyed object at " << this << std::endl;
}

// pre: b is an LBag and this bag doesn't exist
// post: this bag's head and tail point to copies of nodes in same order as b
template<typename T>
LBag<T>::LBag(const LBag<T> & b) {
  head = tail = nullptr;
  for (node<T> * p = b.head; p != nullptr; p = p->link()) {// iterate through b
    // insert the element of b into the tail of this object
    list_insert_tail(head,tail,p->data());
  }

}

// pre: this and b are LBags
// post: this bag's original data has been deleted and it is now a copy of b
template<typename T>
void LBag<T>::operator =(const LBag<T> &b) {
  this->~LBag<T>(); // first delete this bag's current nodes
  for (node<T> * p = b.head; p != nullptr; p = p->link()) {// iterate through b
    list_insert_tail(head,tail,p->data()); // tail insert maintains order
  }
}

// pre:
// post: the number of elements in the bag is returned
template<typename T>
size_t LBag<T>::size() const {
  return list_size(head);
}

// pre:
// post: the number of elements with the target data is returned
template<typename T>
size_t LBag<T>::count(const T & target) const {
  size_t count=0;
  for (const node<T> * p=head; p!=nullptr; p=p->link()) {
    if (p->data() == target) count++;
  }
  return count;
}

// pre:
// post: the target element has been added to (the head of) the bag
template<typename T>
void LBag<T>::insert(const T & target) {
  list_insert_head(head,tail,target);
}

// pre:
// post: if target is in the bag, the first copy is removed and true is returned
//       else false is returned
template<typename T>
bool LBag<T>::erase_one(const T & target) {
  node<T> * prev = nullptr;
  for (node<T> * p = head; p != nullptr; p = p->link()) {
    if (p->data() == target) { // target found
      if (prev==nullptr) { // special case: about to delete head
        head = head->link();
      } else { // general case: link prev to one past p before deleting p
        prev->set_link(p->link());
      }
      if (p == tail) { // special case: about to delete tail, possibly also head
        tail = prev;
      }
      // in any target found case, end by deleting p and returning true
      delete p;
      return true;
    }
    prev = p; // if target not found, update previous pointer so it follows p
  }
  return false; // finished scan without finding target
}

// pre:
// post: all copies of target have been removed and count is returned
template<typename T>
size_t LBag<T>::erase(const T & target) {
  // TODO: replace this with a linear time implementation (Q2)
  size_t count = 0;
  node<T> * last = NULL;
  for (node<T> * p = head; p != nullptr; p = p->link()) {
    if(p->data() == target){
      if(last==NULL){
        head = head->link();
      }
      else{
        last->set_link(p->link());
      }
      if(p == tail){
        tail = last;
      }

      node<T> * temp = p;
      p = p->link();
      delete temp;
      count++;
    }
    else{
      last = p;
      p = p->link();
    }

  }
  return count;



  /*size_t count = 0;
  while (erase_one(target)) count++;
  return count;
  */
}

//sort boolean function
template<typename T>
bool LBag<T>::isSorted(){
  while(head!=tail){
    node<T> * temp = head->link();
    if(head->data() >= temp->data()){
      return false;
    }
    delete head;
    head = temp;
  }
  return true;
}



/*  if(head == nullptr){
    return true;
  }
  for (node<T> * p = head; p != nullptr; p = p->link()){
    //node<T> * s = p->link();
    if(p->data() <= p->link()->data()){
      return false;
    }
  }
  return true;
}
*/

#endif
