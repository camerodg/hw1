#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val)
{
  //if the list is empty 
  if(head_ == nullptr)
  {
    Item *temp = new Item();
    temp -> val[0] = val;
		//allocate node and assign val to it
    temp -> prev = nullptr;
    temp -> next = nullptr;  
		//set next and prev to null since it's 
		//the only node exisiting
    temp -> first = 0;
    temp -> last = 1;
		//keep count of the first and last for size 
    head_ = temp;
    tail_ = temp; 
    size_++; 
  }
  //list isn't empty and has
	//elements present 
  else {
		//not at the end of the list 
    if(tail_ -> last != ARRSIZE)
    {
      tail_ -> val[tail_->last] = val;
      tail_ -> last++;
      size_++;
    }
    // if the node is filled
		//create a new one
    else 
    {
			//allocate new node, assign the value
			//and assign pointers 
      Item *temp = new Item();
      tail_ -> next = temp;
      temp -> val[0] = val;
      temp -> prev = tail_;
      temp -> next = nullptr;  
      temp -> first = 0;
      temp -> last = 1;
      tail_ = temp;
      size_++;
    }
  }
}
void ULListStr::push_front(const std::string& val) {
  if (head_ == nullptr) {
    // if the list is empty 
    Item* temp = new Item();
    head_ = temp;
    tail_ = temp;
    temp = nullptr;
    head_->val[head_->first] = val;
    ++head_->last;
    ++size_;
  } 
	//head item has a element up front
	//make new node and assign the value there
	//make new node the head 
  else if ((head_->first != 0) && (head_->last > 0)) {
    Item* temp = new Item();
    head_->prev = temp;
    temp->next = head_;
    head_ = temp;
    temp = nullptr;
    head_->val[ARRSIZE - 1] = val;
    head_->last = ARRSIZE;
    head_->first = ARRSIZE - 1;
    ++size_;
  } 
	//List isn't empty and has space to
	//add elements 
  else {
    head_->val[head_->first-1] = val;
    --head_->first;
    ++size_;
  }
}

void ULListStr::pop_back() {
  if (head_ == nullptr) 
	{
    return;
  } 
  // remove the string from the list
  --tail_->last;
  --size_;

  // If the list becomes empty
  if (tail_->first == tail_->last)
	 {
		 //There is a node before the tail_ node
    Item* temp = tail_;
    if (tail_->prev != 0) 
		{
      tail_->prev->next = nullptr;
    }
    //set tail to previous node
		//deletes old node
    tail_ = tail_->prev;
    delete temp;
    temp = nullptr;
  }
  //If nothing is present after the pop_back
	//is called, reassign pointer
  if (size_ == 0) 
	{
    head_ = nullptr;
  } 
}
void ULListStr::pop_front()
{
	if(head_ == NULL)
	{
		return;
	}
//The list isn't empty 
	++head_->first;
  --size_;
	//if one item is in the list
 if(head_ -> first == head_ -> last)
  {
    //Create pointer for the next node 
    Item *nextNode = head_ -> next; 
		//Temp node for the soon deleted head 
    Item *temp = head_;
    //gets rid of the curr pointer 
    if(nextNode != nullptr){
      temp -> next -> prev = nullptr; 
      temp -> next = nullptr; 
      temp = head_ -> next; 
      delete head_;
      head_ = nextNode;
    }
    else 
    {
      temp -> next = nullptr; 
      delete head_;
      tail_ = nextNode;
      head_ = nextNode;
    }
	}
}

std::string const & ULListStr::back() const 
{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

string* ULListStr::getValAtLoc(size_t loc) const
{
  // Check if loc is in the list
  if (loc >= size_)
	{
    return NULL;
  }
  else 
	{
    // Create a variable that points to the list
		//Another variable that keeps track of the iterator
		//across all of the lists 
    int iterator = 0;
    Item* temp = head_;

    while (loc >= ((temp->last - temp->first) + iterator)) 
		{
			//updates the iterator with the 
			//difference between last and first of 
			//each node 
      iterator += (temp->last - temp->first);
			//goes to the next node
      temp = temp->next; 
    }
    return &(temp->val[temp->first+(loc-iterator)]);
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
